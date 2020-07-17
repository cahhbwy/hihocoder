#include <stdio.h>
#include <string.h>
char s[1000000] = { 255 };
int main(int argc, char** argv) {
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