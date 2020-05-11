#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define RREP(i, n) for (int i = (n - 1); 0 <= i; --i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

namespace My
{
template <typename ArrayT>
static void DumpArray(const ArrayT &arr)
{
#if defined(HOME)
	for (auto it = std::begin(arr); it != std::end(arr); ++it) {
		cerr << *it << " ";
	}
	cerr << endl;
#endif
}
template <typename T>
static void DumpGrid(const vector<vector<T>> &grid)
{
#if defined(HOME)
	REP (i, grid.size()) {
		REP (j, grid[i].size()) {
			cerr << grid[i][j] << " ";
		}
		cerr << endl;
	}
#endif
}
template <class ArrayT, typename T>
static void InitArray(ArrayT &arr, T initValue)
{
	for (auto &v : arr) {
		v = initValue;
	}
}
template <typename T>
static bool ReplaceIfSmaller(T &target, T value)
{
	if (value < target) {
		target = value;
		return true;
	} else {
		return false;
	}
}
template <typename T>
static bool ReplaceIfBigger(T &target, T value)
{
	if (target < value) {
		target = value;
		return true;
	} else {
		return false;
	}
}

class Solver
{
  public:
	Solver() {}
	void Solve(istream &cin, ostream &cout)
	{
		long A, B, X;
		cin >> A >> B >> X;

		// 1桁MAX
		long ansN = 0;
		for (size_t i = 1; i <= 10; i++) {
			auto n = pow(10, i - 1);
			auto minPrice = A * n + B * i;
			if (X < minPrice) break;

			n = pow(10, i) - 1;
			auto maxPrice = A * n + B * i;
			cerr << i << ": " << minPrice << "-" << maxPrice << endl;
			if (maxPrice < X){
				ansN = n;
				continue;
			}

			// i桁数に確定
			// price = A * N + B * i
			// price - B * i = A * N
			// (price - B * i) / A = N
			n = (X - B * i) / A;
			ansN = n;
		}

		if (pow(10, 9) < ansN){
			ansN = pow(10, 9);
		}

		cout << ansN << endl;
	}
};
} // namespace My

#if !defined(BOOST_TEST_MODULE)
#if !defined(GTEST_INCLUDE_GTEST_GTEST_H_)
int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	My::Solver solver;
	solver.Solve(std::cin, std::cout);

	return 0;
}
#endif
#endif
