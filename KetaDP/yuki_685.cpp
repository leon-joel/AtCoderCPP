#include <bits/stdc++.h>
// #include <iostream>
// #include <utility>
// #include <string>

#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int BLEN = 64;
int DP[BLEN + 2][3][2];
int B[BLEN];
int main()
{
	long N;
	// cin >> N;
	N = 10;
	rep (i, BLEN) {
		if (N & (1LL << i)) {
			B[BLEN - i - 1] = 1;
		} else {
			B[BLEN - i - 1] = 0;
		}
	}

	// 桁DP
	// dp[桁（上位から）]
	//   [未確定/and<xor確定/and<xor<or確定]
	//   [制限なし/あり]
	const int Match = 1;
	const int Free = 0;

	DP[0][0][Match] = 1;

	rep (i, BLEN) {
		auto ni = i + 1;
		auto n = B[i];
		rep (j, 3) {
			rep (k, 2) {
				if (DP[i][j][k] == 0) continue;

				rep (nx, 2) {
					auto nj = j;
					auto nk = k;
					if (k == Match) {
						if (n < nx) continue;
						if (nx < n) {
							nk = Free;
						}
					} else {
					}

					if (nx == 1) {
						if (j == 0) {
							nj = 1;	// 1-0
							DP[ni][nj][nk] += DP[i][j][k];
							// nj = 0;	// 1-1 -> NG確定なので遷移先なし
							// DP[ni][nj][nk] += DP[i][j][k];
						} else if (j == 1) {
							nj = 1;	// 1-0
							DP[ni][nj][nk] += DP[i][j][k];
							nj = 2;	// 1-1
							DP[ni][nj][nk] += DP[i][j][k];
						} else {
							// すでに条件を満たしているので、何を入れても条件を満たしたまま
							DP[ni][nj][nk] += DP[i][j][k] * 2;	// 1-0, 1-1
						}
					}else{
						// 0-0 パターン
						DP[ni][nj][nk] += DP[i][j][k];
					}
				}
			}
		}
	}
	rep (i, BLEN + 1) {
		cout << "i=" << i << "; ";
		rep (j, 3) {
			rep (k, 2) {
				cout << DP[i][j][k] << " ";
			}
		}
		cout << endl;
	}

	auto ans = DP[BLEN][2][0] + DP[BLEN][2][1];
	cout << ans << endl;
	return 0;
}
