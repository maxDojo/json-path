#include "command.h"

#include <iostream>
#include <sstream>

using namespace JsonPath;
using std::cout;
using std::endl;

Command::Command(int id, const std::vector<std::string> arguments)
    : m_id(id), m_args(arguments) {}

Command::Command(int id) : m_id(id), m_args() {}

Command::Command() : m_id(), m_args() {}

Command::~Command() {}

std::string Command::str() const {
  std::stringstream ts;
  ts << "arguments = [";

  for (int i = 0; i < m_args.size(); i++) {
    ts << m_args[i];
    if (i < m_args.size() - 1) {
      ts << ", ";
    }
  }

  ts << "]";
  return ts.str();
}

int Command::id() const { return m_id; }

void Command::addArg(std::string arg) { m_args.push_back(arg); }
std::vector<std::string> Command::getArgs() { return m_args; }