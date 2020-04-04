#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// auto mod int
// https://youtu.be/L8grWxBlIZ4?t=9858
// https://youtu.be/ERZuLAxZffQ?t=4807 : optimize
// https://youtu.be/8uowVvQ_-Mo?t=1329 : division
const int mod = 1000000007;
// const int mod = 998244353;
struct mint {
	ll x; // typedef long long ll;
	mint(ll x = 0) : x((x % mod + mod) % mod) {}
	mint operator-() const { return mint(-x); }
	mint &operator+=(const mint a)
	{
		if ((x += a.x) >= mod) x -= mod;
		return *this;
	}
	mint &operator-=(const mint a)
	{
		if ((x += mod - a.x) >= mod) x -= mod;
		return *this;
	}
	mint &operator*=(const mint a)
	{
		(x *= a.x) %= mod;
		return *this;
	}
	mint operator+(const mint a) const { return mint(*this) += a; }
	mint operator-(const mint a) const { return mint(*this) -= a; }
	mint operator*(const mint a) const { return mint(*this) *= a; }
	mint pow(ll t) const
	{
		if (!t) return 1;
		mint a = pow(t >> 1);
		a *= a;
		if (t & 1) a *= *this;
		return a;
	}

	// for prime mod
	mint inv() const { return pow(mod - 2); }
	mint &operator/=(const mint a) { return *this *= a.inv(); }
	mint operator/(const mint a) const { return mint(*this) /= a; }
};
istream &operator>>(istream &is, const mint &a) { return is >> a.x; }
ostream &operator<<(ostream &os, const mint &a) { return os << a.x; }

const int ILEN = 205;
const int JLEN = 1805;
const int KLEN = 2;
mint DPM[ILEN][JLEN][KLEN];
mint DPD[ILEN][JLEN][KLEN];
const int Match = 1;
const int Free = 0;

void SolveKetaDP(mint dp[ILEN][JLEN][KLEN], string &s)
{
	dp[0][0][Match] = 1;

	// ※loopはいつも昇順にしたほうが良さそう
	// ※逆順にすると、遷移も逆方向にしないといけないので ※桁数を逆にする方が簡単
	rep (i, size(s)) {
		auto ni = i + 1;
		auto n = s[i] - '0';
		rep (j, JLEN) {
			rep (k, 2) {
				if (dp[i][j][k].x == 0) continue;

				rep (nx, 10) {
					auto nj = j + nx;
					auto nk = k; // ※nkは毎回初期化しないとおかしくなるよ！
					if (k == Match) {
						if (n < nx) continue;
						if (nx < n) {
							nk = Free;
						}
					} else {
					}

					dp[ni][nj][nk] += dp[i][j][k];
				}
			}
		}
	}
}

int main()
{
	string M, D;
	cin >> M >> D;
	// M = "2";
	// D = "3";

	// 2つの桁DPを解く

	// 桁DP
	// dp[桁（上位から）][合計][制限なし/あり] = パターン数
	SolveKetaDP(DPM, M);
	SolveKetaDP(DPD, D);

	// 結果を計算
	// ※ 配るDPの場合、結果は S.Length(＝最後のi + 1) に格納されている
	// ※ 整数問題の場合、all 0
	// の分を1個マイナスするのを忘れずに！先行0にも要注意！ ※
	// MOD系は、最後のMODを忘れないことと、MODの前処理で負数にしないこと
	mint ans = 0;
	for (int j = 1; j < JLEN; j++){
		auto m = DPM[size(M)][j][0] + DPM[size(M)][j][1];
		auto d = DPD[size(D)][j][0] + DPD[size(D)][j][1];
		ans += m * d;
	}			
	cout << ans << endl;
	return 0;
}
