#include <string>
#include <vector>

using namespace std;
class data {
public:
  data(string json_src, string jpath_query);
  ~data();

  string src, query;
};

data::data(string json_src, string jpath_query)
    : src(json_src), query(jpath_query) {}

data::~data() {}

data c1(
    R"({"outer":{"inner_prop_num": 5, "inner_prop_str":"my string", "inner prop#$%^&*@''`| num": 7, "inner prop str":"my other string","inner_arr_num": [0,1,2,3], "inner_arr_str": ["zero", "one", "two", "three"], "inner_arr_obj": [{"num":0,"str":"zero"},{"num":1,"str":"one"},{"num":2,"str":"two"},{"num":3,"str":"three"}]}, "outer_num": 9999, "outer_str":"Hello World"})",
    "outer[\"inner prop#$%^&*@''`| num\"]");