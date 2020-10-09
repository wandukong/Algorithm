#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <functional>
#include <string.h>
#include <deque>

using namespace std;


int main() {
	vector<string> operations = {"I 7", "I 5", "I -5", "D -1"};
	
	vector<int> answer;
	
	deque<int> dq;

	for (int i = 0; i < operations.size(); i++) {
		
		if (operations[i][0] == 'I') {
			string temp = "";
			for (int j = 2; j < operations[i].length(); j++) {
				temp += operations[i][j];
			}
			dq.push_back(atoi(temp.c_str()));
			sort(dq.begin(), dq.end(),greater<int>());
		}
		else if (operations[i][0] == 'D') {
			if (dq.empty()) continue;
			if (operations[i][2] == '1') dq.pop_front();
			else dq.pop_back();
		}
	}

	if (dq.empty()) {
		answer.push_back(0);
		answer.push_back(0);
	}
	else {
		answer.push_back(dq.front());
		answer.push_back(dq.back());
	}
	printf("%d %d\n", answer[0],answer[1]);
	return 0;
}