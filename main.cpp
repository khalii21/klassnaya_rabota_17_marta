#include "top-it-vector.hpp"
#include <iostream>

bool testElementAccess()
{
	khalikov::Vector< int > v;
	v.pushBack(1);
	v.pushBack(2);
	return v[0] == 1 && v[1] == 2;
}

bool testElementConstAccess()
{
	khalikov::Vector< int > v;
	v.pushBack(1);
	v.pushBack(2);
	const khalikov::Vector< int > & rv = v;
	return rv[0] == 1 && rv[1] == 2;
}

bool testElementOutOfBoundCheckedAccess()
{
	khalikov::Vector< int > v;
	try
	{
		v.at(0);
		return false;
	}
	catch (const std::out_of_range&)
	{
		return true;
	}
	catch (...)
	{
		return false;
	}
}

bool testElementInBoundCheckedAccess()
{
	khalikov::Vector< int > v;
	v.pushBack(1);
	try
	{
		int & val = v.at(0);
		return val == 1;
	}
	catch (...)
	{
		return false;
	}
}

bool testElementOutOfBoundCheckedConstAccess()
{
	const khalikov::Vector< int > v;
	try
	{
		v.at(0);
		return false;
	}
	catch (const std::out_of_range&)
	{
		return true;
	}
	catch (...)
	{
		return false;
	}
}

bool testElementInBoundCheckedConstAccess()
{
	khalikov::Vector< int > v;
	v.pushBack(1);
	const khalikov::Vector< int > & rv = v;
	try
	{
		const int & val = rv.at(0);
		return val == 1;
	}
	catch (...)
	{
		return false;
	}
}


bool testCopyConstructor()
{
	khalikov::Vector< int > v;
	v.pushBack(1);
	khalikov::Vector< int > yav = v;
	bool isAllEqual = v.getSize() == yav.getSize();
	for (size_t i = 0; isAllEqual && i < v.getSize(); ++i)
	{
		isAllEqual = isAllEqual && v[i] == yav[i];
	}
	return isAllEqual;
}

bool testSwap()
{
	khalikov::Vector< int > v;
	khalikov::Vector< int > yav;
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
	yav.pushBack(6);
	v.swap(yav);
	pass = pass && v.getSize() == 6;
	pass = pass && v.getCapacity() != 5;
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
		{"Vector can swap with another vec", testSwap},
		{"Vector should have copyConstructor", testCopyConstructor}
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
