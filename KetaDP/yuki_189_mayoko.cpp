#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

ll dp[2][222][2000][2];
const ll MOD = 1e9 + 9;

void makeDP(const string &s, int a)
{
	int n = s.size();
	dp[a][0][0][1] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2000; j++) {
			for (int k = 0; k < 2; k++) {
				if (k == 0) {
					for (int b = 0; b < 10; b++) {
						dp[a][i + 1][j + b][0] += dp[a][i][j][0];
						dp[a][i + 1][j + b][0] %= MOD;
					}
				} else {
					int tmp = s[i] - '0';
					for (int b = 0; b < tmp; b++) {
						dp[a][i + 1][j + b][0] += dp[a][i][j][1];
						dp[a][i + 1][j + b][0] %= MOD;
					}
					dp[a][i + 1][j + tmp][1] += dp[a][i][j][1];
					dp[a][i + 1][j + tmp][1] %= MOD;
				}
			}
		}
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	string s, t;
	cin >> s >> t;
	makeDP(s, 0);
	makeDP(t, 1);
	int n = s.size(), m = t.size();

	string filename = "test.txt";
	ofstream f;
	f.open(filename, ios::out);

	ll ans = 0;
	for (int i = 1; i < 2000; i++) {
		ll p = dp[0][n][i][0] + dp[0][n][i][1];
		ll q = dp[1][m][i][0] + dp[1][m][i][1];
		ans += p * q;
		ans %= MOD;
		f << i << ": " << ans << ": " << p * q << endl;
	}
	cout << ans << endl;
	return 0;
}