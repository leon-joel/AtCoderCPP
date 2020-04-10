#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define RREP(i, n) for (int i = (n - 1); 0 <= i; --i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

namespace My
{
class Solver
{
  public:
	Solver() {}
	void Solve(istream &cin, ostream &cout)
	{
		string S;
		cin >> S;

		int scnt = 0;
		int ans = 0;
		REP (i, S.length()) {
			auto c = S[i];
			if (c == 'S') {
				++scnt;
			} else {
				if (0 == scnt) {
					// Tが残る
					++ans;
				} else {
					// STを消す
					--scnt;
				}
			}
		}
		ans += scnt;

		cout << ans << endl;
	}

	template <typename ArrayT>
	static void DumpArray(const ArrayT &arr)
	{
	#if defined(HOME)
		for (auto it = std::begin(arr); it != std::end(arr); ++it) {
			cerr << *it << " ";
		}
		cerr << endl;
	#endif
	};
	template <typename T>
	static bool ChMin(T &target, T value)
	{
		if (value < target) {
			target = value;
			return true;
		} else {
			return false;
		}
	}
	template <typename T>
	static bool ChMax(T &target, T value)
	{
		if (target < value) {
			target = value;
			return true;
		} else {
			return false;
		}
	}
};
} // namespace MySpace

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
