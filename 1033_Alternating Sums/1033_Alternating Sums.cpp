#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <string>
#define PQ priority_queue
#define OO 2147483647
#define Max(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((b) & FASTBUFFER | (a) & ~FASTBUFFER))
#define Min(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((a) & FASTBUFFER | (b) & ~FASTBUFFER))
#define Swap(a, b) (a ^= b, b ^= a, a ^= b)

int FASTBUFFER;

using namespace std;

typedef long long ll;

const int mo = 1000000007;

int f[25][505], g[25][505], mi[25], k;
ll l, r;

int calc(ll n, int k) {
	int temp = n % mo;
	int a[22], tot = 0, ans = 0, now = 0;
	if (n == -1LL) {
		return 0;
	}

	if (n == 0) {
		if (k == 0) {
			return 0;
		} else {
			return 0;
		}
	}

	while (n) {
		a[++tot] = n % 10;
		n /= 10;
	}

	for (int i = 1; i < tot; i++) {
		for (int j = 1; j <= 9; j++) {
			(ans += g[i - 1][j - k + 200]) %= mo;
			(ans += (long long)mi[i - 1] * f[i - 1][j - k + 200] % mo * j % mo) %= mo;
		}
	}

	int op = 1, s = 0;
	for (int i = tot; i >= 1; i--) {
		int j;
		if (i == tot) {
			j = 1;
		} else {
			j = 0;
		}

		for (; j < a[i]; j++) {
			(ans += g[i - 1][(s + op * j - k) / op + 200]) %= mo;
			(ans += (long long)mi[i - 1] * f[i - 1][(s + op * j - k) / op + 200] % mo * j % mo) %= mo;
			(ans += (long long)now * f[i - 1][(s + op * j - k) / op + 200] % mo) %= mo;
		}

		s += op * a[i];
		(now += (long long)mi[i - 1] * a[i] % mo) %= mo;
		op *= -1;
	}

	if (s == k) {
		(ans += temp) %= mo;
	}

	return ans;
}

void work() {
	mi[0] = 1;
	for (int i = 1; i <= 19; i++) {
		mi[i] = (long long)mi[i - 1] * 10 % mo;
	}

	f[0][200] = 1;
	for (int i = 0; i <= 9; i++) {
		f[1][i + 200] = 1;
		g[1][i + 200] = i;
	}

	for (int i = 2; i <= 19; i++) {
		for (int j = -100; j <= 100; j++) {
			for (int k = 0; k <= 9; k++) {
				(f[i][j + 200] += f[i - 1][k - j + 200]) %= mo;
				(g[i][j + 200] += g[i - 1][k - j + 200]) %= mo;
				(g[i][j + 200] += (long long)mi[i - 1] * f[i - 1][k - j + 200] % mo * k % mo) %= mo;
			}
		}
	}

	cin >> l >> r >> k;
	int ans = (calc(r, k) - calc(l - 1, k)) % mo;
	while (ans < 0) {
		ans += mo;
	}

	cout << ans << endl;
}

int main() {
	work();
	return 0;
}
