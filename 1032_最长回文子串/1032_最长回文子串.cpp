#include <stdio.h>
#include <string.h>
char s[1000000] = { 255 };
int main(int argc, char**argv) {
	int i, n, m, t;
	char *p, *q;
	scanf("%d\n", &n);
	while (n-- > 0) {
		scanf("%s", s + 1);
		m = 0;
		for (i = 1; i < strlen(s + 1);) {
			p = q = s + i;
			while (*p == *(++q));
			i = q - s;
			--q;
			t = q - p + 1;
			while (*(--p) == *(++q)) {
				t += 2;
			}
			m = m < t ? t : m;
		}
		printf("%d\n", m);
	}
	return 0;
}
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// char s[2000000];
// int f[2000000];
// int main(int argc, char** argv) {
// 	int n, i, j, minfi, maxf;
// 	scanf("%d", &n);
// 	while (n-- > 0) {
// 		scanf("%s", s);
// 		int length = strlen(s);
// 		i = length - 1;
// 		length = length * 2 + 1;
// 		j = length - 1;
// 		s[j + 1] = 0;
// 		while (i >= 0) {
// 			s[j--] = '_';
// 			s[j--] = s[i--];
// 		}
// 		s[0] = '_';
// 		f[0] = 1;
// 		for (i = 1; i < length; ++i) {
// 			minfi = f[i] > 1 ? f[i] : 1;
// 			minfi /= 2;
// 			while (i + minfi < length&&i - minfi >= 0 && s[i + minfi] == s[i - minfi]) {
// 				++minfi;
// 			}
// 			f[i] = 2 * minfi - 1;
// 			for (j = 1; j <= f[i] / 2; ++j) {
// 				if (f[i - j] + j * 2 <= f[i]) {
// 					f[i + j] = f[i + j]>f[i - j] ? f[i + j] : f[i - j];
// 				}
// 			}
// 		}
// 		i = 0;
// 		while (i < length) {
// 			++i;
// 			f[i] /= 2;
// 		}
// 		maxf = 1;
// 		for (j = 0; j < length; ++j) {
// 			maxf = maxf > f[j] ? maxf : f[j];
// 			f[j] = 1;
// 		}
// 		printf("%d\n", maxf);
// 	}
// 	return 0;
// }