#include <stdio.h>
int main(int argc, char** argv) {
	unsigned long long l, i, r, sum = 0;
	int k, t, j;
	char str[20];
	scanf("%llu%llu%d", &l, &r, &k);
	i = l;
	while (i <= r) {
		sprintf(str, "%llu", i);
		t = 0;
		for (j = 0; str[j]; ++j) {
			t += (j & 0x01 ? '0' - str[j] : str[j] - '0');
		}
		if (t == k) {
			sum += i;
		}
		++i;
	}
	printf("%llu\n", sum);
	return 0;
}