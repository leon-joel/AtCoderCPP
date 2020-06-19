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

struct Child
{
public:
	int Rate;
	int Garden;
	Child(){}
	Child(int rate, int garden) {
		Rate = rate;
		Garden = garden;
	}
};

class Solver
{
  public:
	Solver() {}

	void Solve(istream &cin, ostream &cout) {
		int N, Q;
		cin >> N >> Q;

		// 園児配列
		vector<Child> cs(N);
		// [園番号] = 所属園児Rate の multiset
		vector<multiset<int>> ks(200005);	// Arrayで確保しようとするとSegmentationFault11が発生する
		// 最強園児集団
		multiset<int> maxs;

		// i幼稚園の最高Rate
		auto getMax = [&](int g) {
			if (ks[g].size() == 0) return -1;
			return *ks[g].rbegin();
		};
		auto dumpMaxs = [&]() {
			cout << "maxs: ";
			for (auto &&r : maxs) {
				cout << r << " ";
			}
			cout << endl;
		};
		// from園の最強レートを maxs からいったん削除する
		// from園から当該幼児Rateを削除する
		// from園の最強レートを maxs に追加する
		auto delChild = [&](int g, int rate) {
			auto curMax = getMax(g);
			// ※erase(rate)だと当該rateを全部削除してしまうので、1つだけ削除するときはfindを併用する
			if (curMax != -1) maxs.erase(maxs.find(curMax));
			ks[g].erase(ks[g].find(rate));
			auto newMax = getMax(g);
			if (newMax != -1) maxs.insert(newMax);
		};
		// to園  の最強レートを maxs からいったん削除する
		// to園  に当該幼児idxを追加する
		// to園  の最強レートを maxs に追加する
		auto addChild = [&](int g, int rate) {
			auto curMax = getMax(g);
			// ※erase(rate)だと当該rateを全部削除してしまうので、1つだけ削除するときはfindを併用する
			if (curMax != -1) maxs.erase(maxs.find(curMax));
			ks[g].insert(rate);
			maxs.insert(getMax(g));
		};

		REP (i, N){
			int A, B;
			cin >> A >> B;
			cs[i] = Child(A, B);
			auto rate = getMax(B);
			if (rate != -1){
				maxs.erase(maxs.find(rate));
			}
			ks[B].insert(A);
			maxs.insert(getMax(B));
		}

		REP(i, Q){
			int C, D;
			cin >> C >> D;
			--C;
			// 退園
			delChild(cs[C].Garden, cs[C].Rate);
			// 所属園情報を転園先園idx(to園)に更新
			cs[C].Garden = D;
			// 入園
			addChild(cs[C].Garden, cs[C].Rate);

			// dumpMaxs();
			auto minR = *maxs.begin();
			cout << minR << endl;
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
