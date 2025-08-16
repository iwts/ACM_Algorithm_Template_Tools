// 附题，poj 1222  一定要注意for循环的数据范围，根据实际矩阵大小要会调整，不能错


#include<iostream>
#include<memory>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#define MAX 500005
#define LL long long
#define TIME std::ios::sync_with_stdio(false);

using namespace std;

char oriLights[5];
char lights[5];
char result[5];

int getBit(char c,int i){
	return (c >> i) & 1;
}

// 修改该行的i位为v,1 << i，直接确定到i位置
void setBit(char &c,int i,int v){
	if(v){ // v为1，利用或运算，无论原来是多少肯定为1，其他位不影响
		c |= (1 << i);
	}else{ // v为0，先定位，取反，该位置为0其他位1，与运算该位置一定为0，其他位不影响
		c &= ~(1 << i);
	}
}

// 翻转，确定位置后，该位与1异或，那么0则变为1,1则变为0
void flipBit(char &c,int i){
	c ^= (1 << i);
}

void ouputResult(int t,char result[]){
	cout << "PUZZLE #" << t << endl;
	for(int i = 0;i < 5;i++){ 
		for(int j = 0;j < 6;j++){
			cout << getBit(result[i],j);
			if(j < 5){
				cout << " ";
			}
		}
		cout << endl;
	}
}

// 如果需要最小翻转次数，可以用该函数进行比较
void change(int step,char result[]){
    if(step < min_step){
        for(int i = 0;i < M;i++){
            ansLights[i] = result[i];
        }
        min_step = step;
    }
}

int main() {
	TIME
	int T;
	cin >> T;
	for(int t = 1;t <= T;t++){
		// 读取所有数据
		for(int i = 0;i < 5;i++){
			for(int j = 0;j < 6;j++){
				int s;
				cin >> s;
				setBit(oriLights[i],j,s);
			}
		}
		// 开始枚举
		for(int n = 0;n < 64;n++){
			int switchs = n;
			memcpy(lights,oriLights,sizeof(oriLights)); // 复制一个副本
			for(int i = 0;i < 5;i++){
				result[i] = switchs; // 每行循环开始的时候switchs该行已经确定了
				// 下面的操作是修改已经确定的行，将按下开关的左右与本身进行翻转
				for(int j = 0;j < 6;j++){
					if(getBit(switchs,j)){  // 一次反转，如果记录反转次数可以从这里开始
						if(j > 0){
							flipBit(lights[i],j-1);
						}
						flipBit(lights[i],j);
						if(j < 5){  // 列数减一
							flipBit(lights[i],j+1);
						}
					}
				}
				// i行本来就确定，根据i行修改i+1行数据，将按下的开关的下一行进行修改
				if(i < 4){ // 行数减一
					lights[i+1] ^= switchs;
				}
				// i+1行按键确定，存到switchs中，再次进入循环
				switchs = lights[i];
			}
			// 判断枚举正确的条件，如果最后一行为0，则正确
			if(lights[4] == 0){
				ouputResult(t,result);
				break;
			}
		}
	}

	system("pause");
	return 0;
}