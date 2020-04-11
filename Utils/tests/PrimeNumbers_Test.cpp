#include <bits/stdc++.h>
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE MyTest
#include <boost/test/included/unit_test.hpp>

#include "../PrimeNumbers.cpp"

using namespace std;

BOOST_AUTO_TEST_CASE(IsPrimeNumber)
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

	BOOST_CHECK(!PrimeNumber::IsPrimeNumber(1));
	BOOST_CHECK(PrimeNumber::IsPrimeNumber(2));
	BOOST_CHECK(PrimeNumber::IsPrimeNumber(3));
	BOOST_CHECK(!PrimeNumber::IsPrimeNumber(4));
}

BOOST_AUTO_TEST_CASE(IsPrimeBruteforce){
	BOOST_CHECK(!PrimeNumber::IsPrimeBruteforce(1));
	BOOST_CHECK(PrimeNumber::IsPrimeBruteforce(2));
	BOOST_CHECK(PrimeNumber::IsPrimeBruteforce(3));
	BOOST_CHECK(!PrimeNumber::IsPrimeBruteforce(4));
	BOOST_CHECK(PrimeNumber::IsPrimeBruteforce(5));
	BOOST_CHECK(!PrimeNumber::IsPrimeBruteforce(6));
	BOOST_CHECK(PrimeNumber::IsPrimeBruteforce(7));
	BOOST_CHECK(!PrimeNumber::IsPrimeBruteforce(10));
	BOOST_CHECK(PrimeNumber::IsPrimeBruteforce(11));
}
BOOST_AUTO_TEST_CASE(IsPrimeMillarRabin)
{
	BOOST_CHECK(!PrimeNumber::IsPrimeMillarRabin(1));
	BOOST_CHECK(PrimeNumber::IsPrimeMillarRabin(2));
	BOOST_CHECK(PrimeNumber::IsPrimeMillarRabin(3));
	BOOST_CHECK(!PrimeNumber::IsPrimeMillarRabin(4));
	BOOST_CHECK(PrimeNumber::IsPrimeMillarRabin(5));
	BOOST_CHECK(!PrimeNumber::IsPrimeMillarRabin(6));
	BOOST_CHECK(PrimeNumber::IsPrimeMillarRabin(7));
	BOOST_CHECK(!PrimeNumber::IsPrimeMillarRabin(10));
	BOOST_CHECK(PrimeNumber::IsPrimeMillarRabin(11));
}

BOOST_AUTO_TEST_CASE(IsPrime)
{
	BOOST_CHECK(!PrimeNumber::IsPrime(1));
	BOOST_CHECK(PrimeNumber::IsPrime(2));
	BOOST_CHECK(PrimeNumber::IsPrime(3));
	BOOST_CHECK(!PrimeNumber::IsPrime(4));
	BOOST_CHECK(PrimeNumber::IsPrime(5));
	BOOST_CHECK(!PrimeNumber::IsPrime(6));
	BOOST_CHECK(PrimeNumber::IsPrime(7));
	BOOST_CHECK(!PrimeNumber::IsPrime(10));
	BOOST_CHECK(PrimeNumber::IsPrime(11));
}

template<class ArrayT0, class ArrayT1>
void CheckCollections(const ArrayT0& a0, const ArrayT1& a1){
	BOOST_CHECK_EQUAL_COLLECTIONS(begin(a0), end(a0), begin(a1), end(a1));
}

BOOST_AUTO_TEST_CASE(Eratosthenes)
{
	CheckCollections(vector<int>{2}, PrimeNumber::Eratosthenes(2));
	CheckCollections(vector<int>{2, 3, 5, 7}, PrimeNumber::Eratosthenes(10));
	CheckCollections(vector<int>{2, 3, 5, 7, 11, 13, 17, 19, 23, 29},
	                 PrimeNumber::Eratosthenes(30));

	// auto ans = PrimeNumber::Eratosthenes(1000);
	// for (auto &&v : ans){
	// 	cerr << v << " ";
	// }
	// cerr << endl;

	CheckCollections(PrimeNumber::PRIMES, PrimeNumber::Eratosthenes(50000));
	CheckCollections(PrimeNumber::PRIMES_10_5, PrimeNumber::Eratosthenes(100000));
}
