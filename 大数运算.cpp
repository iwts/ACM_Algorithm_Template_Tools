#include<iostream>
#include<string>
#define MAX 110000

using namespace std;

string add(string s1, string s2) {
	string s;
	int len1, len2;
	len1 = s1.size() - 1;
	len2 = s2.size() - 1;
	int flag = 0; // flag记录是否进位
	// 共有部分进行加法计算
	while (len1 > -1 && len2 > -1) {
		int sum = flag + (s1[len1--] - '0') + (s2[len2--] - '0');
		s += char((sum) % 10 + '0'); // 这里是拼接字符
		flag = sum / 10;
	}
	// 看是否有字符串比较长，直接进行拼接
	while (len1 > -1) {
		int sum = flag + (s1[len1--] - '0');
		s += char((sum) % 10 + '0');
		flag = sum / 10;
	}
	while (len2 > -1) {
		int sum = flag + (s2[len2--] - '0');
		s += char((sum) % 10 + '0');
		flag = sum / 10;
	}
	// 999+1这种情况会出现，最后一次进位
	if (flag) {
		s += char('0' + flag);
	}
	/*
		之前模拟的时候都是得到的新位直接加在字符串后面，所以需要反转
		利用size/2，前后调换，奇数正好中间的数不变，偶数正好全部交换
	*/
	for (int i = 0; i < s.size() / 2; i++) {
		char temp = s[i];
		s[i] = s[s.size() - i - 1];
		s[s.size() - i - 1] = temp;
	}
	return s;
}

string sub(string s1, string s2) {
	// 保证s1是减数
	if (s1 == s2) {
		return "0";
	}
	if (s1.size() < s2.size()) {
		string temp = s1;
		s1 = s2;
		s2 = temp;
	}
	if (s1.size() == s2.size() && s1 < s2) {
		string temp = s1;
		s1 = s2;
		s2 = temp;
	}
	string s;
	int len1, len2;
	len1 = s1.size() - 1;
	len2 = s2.size() - 1;
	int flag = 0;
	while (len1 > -1 && len2 > -1) {
		int sum;
		if (s1[len1] - '0' - flag >= s2[len2] - '0') {
			sum = s1[len1] - '0' - flag - s2[len2] - '0';
		}else {
			sum = 10 + (s1[len1] - '0') - flag - (s2[len2] - '0');
			flag = 1;
		}
		s += char(sum + '0');
		len1--;
		len2--;
	}
	// 因为控制了s1是减数，所以只用考虑s1就可以了
	while (len1 > -1) {
		int sum;
		if (s1[len1] - '0' - flag < 0) {
			sum = 10 - s1[len1] - '0' - flag;
			flag = 1;
		}else {
			sum = s1[len1] - '0' - flag;
		}
		s += char(sum + '0');
		len1--;
	}
	// 将前导的0给去掉，因为s是倒序，所以从后往前遍历
	flag = 0;
	for (int i = s.size() - 1; i >= 0; i--) {
		if (s[i] != '0') {
			flag = i;
			break;
		}
	}
	string s_temp;
	for (int i = flag; i >= 0; i--) {
		s_temp += s[i];
	}
	return s_temp;
}

string mul(string s1, string s2) {
	stringstream ss;
	ss << s1;
	int s1_num;
	ss >> s1_num;
	ss.clear();
	int len = s2.size();
	string s;
	int i = len - 1;
	int k = 0;
	for (; i >= 0; i--, k++) {
		int num = (int)s1_num*(s2[i] - '0');
		ss << num;
		string add_num;
		ss >> add_num;
		ss.clear();
		for (int j = 0; j < k; j++) {
			add_num += "0";
		}
		s = add(s, add_num);
	}
	return s;
}

string NN(string s) {
	if (s == "0") {
		return "1";
	}
	if (s == "1") {
		return "1";
	}
	return mul(s, NN(sub(s,"1")));
}

int main() {
	string a, b;
	cin >> a >> b;
	cout << sub(a, b);

	
	system("pause");
	return 0;
}