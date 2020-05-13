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

struct Station {
	Station(int c, int s, int f) {
		C = c;
		S = s;
		F = f;
	}
	int C;
	int S;
	int F;
};

class Solver
{
  public:
	Solver() {}
	void Solve(istream &cin, ostream &cout)
	{
		int N;
		cin >> N;

		vector<Station> vec;
		REP (i, N-1) {
			int C, S, F;

			cin >> C >> S >> F;
			vec.emplace_back(C, S, F);
		}

		REP(i, N-1){
			// i番目から出発
			int t = 0;	// 現在時刻
			for (size_t j = i; j < N - 1; j++) {
				const auto& s = vec[j];
				if (t <= s.S){
					// Sに出発するので次の駅に着くのは S+C 秒後
					t = s.S + s.C;
				}else {
					// Sより後に出発する
					auto cycle = (t - s.S + s.F - 1) / s.F;
					t = s.S + s.F * cycle + s.C;
				}
			}
			cout << t << endl;
		}
		cout << 0 << endl;
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
