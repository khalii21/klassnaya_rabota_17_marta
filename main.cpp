#include "top-it-vector.hpp"
#include <iostream>

bool testGetSize()
{
	khalikov::Vector< int > v;
	bool pass = v.isEmpty();
	v.pushBack(1);
	pass = pass && v.getSize() == 1;
	v.pushBack(2);
	pass = pass && v.getSize() == 2;
	return pass;
}

bool testVectorWithValue()
{
	khalikov::Vector< int > v;
	v.pushBack(1);
	bool pass = !v.isEmpty();
	pass = pass && v[0] == 1;
	return pass;
}


bool testDefaultVector()
{
  khalikov::Vector< int > v;
  return v.isEmpty();
}

int main()
{
  using test_t = bool(*)();
  using pair_t = std::pair< const char *, test_t >;
  pair_t tests[] = {
    {"Default vector should be empty", testDefaultVector},
		{"Vector with any value is not empty", testVectorWithValue},
		{"Vector should have impl of getSize", testGetSize}
  };
  const size_t count = sizeof(tests) / sizeof(pair_t);
  std::cout << std::boolalpha;
  bool pass = true;
  for (size_t i = 0; i < count; i++)
  {
    bool res = tests[i].second();
    std::cout << res << ": ";
    std::cout << tests[i].first << '\n';
    pass = pass && res;
  }
  std::cout << pass;
  std::cout << ": RESULT\n";
}
