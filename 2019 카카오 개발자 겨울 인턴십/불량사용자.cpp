#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

using namespace std;

bool check[8];
set<string> s;

void dfs(vector<string> user_id, vector<string> banned_id, int banned_index) {

	if (banned_index >= banned_id.size()) {
		string temp = "";
		for (int i = 0; i < user_id.size(); i++) 
			if (check[i]) {
				temp += i;
			}
		s.insert(temp);
		return;
	}

	for (int i = 0; i < user_id.size(); i++) {
		int j = 0;
		if (user_id[i].length() == banned_id[banned_index].length() && !check[i]) {
			for (; j < banned_id[banned_index].length(); j++) {
				if (banned_id[banned_index][j] == '*')
					continue;
				if (user_id[i][j] != banned_id[banned_index][j]) 
					break;
			}
			if (j == banned_id[banned_index].length()) {
				check[i] = true;
				dfs(user_id, banned_id, banned_index + 1);
				check[i] = false;
			}
		}
	}
}

int main() {

	vector<string> user_id = { "frodo", "fradi", "crodo", "abc123", "frodoc" }; // "frodo", "fradi", "crodo", "abc123", "frodoc"
	vector<string> banned_id = { "fr*d*", "*rodo", "******", "******"};

	dfs(user_id, banned_id, 0);
	printf("%d", s.size());
	return 0;
}