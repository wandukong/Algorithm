#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	vector<int> priorities = { 1, 1, 9, 1, 1, 1 };
	int location = 0;
	int answer = 0;

	queue<pair<int, int>> q;

	for (int i = 0; i < priorities.size(); i++)
		q.push({ priorities[i],i });

	sort(priorities.begin(), priorities.end());

	int index = priorities.size() - 1;

	while (!q.empty()) {
		if (q.front().first == priorities[index]) {
			answer++;
			index--;
			if (q.front().second == location) break;
		}
		else q.push(q.front());		
		q.pop();	
	}
	printf("%d\n", answer);
	return 0;
}