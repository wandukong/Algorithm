#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> answer;
vector<string> temp;

int maxValue = 0;

void dfs(string city, vector<vector<string>> tickets, vector<int> check, int cnt) {
	temp.push_back(city);
	if (maxValue < cnt) {
		maxValue = cnt;
		answer = temp;
	}
	for (int i = 0; i < tickets.size(); i++) {
		if (city == tickets[i][0] && !check[i]) {
			check[i] = 1;
			dfs(tickets[i][1], tickets, check, cnt + 1);
			check[i] = 0;
		}
	}
	temp.pop_back();
}

int main() {
	vector<vector<string>> tickets = { {"ICN", "SFO"}, {"ICN", "ATL"}, {"SFO", "ATL"}, {"ATL", "ICN"}, {"ATL","SFO"} };
	vector<int> check(tickets.size());
	sort(tickets.begin(), tickets.end());
	dfs("ICN", tickets, check, 1);

	for (int i = 0; i < answer.size(); i++) 
		printf("%s\n",answer[i].c_str());
	
	return 0;
}