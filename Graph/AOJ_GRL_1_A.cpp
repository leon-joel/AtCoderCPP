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

using Edge = pair<ll, ll>;
using Graph = vector<vector<Edge>>; 

class Solver
{
  public:
	Solver() {}

	ll V, E, r;
	// 隣接リスト Graph[from頂点] = {to頂点, to頂点への距離}
	Graph G;
	// dist[行き先頂点] = start地点からの最短距離
	vector<ll> dist;

	// シンプルにダイクストラを適用するだけの問題
	void dijkstra()
	{
		// {距離, 頂点} のpairで格納 ※Graphの要素Edge(pair)とは異なる点に注意！
		// 距離が最も小さいものを取り出すのでGreaterを指定している ※降順ソートして、後ろから取り出すイメージ
		priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> que;
		//距離0の頂点rを入れる
		que.emplace(0, r);

		while (!que.empty()) {
			// キューの先頭を取り出す
			auto p = que.top();
			que.pop();
			ll curDist = p.first;  //取り出した距離
			ll curNode = p.second; //取り出した頂点

			//(optional)取り出した距離が、今現在わかっている頂点の距離より長い時スルーする
			if (dist[curNode] < curDist) continue;

			// 行ける頂点にすべてについて距離を更新
			for (auto&& next : G[curNode]) {
				ll nextNode = next.first;     //辺の行き先
				ll nextWeight = next.second;  //辺の重み

				// 距離を小さくできたときだけキューに追加
				if (ReplaceIfSmaller(dist[nextNode], dist[curNode] + nextWeight)){
					que.emplace(dist[nextNode], nextNode);
				}
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
			G[s].emplace_back(t, d);
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
