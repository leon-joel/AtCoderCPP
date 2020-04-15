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
		string S;
		cin >> S;

		// 特別扱いで0回チェックだけやっておく
		char firstC = S[0];
		if (all_of(S.begin(), S.end(), [&](auto c) { return c == firstC; })){
			cout << 0 << endl;
			return;
		}

		// a-z を全部試す
		int minIter = INT_MAX;
		REP (i, 26) {
			char c = 'a' + i;
			string s = S;

			// 0,1 -> 0
			// 1,2 -> 1
			// 2,3 -> 2
			for (int len = s.size()-1; 0 < len; len--) {
				bool foundOther = false;
				REP (j, len) {
					// j番目を決める
					if (s[j] == c || s[j+1] == c){
						s[j] = c;
					}else{
						// 文字はそのままで
						foundOther = true;
					}
				}
				if (!foundOther){
					ReplaceIfSmaller(minIter, (int)(s.size() - len));
					break;
				}
			}
		}

		cout << minIter << endl;
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
