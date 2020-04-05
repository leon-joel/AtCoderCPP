#include <bits/stdc++.h>
using namespace std;

// auto mod int
// https://youtu.be/L8grWxBlIZ4?t=9858
// https://youtu.be/ERZuLAxZffQ?t=4807 : optimize
// https://youtu.be/8uowVvQ_-Mo?t=1329 : division
const int MOD = 1000000009;
// const int MOD = 1000000007;
// const int MOD = 998244353;
struct mint {
	long long x; // typedef long long ll;
	mint(long long x = 0) : x((x % MOD + MOD) % MOD) {}
	mint operator-() const { return mint(-x); }
	mint &operator+=(const mint a)
	{
		if ((x += a.x) >= MOD) x -= MOD;
		return *this;
	}
	mint &operator-=(const mint a)
	{
		if ((x += MOD - a.x) >= MOD) x -= MOD;
		return *this;
	}
	mint &operator*=(const mint a)
	{
		(x *= a.x) %= MOD;
		return *this;
	}
	mint operator+(const mint a) const { return mint(*this) += a; }
	mint operator-(const mint a) const { return mint(*this) -= a; }
	mint operator*(const mint a) const { return mint(*this) *= a; }
	mint pow(long long t) const
	{
		if (!t) return 1;
		mint a = pow(t >> 1);
		a *= a;
		if (t & 1) a *= *this;
		return a;
	}

	// for prime mod
	mint inv() const { return pow(MOD - 2); }
	mint &operator/=(const mint a) { return *this *= a.inv(); }
	mint operator/(const mint a) const { return mint(*this) /= a; }
};
istream &operator>>(istream &is, const mint &a) { return is >> a.x; }
ostream &operator<<(ostream &os, const mint &a) { return os << a.x; }

int main()
{
	cout << endl;

	cout << mint(MOD-1) << endl;
	cout << mint(MOD) << endl;

	cout << "MUL" << endl;
	cout << mint(2) * mint(3) << endl;
	cout << mint(MOD + 2) * mint(3) << endl;

	// 割り算は普通のわり算とは全然違う結果になる
	cout << "DIV" << endl;
	cout << 5LL / 2LL << endl;
	cout << mint(5) / mint(2) << endl;

	return 0;
}
