#include <bits/stdc++.h>
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE MyTest
#include <boost/test/included/unit_test.hpp>

#include "ABC_147_C.cpp"

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
	string in, out;

	in = "1\n"
	     "3 7\n";
    out = "2";
	TestCase(in, out);

	in = "4\n"
	     "13 13\n"
	     "7 11\n"
	     "7 11\n"
	     "2017 2017\n";
	out = "1\n"
	      "0\n"
		  "0\n"
		  "1";
	TestCase(in, out);

	in = "6\n"
	     "1 53\n"
	     "13 91\n"
	     "37 55\n"
	     "19 51\n"
	     "73 91\n"
	     "13 49\n";
	out = "4\n"
	      "4\n"
	      "1\n"
	      "1\n"
	      "1\n"
	      "2";
	TestCase(in, out);
}
