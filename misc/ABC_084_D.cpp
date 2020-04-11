#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define RREP(i, n) for (int i = (n - 1); 0 <= i; --i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

namespace My
{
long seedPrimes[] = {
    /*1,2,3,4, 5, 6, 7  8, 9,10,11,12,13,14,15,*/
    2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37, 41,
    43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

/// <summary>
/// 素因数分解 ※1は返さない
/// </summary>
template <typename T>
static vector<T> Factoring(T n)
{
	vector<T> factors;
	while (1 < n) {
		T factor = GetFactor(n);
		factors.emplace_back(factor);
		n /= factor;
	}
}

template <typename T>
static long GetFactor(T n, int seed = 1)
{
	if (n % 2 == 0) return 2;
	if (IsPrime(n)) return n;
	T x = 2;
	T y = 2;
	T d = 1;
	T count = 0;
	while (d == 1) {
		count++;
		x = f(x, n, seed);
		y = f(f(y, n, seed), n, seed);
		d = Gcd(std::abs(x - y), n);
	}
	if (d == n)
		// 見つからなかった、乱数発生のシードを変えて再挑戦。
		return GetFactor(n, seed + 1);
	// 素数でない可能性もあるので、再度呼び出す
	return GetFactor(d);
}
template <typename T>
static T f(T x, T n, int seed)
{
	return (seedPrimes[seed % 6] * x + seed) % n;
}
template <typename T>
static T Gcd(T a, T b)
{
	if (a < b) return Gcd(b, a); // 引数を入替えて自分を呼び出す
	if (b == 0) return a;
	T d = 0;
	do {
		d = a % b;
		a = b;
		b = d;
	} while (d != 0);
	return a;
}

template <typename T>
static bool IsPrimeBruteforce(T num)
{
	if (num == 1) return false;
	if (num != 2 && num % 2 == 0) return false;
	if (num != 3 && num % 3 == 0) return false;
	if (num != 5 && num % 5 == 0) return false;
	T inc = 0;
	while (true) {
		for (int i = 3; i < 11; i++) {
			// 30m+2, 30m+3, 30m+4, 30m+5, 30m+6、30m+8、30m+9、30m+12...
			// は割る必要はない。
			auto primeCandidte = seedPrimes[i] + inc;
			if (std::sqrt(num) < primeCandidte) return true;
			if (num % (primeCandidte) == 0) return false;
		}
		inc += 30;
	}
}

template <typename T>
static int GetWitnessCnt(T num)
{
	if (num < 2047) return 1;
	if (num < 1373653) return 2;
	if (num < 25326001) return 3;
	if (num < 3215031751) return 4;
	if (num < 2152302898747) return 5;
	if (num < 3474749660383) return 6;
	if (num < 341550071728321) return 7;
	if (num < 3825123056546413051) return 9;
	return 12;
}

/**
 * 冪剰余を返す。
 * C ≡ b^e ( mod m)
 *
 * @param [in] b 基底
 * @param [in] e 冪指数
 * @param [in] m m を法とした b の e 冪剰余
 * @return 冪剰余を返す。
 */
template <typename IntType>
IntType ModPow(IntType b, IntType e, IntType m)
{

	IntType result = 1;

	while (e > 0) {
		if ((e & 1) == 1) result = (result * b) % m;
		e >>= 1;
		b = (b * b) % m;
	}

	return result;
}
template <typename T>
static bool MillarRabin(T num, T s, T d, long witness)
{
	T x = ModPow((T)witness, d, num);
	if (x == 1) return true;
	for (T r = 0; r < s; r++) {
		if (x == num - 1) return true;
		auto divt = std::div(x * x, num);
		x = divt.rem;
	}
	return false;
}

template <typename T>
static bool IsPrimeMillarRabin(T num)
{
	if (num <= 1) return false;
	if ((num & 1) == 0) return num == 2;

	if (num < 100 && std::binary_search(std::begin(seedPrimes),
	                                    std::end(seedPrimes), (long)num))
		return true;

	auto witnessCnt = GetWitnessCnt(num);

	T d = num - 1;
	T s = 0;
	while ((d & 1) == 0) {
		s++;
		d >>= 1;
	}
	for (int i = 0; i < witnessCnt; i++) {
		auto w = seedPrimes[i];
		if (!MillarRabin(num, s, d, w)) return false;
	}
	return true;
}

/// <summary>
/// 素数判定 【高速版】
/// </summary>
template <typename T>
bool IsPrime(T num)
{
	if (num == 1) return false;
	if (std::binary_search(std::begin(seedPrimes), std::end(seedPrimes), num))
		return true;

	for (auto &&p : seedPrimes) {
		if (num % p == 0) return false;
	}

	return (num < 2000000) ? IsPrimeBruteforce(num) : IsPrimeMillarRabin(num);
}

// [2, num] の素数列挙
// エラトステネスの篩（ふるい）
template <typename T>
std::vector<T> Eratosthenes(const T num)
{
	std::vector<bool> siftPrimes(num + 1, true);

	std::vector<T> primes;
	for (T i = 2; i <= num; i++) {
		if (siftPrimes[i]) {
			for (T j = 2 * i; j <= num; j += i) {
				siftPrimes[j] = false;
			}
			primes.emplace_back(i);
		}
	}
	return primes;
}

class Solver
{
  public:
	Solver() {}
	void Solve(istream &cin, ostream &cout)
	{
		int Q;
		cin >> Q;

		// 1-10^5 の素数列を予め計算
		auto primes = Eratosthenes(100000);
		// 1-10^5 までの 2017数 の数を累積和配列として持っておく
		array<int, 100005> sum2017;
		int cnt2017 = 0;
		int preP = 0;
		for (auto &&p : primes) {
			if (IsPrime((p + 1) / 2)){
				for (int i = preP; i < p+1; i++){
					sum2017[i] = cnt2017;
				}
				++cnt2017;
				preP = p;
			}
		}
		for (int i = preP; i < sum2017.size(); i++) {
			sum2017[i] = cnt2017;
		}
		// DumpArray(sum2017);

		REP(i, Q){
			int L, R;
			cin >> L >> R;

			// (Rまでの2017数) - (L-1 までの 2017数)
			cout << sum2017[R] - sum2017[L - 1] << endl;
		}
	}

	template <typename ArrayT>
	static void DumpArray(const ArrayT &arr)
	{
	#if defined(HOME)
		for (auto it = std::begin(arr); it != std::end(arr); ++it) {
			cerr << *it << " ";
		}
		cerr << endl;
	#endif
	};
	template <typename T>
	static bool ChMin(T &target, T value)
	{
		if (value < target) {
			target = value;
			return true;
		} else {
			return false;
		}
	}
	template <typename T>
	static bool ChMax(T &target, T value)
	{
		if (target < value) {
			target = value;
			return true;
		} else {
			return false;
		}
	}
};
} // namespace MySpace

#if !defined(BOOST_TEST_MODULE)
#if !defined(GTEST_INCLUDE_GTEST_GTEST_H_)
int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	My::Solver solver;
	solver.Solve(std::cin, std::cout);

	return 0;
}
#endif
#endif
