#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<sstream>

using namespace std;

struct trie {
	int flag;
	trie *next[26];
}*head;

trie *gettrie() {
	trie *temp = new trie;
	for (int i = 0; i < 27; i++) {
		temp->next[i] = NULL;
	}
	temp->flag = -1;
	return temp;
}

void gettree(trie *p, string s, int num) {
	int temp;
	int len = s.size();
	for (int i = 0; i < len; i++) {
		temp = s[i] - 'a';
		if (p->next[temp] == NULL) {
			p->next[temp] = gettrie();
		}
		p = p->next[temp];
	}
	p->flag = num;
}

int Find(trie *p, string s) {
	int len = s.size();
	for (int i = 0; i < len; i++) {
		int temp = s[i] - 'a';
		if (p->next[temp] == NULL) {
			return -1;
		}
		p = p->next[temp];
	}
	return p->flag;
}

int main() {
	trie *head = gettrie();
	int num = 0;
	string s, s1, s2;
	map<int, string> m;
	while (true) {
		getline(cin,s);
		stringstream ss(s);
		if (s[0] == '\0') break;
		ss >> s1 >> s2;
		m.insert(pair<int, string>(num, s1));
		gettree(head, s2, num);
		num++;
	}
	while (getline(cin,s)) {
		if (s[0] == '\0') break;
		int judge = Find(head, s);
		if (judge == -1) {
			cout << "eh" << endl;
		}
		else {
			cout << m.find(judge)->second << endl;
		}
	}

	system("pause");
	return 0;
}