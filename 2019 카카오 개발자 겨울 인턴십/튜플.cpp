#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

using namespace std;


int main() {
	vector<int> answer;
	string s = "{{1,2,3},{2,1},{1,2,4,3},{2}}";

	string temp = "";
	int cnt;
	vector<int> seg;
	vector<pair<int, vector<int>>> v;
	
	for (int i = 1; i < s.length()-1; i++) {

		if (s[i] == '{') cnt = 0;

		else if (48 <= s[i] && s[i] <= 57) {
			temp += s[i];
		}
	
		else {
			if (temp.length() > 0) {
				
				seg.push_back(stoi(temp));
				
				//printf("%d %d\n", cnt, stoi(temp));
				cnt++;
			}
			 temp = "";
		}
		if (s[i] == '}') {
			v.push_back({ cnt, seg });
			seg.clear();
		}
	}

	sort(v.begin(), v.end());

	set<int> res;
	for (int i = 0; i < v.size();  i++) {
		for (int j = 0; j < v[i].second.size(); j++) {
			if (res.find(v[i].second[j]) == res.end()) {
				res.insert(v[i].second[j]);
				answer.push_back(v[i].second[j]);
			}
		}
	}

	for (int i = 0; i < answer.size(); i++)
		printf("%d ", answer[i]);
	
	return 0;
}