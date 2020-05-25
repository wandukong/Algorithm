#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <functional>
#include <string.h>

using namespace std;


int main() {
	int stock = 14;
	vector<int> dates = { 3,5,15 };
	vector<int> supplies = { 20,40,20 };
	int k = 15;

	int answer = 0;
	
	priority_queue<int> q;

	int idx = 0;
	for (int i = 0; i < k; i++) {
		if (i == dates[idx] && idx < dates.size()) {
			q.push(supplies[idx]);
		}
		if (stock == 0) {
			stock += q.top();
			q.pop();
			answer++;
		}
		stock--;
	}

	
	printf("%d\n", answer);
	return 0;
}