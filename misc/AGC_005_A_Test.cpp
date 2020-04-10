#include <bits/stdc++.h>
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE MyTest
#include <boost/test/included/unit_test.hpp>

#include "AGC_005_A.cpp"

void TestCase(string input, string ans)
{
	stringstream ist;
	ist << input;
	ostringstream ost;
	My::Solver solver;
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

	string in, out;

	in = "TSTTSS\n";
    out = "4";
	TestCase(in, out);

	in = "SSTTST\n";
	out = "0";
	TestCase(in, out);

	in = "TSSTTTSS\n";
	out = "4";
	TestCase(in, out);
}
