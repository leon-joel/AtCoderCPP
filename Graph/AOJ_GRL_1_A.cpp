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

#define INF 1LL << 60

using Edge = pair<ll, ll>;          //辺
using Graph = vector<vector<Edge>>; //隣接リスト

class Solver
{
  public:
	Solver() {}

	ll V, E, r;
	Graph G;
	vector<ll> dist;

	void dijkstra()
	{
		//{距離, 頂点}のpairで格納
		//距離の小さいものから取り出す
		priority_queue<pair<ll, ll>, vector<pair<ll, ll>>,
		               greater<pair<ll, ll>>>
		    que;

		que.push({0, r}); //距離0の頂点rを入れる

		while (!que.empty()) { //キューが空になるまで

			auto now = que.top();
			que.pop();
			//キューの先頭を取り出す
			ll nowDist = now.first;  //取り出した距離
			ll nowNode = now.second; //取り出した頂点

			//取り出した距離が、今現在わかっている頂点の距離より長い時スルーする
			if (nowDist > dist[nowNode]) continue;

			for (Edge next : G[nowNode]) {
				//行ける頂点について
				ll nextDir = next.first;     //辺の行き先
				ll nextWeight = next.second; //辺の重み

				//更新しても距離を小さくできないときスルーする
				if (dist[nextDir] <= dist[nowNode] + nextWeight) continue;
				dist[nextDir] =
				    min(dist[nextDir], dist[nowNode] + nextWeight); //更新する
				que.push({dist[nextDir], nextDir}); //キューに追加
			}
		}
	}
	void Solve(istream &cin, ostream &cout)
	{
		cin >> V >> E >> r;
		G.resize(V);

		for (int i = 0; i < E; i++) {
			int s, t, d;
			cin >> s >> t >> d;
			G[s].push_back({t, d});
		}

		dist.resize(V, INF);
		dist[r] = 0;
		dijkstra();
		for (ll x : dist) {
			if (x == INF) {
				cout << "INF" << endl;
			} else {
				cout << x << endl;
			}
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
