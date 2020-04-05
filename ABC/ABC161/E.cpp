	#include <bits/stdc++.h>
	#define REP(i, n) for (int i = 0; i < (n); ++i)
	#define RREP(i, n) for (int i = (n - 1); 0 <= i; --i)
	using namespace std;
	using ll = long long;
	using P = pair<int, int>;

	int main()
	{
		int N, K, C;
		cin >> N >> K >> C;
		string S;
		cin >> S;

		// 左から K個 貪欲に詰め込んでいく
		vector<int> ls(K, -1);
		int pos = 0;
		REP (i, K) {
			while (S[pos] == 'x') {
				++pos;
			}
			// S[pos] は o
			ls[i] = pos;
			pos += C + 1;
		}
		for (auto &&p : ls) {
			cerr << p << " ";
		}
		cerr << endl;

		// 右から K個 貪欲に詰め込んでいく
		vector<int> rs(K, -1);
		pos = S.size() - 1;
		RREP (i, K) {
			while (S[pos] == 'x') {
				--pos;
			}
			// S[pos] は o
			rs[i] = pos;
			pos -= C + 1;
		}
		for (auto &&p : rs) {
			cerr << p << " ";
		}
		cerr << endl;

		// 同じボール番号が同じところに入るなら
		// それはそこにしかおけないということ
		REP (i, K) {
			if (ls[i] == rs[i]) {
				cout << ls[i] + 1 << endl;
			}
		}
	}