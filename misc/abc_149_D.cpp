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

class Solver
{
  public:
	Solver() {}
	void Solve(istream &cin, ostream &cout)
	{
		int N, K, R, S, P;
		string T;
		cin >> N >> K >> R >> S >> P >> T;

		char res[N];

		auto calc = [&](char c) {
			switch (c) {
			case 'r':
				return R;
			case 's':
			    return S;
			case 'p':
			default:
				return P;
			}
		};

		ll ans = 0;
		REP (i, N) {
			if (i < K) {
				res[i] = Win(T[i]);
				ans += calc(res[i]);
			} else {
				auto w = Win(T[i]);
				if (res[i - K] == w){
					res[i] = '0';
				}else{
					res[i] = w;
					ans += calc(res[i]);
				}
			}
		}

		cout << ans << endl;
	}

	char Win(char c)
	{
		if (c == 'r') {
			return 'p';
		} else if (c == 's') {
			return 'r';
		} else {
			return 's';
		}
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
