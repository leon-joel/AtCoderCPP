#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define RREP(i, n) for (int i = (n - 1); 0 <= i; --i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

template <typename ArrayT>
void DumpArray(const ArrayT &arr)
{
#if defined(HOME)
	for (auto it = arr.begin(); it != arr.end(); ++it) {
		cerr << *it << " ";
	}
	cerr << endl;
#endif
};
template <typename T>
bool ChMin(T &target, T value)
{
	if (value < target) {
		target = value;
		return true;
	} else {
		return false;
	}
}
template <typename T>
bool ChMax(T &target, T value)
{
	if (target < value) {
		target = value;
		return true;
	} else {
		return false;
	}
}

// 繰り下がり有無
static const int DESC = 1;
static const int NONE = 0;

const int ILEN = 10000005;
const int KLEN = 2;

int DP[ILEN][KLEN];

class Solver
{
	void InitDP()
	{
		REP (i, ILEN)
			REP (k, KLEN) {
				DP[i][k] = INT_MAX;
			}
	}

  public:
	Solver() {}
	void Solve(istream &cin, ostream &cout)
	{
		string S;
		cin >> S;

		// 桁DP
		// dp[桁（下位から）]
		//   [前の桁からの繰り下がりなし/あり]
		//   = 使用した紙幣枚数

		SolveDP(S);

		// 結果を計算
		// ※ 配るDPの場合、結果は S.Length(＝最後のi + 1) に格納されている
		// ※ 整数問題の場合、all 0
		// の分を1個マイナスするのを忘れずに！先行0にも要注意！ ※
		// MOD系は、最後のMODを忘れないことと、MODの前処理で負数にしないこと
		int ans = min(DP[S.length()][DESC]+1, DP[S.length()][NONE]);

		DumpDP(S.length());

		cout << ans << endl;
	}

	void SolveDP(string s)
	{
		InitDP();
		DP[0][NONE] = 0;

		// ※loopはいつも昇順にしたほうが良さそう
		// ※逆順にすると、遷移も逆方向にしないといけないので
		// ※桁数を逆にする方が簡単
		REP (i, s.size()) {
			auto ni = i + 1;
			auto x = s[i] - '0';

			// ■繰り下がりなし
			if (INT_MAX != DP[i][NONE]) {
				// x を出す
				ChMin(DP[ni][NONE], DP[i][NONE] + x);
				// 繰り下がって0を出す
				ChMin(DP[ni][DESC], DP[i][NONE] + (10 - x));
			}

			// ■繰り下がりあり
			if (INT_MAX != DP[i][DESC]) {
				if (x == 9) {
					// 0を出して、更に繰り下がりするしかない
					ChMin(DP[ni][DESC], DP[i][DESC]);
				} else {
					// x + 1 を出す
					ChMin(DP[ni][NONE], DP[i][DESC] + x + 1);
					// 0 を出して、更に繰り下がらせる
					ChMin(DP[ni][DESC], DP[i][DESC] + (9 - x));
				}
			}
		}
	}

	void DumpDP(int len)
	{
#if defined(HOME)
		REP (i, len + 1) {
			cerr << DP[i][0] << "-" << DP[i][1] << " ";
		}
		cerr << endl;
#endif
	}
};

#if !defined(BOOST_TEST_MODULE)
#if !defined(GTEST_INCLUDE_GTEST_GTEST_H_)
int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	Solver solver;
	solver.Solve(std::cin, std::cout);

	return 0;
}
#endif
#endif
