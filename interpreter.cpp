#include "interpreter.h"
#include "command.h"

using namespace JsonPath;

using json = nlohmann::ordered_json;

Interpreter::Interpreter()
    : m_commands(), m_scanner(*this), m_parser(m_scanner, *this),
      m_location(0) {}

Interpreter::Interpreter(json inp)
    : m_commands(), m_scanner(*this), m_parser(m_scanner, *this), m_location(0),
      m_json(inp) {}

Interpreter::Interpreter(json inp, istringstream &jsonpath_inp)
    : m_commands(), m_scanner(*this), m_parser(m_scanner, *this), m_location(0),
      m_json(inp) {
  _jsonpath = std::move(jsonpath_inp);
}

int Interpreter::parse() {
  m_location = 0;
  return m_parser.parse();
}

void Interpreter::clear() {
  m_location = 0;
  m_commands.clear();
}

std::string Interpreter::str() const {
  std::stringstream s;
  s << "Interpreter: " << m_commands.size()
    << " commands received from command line." << endl;
  for (int i = 0; i < m_commands.size(); i++) {
    s << " * " << m_commands[i].str() << endl;
  }
  return s.str();
}

void Interpreter::switchInputStream(istringstream &is) {
  m_scanner.switch_streams(&is, NULL);
  m_commands.clear();
}

void Interpreter::addCommand(const Command &cmd) { m_commands.push_back(cmd); }

void Interpreter::increaseLocation(unsigned int loc) { m_location += loc; }

unsigned int Interpreter::location() const { return m_location; }

json Interpreter::getOutput() { return m_json; }

void Interpreter::show() { cout << m_json << endl; }

/*
...
Main parse function...
...
*/

void Interpreter::evaluate() {

  /*
      0-9     : Regular path expressions
      10-19   : Selections
      20-29   : Filters
      30-39   : Script engine filters
  */
  std::string rootPointer = "";
  std::string pointer = "";
  bool preFilter = true; // first part of expression

  for (auto &a : m_commands) {
    switch (a.id()) {

    case 0: { // Regular dotnotation Path
      if (preFilter == true || m_json.is_object()) {
        std::string fullPath = "";
        for (auto b : a.getArgs())
          fullPath += "/" + b;

        if (fullPath == "")
          break;

        if (m_json.is_object() || m_json.is_array()) {
          m_json = m_json[json::json_pointer(fullPath)];
        } else {
          error = true;
          return;
        }

        if (m_json.empty()) {
          error = true;
          return;
        }
        preFilter = false;
      } else {
        json res, tmp;
        string fullPath = "";

        for (auto &b : a.getArgs())
          fullPath += "/" + b;

        if (fullPath == "")
          break; // no arguments

        for (auto &obj : m_json)
          if (obj.is_array() && m_json.size() == 1)
            m_json = m_json[0];

        if (m_json.is_object() || m_json.is_array()) {
          for (auto &obj : m_json) {
            tmp = obj[json::json_pointer(fullPath)];
            if (!tmp.empty())
              res.push_back(tmp);
          }
        } else {
          error = true;
          return;
        }
        m_json = res;
      }
    } break;

    case 9: { // * in dotnotation
      json res;

      for (auto &c : m_json) {
        if (c.is_array() && m_json.size() == 1)
          for (auto &d : c)
            res.push_back(d);
        else
          res.push_back(c);
      }

      if (res.size() < 1) {
        error = true;
        return;
      }
      m_json = res;
    } break;

    /* Selection Cases */
    case 10:
    case 12: {
      json res;

      for (auto &c : m_json)
        if (c.is_array() && m_json.size() == 1)
          m_json = m_json[0];

      if (m_json.is_object()) {
        for (auto b : a.getArgs()) {
          pointer = "/" + b;
          res.push_back(m_json[json::json_pointer(pointer)]);
        }
      } else {
        error = true;
        return;
      }

      if (res.size() < 1) {
        error = true;
        return;
      }

      m_json = res;
    } break;

    case 11:
    case 14: {
      json res;

      for (auto b : a.getArgs()) {
        if (m_json[0].type() == json::value_t::array && m_json.size() == 1) {
          res.push_back(m_json[0][stoi(b)]);
        } else {
          res.push_back(m_json[stoi(b)]);
        }
      }

      m_json = res;
    } break;

    case 13: {
      json res;

      for (auto b : a.getArgs())
        res.push_back(m_json[stoi(b) - 1]);

      m_json = res;
    } break;

    case 19: {
      json res;

      for (auto &j : m_json) {
        if (j.is_array())
          for (auto &k : j)
            res.push_back(k);
        else
          res.push_back(j);
      }

      m_json = res;
    } break;

    /* Filter Cases */
    case 20: {
      json res;
      vector<string> args = a.getArgs();

      for (auto &obj : m_json)
        if (obj.is_array() && m_json.size() == 1)
          m_json = m_json[0];

      if (args.size() == 1) { // select if identifier present
        for (auto &item : m_json) {
          if (item.find(args[0]) != item.end())
            res.push_back(item);
        }
      } else if (args.size() == 3) { // select if binary exp true
        for (auto &item : m_json) {
          switch (args[1].c_str()[0]) {
          case '<': {
            if (item.find(args[0]) != item.end() &&
                item[args[0]] < stoi(args[2]))
              res.push_back(item);
          } break;
          case '>': {
            if (item.find(args[0]) != item.end() &&
                item[args[0]] > stoi(args[2]))
              res.push_back(item);
          } break;
          default:
            error = true;
            return;
          }
        }
      }
      m_json = res;
    } break;
    case 30: {
      json res;
      vector<string> args = a.getArgs();

      for (auto &obj : m_json)
        if (obj.is_array() && m_json.size() == 1)
          m_json = m_json[0];

      if (args.size() == 3) {
        if (args[0] == "length" && args[1] == "-") {
          int selected = m_json.size() - stoi(args[2]);
          res.push_back(m_json[selected]);
        }
      }
      m_json = res;
    } break;
    }
  }
  return;
}