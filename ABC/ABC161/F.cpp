#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// nの約数を全列挙。但し 1 は除外。n 自身は含む。
// ※結果はソートされていない
template <typename T> vector<T> ListDivisors(T n)
{
	vector<T> res;
	for (T i = 1; i * i <= n; ++i) {
		if (n % i != 0) continue;

		// 1は除外
		if (1 < i) res.push_back(i);

		if (i * i != n) res.push_back(n / i);
	}
	return res;
}

int main()
{
	ll N;
	cin >> N;

	set<ll> set;

	auto ds = ListDivisors(N - 1);
	for (auto &&d : ds) {
		if (N % d != 0) {
			set.insert(d);
			cerr << " 1: " << d << endl;
		}
	}

	ds = ListDivisors(N);
	for (auto &&d : ds) {
		auto n = N;
		while (n % d == 0)
			n /= d;

		if (n % d == 1) {
			set.insert(d);
			cerr << " 2: " << d << endl;
		}
	}

	cout << set.size() << endl;
}