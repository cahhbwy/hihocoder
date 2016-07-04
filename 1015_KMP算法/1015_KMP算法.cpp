#include <iostream>
#include <string>
using namespace std;
unsigned int kmp(string source, string mode) {
	int modelength = (int)mode.length();
	int sourcelength = (int)source.length();
	int *next = new int[modelength];
	int i = 0, j = -1;
	next[0] = -1;
	while (i < modelength - 1) {
		if (j == -1 || mode[j] == mode[i]) {
			++i;
			++j;
			next[i] = j;
		} else {
			j = next[j];
		}
	}
	i = 0;
	j = 0;
	int count = 0;
	while (i < sourcelength) {
		while (i < sourcelength && j < modelength) {
			if (j == -1 || source[i] == mode[j]) {
				++i;
				++j;
			} else {
				j = next[j];
			}
		}
		if (j == modelength) {
			++count;
			if (i < sourcelength) {
				if (modelength > 1) {
					--i;
				}
				j = next[j - 1];
				j = (j < 0 ? 0 : j);
			}
		}
	}
	return count;
}
int main(int argc, char** argv) {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string source, mode;
		cin >> mode >> source;
		cout << kmp(source, mode) << endl;
	}
	return 0;
}