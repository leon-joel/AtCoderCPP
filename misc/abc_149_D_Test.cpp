#include <bits/stdc++.h>
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE MyTest
#include <boost/test/included/unit_test.hpp>

#include "abc_149_D.cpp"

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

	string in, out;
	
	in = "5 2\n"
	     "8 7 6\n"
	     "rsrpr\n";
	out = "27";
	TestCase(in, out);

	in = "7 1\n"
	     "100 10 1\n"
	     "ssssppr\n";
	out = "211";
	TestCase(in, out);

	in = "30 5\n"
	     "325 234 123\n"
	     "rspsspspsrpspsppprpsprpssprpsr\n";
	out = "4996";
	TestCase(in, out);
}
