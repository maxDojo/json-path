#ifndef COMMAND_H
#define COMMAND_H

#include <stdint.h>
#include <string>
#include <vector>

namespace JsonPath {

class Command {
public:
  Command(int id, const std::vector<std::string> arguments);
  Command(int id);
  Command();
  ~Command();

  std::string str() const;
  int id() const;
  std::vector<std::string> getArgs();
  void addArg(std::string arg);

private:
  int m_id;
  std::vector<std::string> m_args;
};

} // namespace JsonPath

#endif // COMMAND_H
