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

	// [row][col]
	int dist[10][10];
	void Solve(istream &cin, ostream &cout)
	{
		int H, W;
		cin >> H >> W;

		REP(i, 10){
			REP(j, 10){
				cin >> dist[i][j];
			}
		}

		// 最短経路問題
		// ワーシャル・フロイドで最小コストを求める
		REP(k, 10){
			REP(i, 10){
				REP(j, 10){
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
		// REP(i, 10){
		// 	DumpArray(dist[i]);
		// }

		ll ans = 0;
		REP (i, H) {
			REP (j, W) {
				int n;
				cin >> n;

				if (n == -1 || n == 1) continue;

				ans += dist[n][1];
			}
		}

		cout << ans << endl;
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
