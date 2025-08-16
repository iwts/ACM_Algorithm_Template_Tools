/*
main函数提供测试数据，按照每行8个素数输出，可以输出前n位的素
数。百度素数表对比即可验证算法正确性
prime函数，将素数根据出现顺序放在数组中，prime_num函数在只计
算素数数量的情况下进行了时间优化（prime函数也能计算数量）
*/

#include<iostream>
#define MAX 233333

using namespace std;

int not_prime[MAX]; // 非素数存放数组，值为1的不是素数，0是素数
int primes[MAX]; // 素数存放数组，按照顺序存放素数

int prime(int n){
	memset(not_prime, 0, sizeof(not_prime));
	memset(primes, 0, sizeof(primes));
	int flag = 1;
	for (int i = 2; i <= n; i++) {
		if (not_prime[i] == 0) { // 默认为0，即默认全部是素数，然后慢慢筛选
			primes[flag++] = i; // i本身一定是素数
			for (int j = i*i; j <= n; j += i) { // 搜索i的所有倍数，全部都不是素数
                /*
                    i*i的时间优化，假设i是6，那么直接从6*6开始筛选，因为6*5、6*4、6*3...已经
                    在之前i=5、4、3...的时候筛选掉了，减少了重复的次数
                */
				not_prime[j] = 1;
			}
		}
	}
	return flag - 1; // 返回值是素数的数量
}

// 将上面i*i的优化应用全局，flag假设了全部数都是素数，然后慢慢减。
// 在纯粹求素数数量的情况下时间优化了
int prime_num(int n){
	memset(not_prime, 0, sizeof(not_prime));
	int flag = n;
	for (int i = 2; i*i <= n; i++) {
		if (not_prime[i] == 0) {
			for (int j = i*i; j <= n; j += i) {
				if (not_prime[j] == 1) continue;
				not_prime[j] = 1;
				flag--;
			}
		}
	}
	return flag - 1;
}

int main(){
	int n;
	while (cin >> n) {
		int number = prime(n);
		int j = 1;
		for (int i = 1; i <= number; i++,j++) {
			cout << primes[i] << " ";
			if (j == 8) {
				cout << endl;
				j = 0;
			}
		}
	}

	system("pause");
	return 0;
}

// 大区间筛法，primes存放区间内素数，prime_num是素数数量
bool is_prime_small[MAX];
bool is_prime[MAX];
LL primes[MAX];
LL prime_num;

LL Max(LL a, LL b) {
	return a > b ? a : b;
}

void interval_sieve(LL a, LL b) {
	memset(is_prime, true, sizeof(is_prime));
	memset(is_prime_small, true, sizeof(is_prime_small));
	for (LL i = 2; i <= (LL)sqrt((double)b); i++) {
		if (is_prime_small[i]) {
			for (LL j = i*i; j <= (LL)sqrt((double)b); j += i) {
				is_prime_small[j] = false;
			}
			for (LL j = Max(2LL, (a + i - 1) / i)*i; j <= b; j += i) {
				is_prime[j - a] = false;
			}
		}
	}
	for (LL i = 0; i <= b - a; i++) {
		if (is_prime[i]) {
			if (i + a == 1) continue;
			primes[prime_num++] = i + a;
		}
	}
}