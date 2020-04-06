#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define RREP(i, n) for (int i = (n - 1); 0 <= i; --i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

template <typename ArrayT> void DumpArray(const ArrayT &arr)
{
	for (auto it = arr.begin(); it != arr.end(); ++it) {
		cerr << *it << " ";
	}
	cerr << endl;
};


class Solver
{
	const int Match = 1;
	const int Free = 0;

	ll DP[65][2];
	void InitDP()
	{
		REP (i, 65)
			REP (k, 2) {
				DP[i][k] = 0;
			}
	}

  public:
	Solver(){}
	void Solve(istream &cin, ostream &cout)
	{
		ll N, L, R;
		cin >> N >> L >> R;

		ll maxA = 0;
		vector<ll> AS(N);
		REP (i, N) {
			cin >> AS[i];
			maxA = max(maxA, AS[i]);
		}
		// DumpArray(AS);

		// 桁DP
		// dp[2進数での桁（上位から）]
		//   [制限なし/あり]
		//   = パターン数

		// TASK: R,L == 0の場合の特殊処理

		// [0, R] でDP
		ll ansL = 0;
		if (0 < R) {
			auto len = SolveDP(R, AS, maxA);
			ansL = DP[len][0] + DP[len][1];

			cerr << "DP L [" << len << "]" << endl;
			DumpDP(len);
		}

		// [0, L-1] でDP
		ll ansR = 0;
		if (0 < L) {
			auto len = SolveDP(L - 1, AS, maxA);
			ansR = DP[len][0] + DP[len][1];

			cerr << "DP R [" << len << "]" << endl;
			DumpDP(len);
		}

		// 結果
		cout << ansL - ansR << endl;
	}

	int SolveDP(ll upper, vector<ll> nums, ll maxN)
	{
		ll mm = max(upper, maxN);
		int len = 0;
		while (0 < mm) {
			++len;
			mm = mm >> 1;
		}

		InitDP();
		DP[0][Match] = 1;
		// ※loopはいつも昇順にしたほうが良さそう
		// ※逆順にすると、遷移も逆方向にしないといけないので ※桁数を逆にする方が簡単
		REP (i, len) {
			auto digit = len - 1 - i;
			auto ni = i + 1;
			auto x = (upper & (1LL << digit)) ? 1 : 0;

			REP (k, 2) {
				if (DP[i][k] == 0) continue;

				for (ll nx = 0; nx < 2; nx++) {
					auto nk = k; // ※nkは毎回初期化しないとおかしくなるよ！
					if (k == Match) {
						if (x < nx) continue;
						if (nx < x) {
							nk = Free;
						}
					} else {
					}

					// 当該bitが単調増加になっているかどうかを調べる
					auto f = [&] {
						ll preX = 0;
						for (auto &&n : nums) {
							auto xv = (n & (1LL << digit)) ^ (nx << digit);
							if (xv < preX) return false;
							preX = xv;
						}
						return true;
					};
					if (!f()) continue;

					DP[ni][nk] += DP[i][k];
				}
			}
		}

		return len;
	}

	void DumpDP(int len)
	{
		REP (i, len + 1) {
			cerr << DP[i][0] << "-" << DP[i][1] << " ";
		}
		cerr << endl;
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
