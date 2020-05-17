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
	int dist[200][200];
	void Solve(istream &cin, ostream &cout)
	{
		int N, M, R;
		cin >> N >> M >> R;

		vector<int> r;
		REP (i, R) {
			int c;
			cin >> c;
			r.emplace_back(c - 1);
		}

		REP(i, N){
			REP(j, N){
				// 辺が存在しないところには十分大きな値を入れておく
				// ただし、INT_MAXみたな大きすぎるのはだめ。（オーバーフローするため）
				// おそらく10億くらいが適切かと。
				dist[i][j] = 1'000'000'000;
			}
		}

		REP(m, M){
			int A, B, C;
			cin >> A >> B >> C;
			if (C < dist[--A][--B]){
				dist[A][B] = dist[B][A] = C;

			}
		}
		// REP(i, N){
		// 	DumpArray(dist[i]);
		// }

		// 最短経路問題
		// ワーシャル・フロイドで最小コストを求める
		REP(k, N){
			REP(i, N){
				REP(j, N){
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
		// REP(i, N){
		// 	DumpArray(dist[i]);
		// }

		// R[]の順列を求めて
		sort(std::begin(r), std::end(r));
		ll ans = 100000000;
		do {
			ll d = 0;
			REP (i, R - 1) {
				d += dist[r[i]][r[i + 1]];
			}
			ReplaceIfSmaller(ans, d);

		} while (std::next_permutation(std::begin(r), std::end(r)));

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
