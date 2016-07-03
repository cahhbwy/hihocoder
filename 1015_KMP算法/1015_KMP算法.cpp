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
			if (mode[j] != mode[i]) {
				next[i] = j;
			} else {
				next[i] = next[j];
			}
		} else {
			j = next[j];
		}
	}
	int pos = 0;
	int count = 0;
	while (true) {
		i = pos;
		j = 0;
		while (i < sourcelength && j < modelength) {
			if (j == -1 || source[i] == mode[j]) {
				++i;
				++j;
			} else {
				j = next[j];
			}
		}
		if (j >= (int)modelength) {
			++count;
			pos = i - modelength + 2;
			//			return i - mode.size() + 1;
			if (pos > sourcelength)
				break;
		} else {
			break;
			//			return -1;
		}
	}
	return count;
}
int main(int argc, char** argv) {
	int n;
	cin >> n;
	string *source = new string[n];
	string *mode = new string[n];
	for (int i = 0; i < n; ++i) {
		cin >> mode[i];
		cin >> source[i];
	}
	for (int i = 0; i < n; ++i) {
		cout << kmp(source[i], mode[i]) << endl;
	}
	return 0;
}