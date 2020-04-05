#include <bits/stdc++.h>
using namespace std;

// nの約数を全列挙。但し 1 は除外。n 自身は含む。
// ※結果はソートされていない
template<typename T>
vector<T> ListDivisors(T n)
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
	int n;
	cin >> n;

	cout << endl;
	auto list = ListDivisors(n);
	// sort(list.begin(), list.end());

	for (auto &&d : list) {
		cout << d << endl;
	}

	return 0;
}
