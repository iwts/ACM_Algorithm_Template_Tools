#include<iostream>
#include<vector>
#define MAX 2333

using namespace std;

int ans[MAX];

// 纯分解，由小到大输出，返回数量
int solve(int number){
    int times = 0;
    for(int i = 2;i <= sqrt(number);i++){  
        while(number != i){  
            if(number%i == 0){
            	eulur[times++] = i;
                number = number / i;
                if (number % i == 0) {
                    while (number % i == 0) number = number / i;
                    number = number*i;
                }
            }else{
            	break;
            }
        }  
    }  
    ans[times++] = number;
    return times;
}