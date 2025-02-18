#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <memory>
#include <sstream>
#include <vector>

#include "json.hpp"
#include "scanner.h"

#include "parser.hpp"

namespace JsonPath {

class Command;

class Interpreter {
public:
  Interpreter();
  Interpreter(nlohmann::ordered_json inp);
  Interpreter(nlohmann::ordered_json inp, istringstream &jsonpath_inp);

  /**
   * Run parser. Results are stored inside.
   * \returns 0 on success, 1 on failure
   */
  int parse();
  bool error = false;

  // Clear AST
  void clear();

  // Print AST
  std::string str() const;

  nlohmann::ordered_json getOutput();
  void show();
  void evaluate();
  void showCommands() {
    int n = 1;
    for (auto &i : m_commands) {
      cout << "Command " << n << " = " << i.id() << ";  Arguments: ";
      for (auto k : i.getArgs())
        cout << k << "; ";
      cout << "\n";
      n++;
    }
  }

  /**
   * Switch scanner input stream. Default is standard input (std::cin).
   * It will also reset AST.
   */
  void switchInputStream(istringstream &is);
  istringstream _jsonpath;

  friend class Parser;
  friend class Scanner;

private:
  // Used internally by Parser to insert AST nodes.
  void addCommand(const Command &cmd);

  // Used internally by Scanner YY_USER_ACTION to update location indicator
  void increaseLocation(unsigned int loc);

  // Used to get last Scanner location. Used in error messages.
  unsigned int location() const;

private:
  Scanner m_scanner;
  Parser m_parser;
  std::vector<Command> m_commands;
  unsigned int m_location;       // Used by scanner
  nlohmann::ordered_json m_json; // parsed ordered_json input
};

} // namespace JsonPath

#endif // INTERPRETER_H
