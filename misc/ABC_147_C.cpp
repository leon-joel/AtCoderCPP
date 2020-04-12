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
template<typename T>
static void DumpGrid(const vector<vector<T>> &grid){
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
static void InitArray(ArrayT &arr, T initValue){
	for (auto &v : arr){
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
	void Solve(istream &cin, ostream &cout)
	{
		int N;
		cin >> N;

		// matrixを作る
		vector<vector<int>> grid(15, vector<int>(15));
		REP(i, 15)REP(j, 15){
			grid[i][j] = -1;
		}

		REP(i, N){
			int A;
			cin >> A;

			REP(j, A){
				int X, Y;
				cin >> X >> Y;

				grid[i][X - 1] = Y;
			}
		}
		// DumpGrid(grid);

		// BIT全探索
		// 全探索に使用する全bit数
		// N = 15;

		int ans = 0;
		// bit mask の生成
		// 2^n     = 1 << n
		REP(mask, 1<<N){
			array<int, 15> arr {0};	// デフォルトで0初期化される
			// BITが立っているところだけを 1 にしていく
			REP(j,N){
				if (mask>>j&1){
					arr[j] = 1;
				}
			}

			bool failed = false;
			// arrをなめて、正直者の証言だけをチェックしていく
			REP(i, N){
				// iビット目が立っている？
				if (arr[i]) {
					// その人の証言を確認する
					REP(k, N){
						if (grid[i][k] == -1) continue;
						if (grid[i][k] != arr[k]) {
							failed = true;
							break;
						}
					}
					if (failed) break;
				}
			}
			cerr << mask << "======" << endl;
			DumpArray(arr);
			if (!failed) {
				cerr << "Succeeded" << endl;
				ReplaceIfBigger(ans, __builtin_popcount(mask));
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
