#include<iostream>
#include<string>
#define MAX 110

using namespace std;

void function(string s,string t){
	int n = s.size();
	int m = t.size();
	for(int i = 0;i <= m-n;i++){
		bool judge = true;
		for(int j = 0;j < n;j++){
			if(s[j] != t[i+j]){
				judge = false;
				break;
			}
		}
		if(judge){
			cout << i << endl;
		}
	}
}

int main() {
	// s表示模板字符串，t表示匹配字符串
	string s,t;
	cin >> s >> t;
	function(s,t);
	
	system("pause");
	return 0;
}