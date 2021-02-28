#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <math.h>

using namespace std;

int answer = 51;

bool cmp(string cur, string tar) {
	int cnt = 0;
	for (int i = 0; i < cur.size(); i++) 
		if (cur[i] != tar[i]) cnt++;
	if (cnt == 1) return true;
	else return false;
}

void dfs(vector<string> words, vector<int> check, string cur, string tar, int cnt) {
	if (cur == tar && answer > cnt) {
		answer = cnt;
		return;
	}
	for (int i = 0; i < words.size(); i++) {
		if (!check[i] && cmp(cur, words[i])) {
			check[i] = 1;
			dfs(words, check, words[i], tar, cnt + 1);
			check[i] = 0;
		}
	}
}

int main() {
	string begin = "hit";
	string target = "cog";
	vector<string> words = {"hot", "dot", "dog", "lot", "log", "cog"};
	int size = words.size();
	vector<int> check(size);

	dfs(words, check, begin, target, 0);
	if (answer == 51) answer = 0;
	printf("%d", answer);

	return 0;
}