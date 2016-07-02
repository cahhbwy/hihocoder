#include <iostream>
#include <vector>

using namespace std;

typedef struct Trie{
	char c;
	int count;
	vector<struct Trie *> child;
}Trie;

Trie *root;
void initial(){
	root = new Trie;
	root->c = 0;
	root->count = 0;
}
void insertTrie(string s){
	Trie *p = root, *np;
	bool create = false;
	unsigned int i, j;
	char c;
	for (i = 0; i < s.length(); ++i){
		c = s[i];
		for (j = 0; j < p->child.size(); ++j){
			np = p->child[j];
			if (c == np->c){
				p->count++;
				p = np;
				j = 0xffffffff;
				break;
			}
		}
		if (j == p->child.size()){
			create = true;
			break;
		}
	}
	p->count++;
	if (create){
		while (i < s.length()){
			Trie* t = new Trie;
			t->c = s[i];
			t->count = 1;
			p->child.push_back(t);
			p = t;
			++i;
		}
	}
}
int countPrefix(string s){
	Trie *p = root, *np;
	unsigned int i, j;
	char c;
	for (i = 0; i < s.length(); ++i){
		c = s[i];
		for (j = 0; j < p->child.size(); ++j){
			np = p->child[j];
			if (c == np->c){
				p = np;
				j = 0xffffffff;
				break;
			}
		}
		if (j == p->child.size()){
			return 0;
		}
	}
	return p->count;
}
int main(int argc, char** argv){
	initial();
	int n;
	cin >> n;
	while (n-- > 0){
		char s[10];
		cin >> s;
		insertTrie(s);
	}
	int m;
	cin >> m;
	int *count = new int[m];
	for (int i = 0; i < m; ++i){
		char s[10];
		cin >> s;
		count[i] = countPrefix(s);
	}
	for (int i = 0; i < m; ++i){
		cout << count[i] << endl;
	}
	return 0;
}