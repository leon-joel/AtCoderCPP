#include <bits/stdc++.h>
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE MyTest
#include <boost/test/included/unit_test.hpp>

#include "abc_155_E.cpp"

void TestCase(string input, string ans)
{
	stringstream ist;
	ist << input;
	ostringstream ost;
	Solver solver;
	solver.Solve(ist, ost);
	BOOST_CHECK_EQUAL(ost.str(), ans + "\n");
}

BOOST_AUTO_TEST_CASE(case0)
{

	// std::ifstream ist("input.txt");
	// std::ifstream result("result.txt");
	// std::string ans, line;
	// while (std::getline(result, line)) {
	// 	ans += line;
	// }

	// string input = "36";
	// string ans = "8";
	// stringstream ist;
	// ist << input;
	// ostringstream ost;
	// Solver solver;
	// solver.Solve(ist, ost);
	// BOOST_CHECK_EQUAL(ost.str(), ans + "\n");

	TestCase("36", "8");
	TestCase("91", "3");
	TestCase("98", "3");
	TestCase("31415926535897932384626433832795028841971693993755105820974944592"
	         "3078164062862089986280348253421170",
	         "243");
}
