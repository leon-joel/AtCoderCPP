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

	void Solve(istream &cin, ostream &cout) {
		int H, W, K;
		cin >> H >> W >> K;

		vector<string> lines(H);
		REP (i, H) {
			string s;
			cin >> s;
			lines.emplace_back(s);
		}

		// 最大9bit(H-1)のbit全探索によって
		// 横方向でのカットを全通り行う

		// 全探索に使用する全bit数
		int N = H - 1;

		// bit mask の生成
		// 2^n     = 1 << n
		REP(mask, 1<<N){

			REP(j,N){
				if (mask>>j&1){
					// BITが立っている
					
				}
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
