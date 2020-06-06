#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define RREP(i, n) for (int i = (n - 1); 0 <= i; --i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

namespace My
{
template <typename ArrayT>
static void DumpArray(const ArrayT &arr, int len = 0,
                      int upper = std::numeric_limits<int>::max())
{
#if defined(HOME)
	if (len == 0) {
		for (auto it = std::begin(arr); it != std::end(arr); ++it) {
			cerr << *it << " ";
		}
	} else {
		for (int i = 0; i < len; i++) {
			if (arr[i] <= upper) {
				cerr << arr[i] << " ";
			} else {
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

	ll INF = 1 << 30;

	// ワーシャル・フロイドを順次適用していく
	// ※本番では関数化するほどのことはないが…
	void WarshallFloyd(vector<vector<ll>> &dist, int N)
	{
		REP (k, N) {
			REP (i, N) {
				REP (j, N) {
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
	}

	void Solve(istream &cin, ostream &cout)
	{
		int N, M;
		cin >> N >> M;

		vector<vector<ll>> dist(N);
		REP (i, N) {
			dist[i] = vector<ll>(N, INF);
			dist[i][i] = 0; // 自己ループなしだがわかりにくいので0を入れておく
		}
		REP (i, M) {
			int a, b, c;
			cin >> a >> b >> c;
			dist[--a][--b] = c;
			dist[b][a] = c;
		}
		// DumpGrid(dist);
		WarshallFloyd(dist, N);

		// cout << endl;
		// DumpGrid(dist);

		int K;
		cin >> K;
		REP (k, K) {
			int x, y, z;
			cin >> x >> y >> z;
			--x;
			--y;
			if (z < dist[x][y]) {
				dist[x][y] = dist[y][x] = z;
				// 新しい道を使って更新
				REP (i, N) {
					REP (j, N) {
						// ※3要素でも{}でくくれば1回でminできる
						dist[i][j] =
						    min({dist[i][j],
								 dist[i][x] + dist[y][j] + z,
						         dist[i][y] + dist[x][j] + z});
					}
				}
			}
			// cout << endl;
			// DumpGrid(dist);

			ll ans = 0;
			for (int i = 0; i < N - 1; i++) {
				for (int j = i + 1; j < N; j++) {
					ans += dist[i][j];
				}
			}
			cout << ans << endl;
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
