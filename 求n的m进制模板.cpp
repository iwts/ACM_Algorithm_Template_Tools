#include <iostream>
#include <string>
#include <stack>

using namespace std;

void transform(int n,int m){
	stack<int> st;
	if(n < 0){
		n = -n;
		cout << "-";
	}
	while(n){
		st.push(n%m);
		n /= m;
	}
	while(!st.empty()){
		int elem = st.top();
		st.pop();
		if(elem >= 10){
			cout << (char)(elem-10+'A');
		}else{
			cout << elem;
		}
	}
}

int main(){
	int m,n;
	cin >> n >> m;
	transform(n,m);

	system("pause");
	return 0;
}