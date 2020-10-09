#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

int main() {

	vector<vector<int>> jobs = { {0,10},{4,10},{5,11},{15,2} };
	
	int answer = 0;
	int index = 0, time = 0, sum = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

	sort(jobs.begin(), jobs.end());

	while (index < jobs.size() || !q.empty()) {
		if (index < jobs.size() && time >= jobs[index][0]) {
			q.push({ jobs[index][1],jobs[index][0] });
			index++;
			continue;
		}
		if (!q.empty()) {
			time += q.top().first;
			sum += time - q.top().second;
			q.pop();
		}
		else time = jobs[index][0];
	}
	answer = sum / jobs.size();
	printf("%d\n", answer);
	return 0;
}