/*
LIS的核心算法在函数lis，可以看出时间复杂度是O(n^2)
*/

#include<iostream>
#define MAX 2333

using namespace std;

int dp[MAX];
int a[MAX];

int main() {
	int N;
	cin >> N;
	for(int i = 1;i <= N;i++){
		cin >> a[i];
		dp[i] = 1;
	}
	for(int i = 2;i <= N;i++){
		for(int j = 1;j < i;j++){
			if(a[i] > a[j]){
				dp[i] = dp[i] > dp[j]+1 ? dp[i] : dp[j]+1;
			}
		}
	}
	int ans = 0;
	for(int i = 1;i <= N;i++){
		ans = ans > dp[i] ? ans : dp[i];
	}
	cout << ans << endl;

	system("pause");
	return 0;
}
