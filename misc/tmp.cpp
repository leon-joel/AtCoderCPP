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
	Station(int c, int s, int f)
	{
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
		int N, M;
		cin >> N >> M;

		vector<int> fs[10];
		REP (i, M) {
			int a, b;
			cin >> a >> b;
			--a;
			--b;
			fs[a].emplace_back(b);
			fs[b].emplace_back(a);
		}
		// for (auto &&ff : fs) {
		// 	for (auto &&f : ff) {
		// 		cout << f << " ";
		// 	}
		// 	cout << endl;
		// }

		REP (i, N) {
			// 友達の友達をsetに追加していく
			set<int> ffset;
			for (auto &&f : fs[i]) {
				auto ff = fs[f];
				for (auto &&j : ff) {
					if (i == j) continue;
					ffset.insert(j);
				}
			}
			// 「友達の友達」の友達に自分が含まれていたスキップ
			int ans = 0;
			for (auto &&f : ffset) {
				if (fs[f].end() == find(fs[f].begin(), fs[f].end(), i)){
					++ans;
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
