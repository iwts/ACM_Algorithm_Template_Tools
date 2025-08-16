int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

int lcm(int a,int b){
	int ans = a/gcd(a,b)*b; // 防止a*b溢出
	return ans;
}

int stein(int a, int b) {
	int k = 0;
	while (b > 0) {
		if (a % 2 == 0 && b % 2 == 0) {
			a = a>>1;
			b = b>>1;
			k++;
		}else {
			if (a % 2 == 0) {
				a = a>>1;
			}else {
				if (b % 2 == 0) {
					b = b>>1;
				}else {
					a = (a - b)>>1;
				}
			}
		}
		if (a < b) { // 保证数据一定是a>b
			int temp = b;
			b = a;
			a = temp;
		}
	}
	return a<<k; // 不能a*k
}

// 扩展欧几里德算法
int exgcd(int a,int b,int &x,int &y){
	if(b == 0){
		x = 1;
		y = 0;
		return a;
	}
	int ans = exgcd(b,a%b,x,y);
	int temp = y;
	y = x - (a/b)*y;
	x = temp;
	return ans;
}

// 中国剩余定理
int crt(int a[],int m[],int n){
	int M = 1;
	int ans = 0;
	for(int i = 0;i < n;i++){
		M *= m[i];
	}
	for(int i = 0;i < n;i++){
		int x = 0;
		int y = 0;
		int Mi = M/m[i];
		exgcd(Mi,m[i],x,y);
		ans = (ans + Mi%M * x%M * a[i]%M + M)%M;
	}
	if(ans < 0){
		ans += M;
	}
	return ans;
}

// 快速幂
int Pow(int a,int b){
	int ans = 1;
	int base = a;
	while(b){
		if(b & 1) ans *= base;
		base *= base;
		b >>= 1;
	}
	return ans;
}

// 快速幂取模
int pow_mod(int a,int b,int c){
	int ans = 1;
	int base = a%c;
	while(b){
		if(b & 1) ans = (ans*base)%c;
		base = (base*base)%c;
		b >>= 1;
	}
	return ans;
}

// 等比数列二分求模取和
int pow_sum_mod(int a,int n,int p){
	if(n == 1) return a%p;
	if(n & 1 == 0){
		return (1 + pow_mod(a,2/n,p))*pow_sum_mod(a,2/n,p) % p;
	}else{
		return ((1+pow_mod(a,(n-1)/2,p))*pow_sum_mod(a,(n-1)/2,p) + pow_mod(a,n,p)) % p;
	}
}

// 矩阵快速幂-矩阵结构体，ans是结果矩阵，res是初始矩阵
struct Matrix{
    int m[MAX][MAX];
}ans,res;

int n;

// 矩阵乘法，矩阵a矩阵b，皆为n阶方阵
Matrix matr_mul(Matrix a,Matrix b){
    Matrix temp;
    memset(temp.m,0,sizeof(temp.m));
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            for(int k = 1;k <= n;k++){
                temp.m[i][j] += a.m[i][k] * b.m[k][j];
            }
        }
    }
    return temp;
}

// 矩阵快速幂，N表示N次幂，n表示是n阶方阵
void matr_pow(int N){
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            if(i == j){
                ans.m[i][j] = 1;
            }else{
                ans.m[i][j] = 0;
            }
        }
    }
    while(N){
        if(N & 1 == 1) ans = matr_mul(ans,res);
        res = matr_mul(res,res);
        N >>= 1;
    }
}

// 递归求欧拉函数
int euler(int n){
	int ans = 1;
	for(int i = 2;i*i < n;i++){
		if(n % i == 0){
			n /= i;
			ans *= (i-1);
			while(n % i == 0){
				n /= i;
				ans *= i;
			}
		}
	}
	if(n > 1) ans *= (n-1);
	return ans;
}