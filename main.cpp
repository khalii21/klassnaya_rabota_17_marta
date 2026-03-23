#include "top-it-vector.hpp"
#include <iostream>

bool testSwap()
{
	khalikov::Vector< size_t > v;
	khalikov::Vector< size_t > yav;
	v.pushBack(1);
	v.pushBack(2);
	v.pushBack(3);
	v.pushBack(4);
	v.pushBack(5);
	yav.pushFront(1);
	yav.pushFront(2);
	yav.pushFront(3);
	yav.pushFront(4);
	yav.pushFront(5);
	bool pass = true;
	for (size_t i = 0; i < 5; i++)
	{
		if (v[i] == i + 1)
		{
			pass = pass && true;
		}
		else
		{
			pass = false;
		}
	}
	v.swap(yav);
	size_t index = 0;
	for (size_t i = 5; i > 0; i--)
	{
		if (v[index++] == i)
		{
			pass = pass && true;
		}
		else
		{
			pass = false;
		}
	}
	return pass;
}

bool testPushFront()
{
	khalikov::Vector< int > v;
	bool pass = v.isEmpty();
	v.pushFront(1);
	pass = pass && v[0] == 1;
	v.pushFront(2);
	pass = pass && v[0] == 2;
	return pass;
}

bool testPopBack()
{
	khalikov::Vector< int > v;
	bool pass = v.isEmpty();
	v.pushBack(1);
	v.pushBack(2);
	pass = pass && !v.isEmpty();
	v.popBack();
	v.popBack();
	pass = pass && v.isEmpty();
	return pass;
}

bool testGetCapacity()
{
	khalikov::Vector< int > v;
	bool pass = !v.getCapacity();
	v.resize(5);
	pass = pass && v.getCapacity() == 5;
	return pass;
}

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
		{"Vector should have impl of getSize", testGetSize},
		{"Vector should have impl of getCapacity", testGetCapacity},
		{"Vector can remove last element", testPopBack},
		{"Vector can pushFront", testPushFront},
		{"Vector can swap with another vec", testSwap}
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
