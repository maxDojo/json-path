#include "interpreter.h"
#include "parser.hpp"
#include "scanner.h"
#include "text.h"
#include <iostream>
#include <sstream>

using namespace JsonPath;
using namespace std;

int main(int argc, char **argv) {
  // std::string json_string = R"({"isbn": "123-456-222",
  //                   "maker": true,
  //               "author":
  //                   {
  //                   "lastname": "Doe",
  //                   "firstname": "Jane"
  //                   },
  //               "editor":
  //                   {
  //                   "lastname": "Smith",
  //                   "firstname": "Jane"
  //                   },
  //               "title": "The Ultimate Database Study Guide",
  //               "category": ["Non-Fiction", "Technology"]
  //           })";
  string json_string = c1.src;
  nlohmann::ordered_json j;

  if (nlohmann::json::accept(json_string))
    j = nlohmann::ordered_json::parse(json_string);
  else {
    cout << "Bad json object\n";
    return 1;
  }
  // string jp = "$.phoneNumbers[?(@.type)].number"; // /isbn/key
  // string jp = "$[phoneNumbers][(@.length-1)]"; // /isbn/key
  // string jp = "$.*"; // /isbn/key
  string jp = c1.query; // /isbn/key
  istringstream _jsonpath(jp);
  // _jsonpath >> jp;
  // _jsonpath = new std::istringstream(jp);

  Interpreter i(j, _jsonpath);
  int res = i.parse();
  i.show();

  for (auto i : i.getOutput())
    if (i.is_boolean())
      cout << "Boolean!" << i << endl;

  cout << "Parse complete. Result = " << res << endl;
  return res;
}
