#include<iostream>
#include<string>
#include<stdio.h>
#define TIME std::ios::sync_with_stdio(false)

// 注意由于要插入'#'，所以没有使用string，而是全局设置了字符串s与p数组
const int MAX=110000+10;  
char s[MAX*2];  
int p[MAX*2]; 

using namespace std;

int manachar(){
	memset(p,0,sizeof(p));
    int len = strlen(s);
    int id = 0;
    int maxlen = 0;
    // 防止偶数串，字符间穿插'#'，但s[0]为'*'
    for(int i = len;i >= 0;i--){
        s[i+i+2] = s[i];
        s[i+i+1] = '#';
    }
    s[0] = '*';
    // manachar核心代码，O(n)复杂度下补充p数组，并求得maxlen
    for(int i = 2;i < 2*len + 1;i++){
        if(p[id] + id > i){
            p[i] = p[2*id - i] < p[id]+id-i ? p[2*id - i] : p[id]+id-i;
        }else{
            p[i] = 1;
        }
        while(s[i - p[i]] == s[i + p[i]]){
            p[i]++;
        }
        if(id + p[id] < i + p[i]){
            id = i;
        }
        if(maxlen < p[i]){
            maxlen = p[i];
        }
    }
    // 得到的maxlen是半径长度，包括了插入的'#'
    return maxlen-1;
}

int main() {
    TIME;
    while (scanf("%s",s) != EOF) {
        int ans = manachar();
        cout << ans << endl;
    }

    system("pause");
    return 0;
}