#include <bits/stdc++.h>
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE MyTest
#include <boost/test/included/unit_test.hpp>

#include "yuki_911.cpp"

BOOST_AUTO_TEST_CASE(case0)
{
	BOOST_CHECK(2 == 2);

	// string input = "6 1325 1350\n1332 1335 1334 1329 1328 1331 ";
	// stringstream ist;
	// ist << input;

	std::ifstream ist("input.txt");
	std::ifstream result("result.txt");
	std::string ans, line;
	while (std::getline(result, line)){
		ans += line;
	}

	ostringstream ost;

	Solver solver;
	solver.Solve(ist, ost);

	BOOST_CHECK_EQUAL(ost.str(), ans);
}