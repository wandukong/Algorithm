#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>

using namespace std;


int main() {
	string s = "abcabcabcabcdededededede";

	int answer = s.size();

	for (int i = 1; i <= s.size() / 2; i++) { // 반복길이
		int tempNum = s.size();
		int cnt = 1, sum = 0;
		bool chk = false;
		string temp = s.substr(0, i);
		string target, compare;
		string str = "";
		for (int j = i; j < s.size(); j += i) {
			target = s.substr(j, i);
			if (temp == target)			
				cnt++;
			else {
				if (cnt == 1){
					str += temp;
					temp = target;
				}
				else {
					str = str + to_string(cnt) + temp;
					temp = target;
					cnt = 1;
				}
			}
			if (j + i >= s.size()) {
				if (cnt != 1) 
					str = str + to_string(cnt) + temp;
				else 
					str = str + s.substr(j);
			}
		}
		printf("%d %s %d\n",i, str.c_str(), str.size());
		answer = answer > str.size() ? str.size() : answer;
	}
	return 0;
}