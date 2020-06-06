#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define RREP(i, n) for (int i = (n - 1); 0 <= i; --i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

namespace My
{
template <typename ArrayT>
static void DumpArray(const ArrayT &arr, int len = 0, int upper = std::numeric_limits<int>::max())
{
#if defined(HOME)
	if (len == 0){
		for (auto it = std::begin(arr); it != std::end(arr); ++it) {
			cerr << *it << " ";
		}
	}else{
		for (int i = 0; i < len; i++) {
			if (arr[i] <= upper){
				cerr << arr[i] << " ";
			}else{
				cerr << "x ";
			}
		}
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
	int dist[100][100];
	void Solve(istream &cin, ostream &cout)
	{
		int V, E;
		cin >> V >> E;

		// 辺が存在しないところには十分大きな値を入れておく
		// ただし、INT_MAXみたな大きすぎるのはだめ。（オーバーフローするため）
		// おそらく10億くらいが適切かと。
		const int INF = 1'000'000'000;
		REP(i, 100){
			REP(j, 100){
				// この問題は「自己ループなし」と書いてあるが、
				// dist[i][i] == 0 は自明なので、そこだけは0初期化する
				dist[i][j] = i == j ? 0 : INF;
			}
		}

		REP(i, E){
			int S, T, D;
			cin >> S >> T >> D;
			// 有向グラフ（＝双方向じゃない）のでただ単にセットするだけでOK
			dist[S][T] = D;
			// if (D < dist[S][T]) {
			// 	dist[S][T] = dist[T][S] = D;
			// }
		}
		cerr << endl;
		REP (i, V) {
			DumpArray(dist[i], V, INF-1);
		}

		// 最短経路問題
		// 全頂点間の最小コストを計算（ワーシャル・フロイド）
		REP(k, E){
			REP(i, E){
				REP(j, E){
					dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
		cerr << endl;


		// 結合
		// auto join = [&](int i) {
		// 	const char *delim = " "; // 区切り文字
		// 	copy(
		// 		&dist[i][0],
		// 		&dist[i][V-1],
		// 		ostream_iterator<int>(std::cout, delim));
		// 	cout << dist[i][V-1];
		// };
		auto join = [&](int i) {
			const char *delim = " "; // 区切り文字
			for (int j = 0; j < V-1; j++){
				cout << (dist[i][j] == INF ? "INF" : to_string(dist[i][j])) << delim;
			}
			cout << (dist[i][V-1] == INF ? "INF" : to_string(dist[i][V-1]));
		};

		REP (i, V){
			join(i);
			cout << endl;
		}
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
