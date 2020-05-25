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
	vector<int> scoville = { 1, 2, 3, 9, 10, 12 }; 
	int K = 7;
	int answer = 0;

	priority_queue<int, vector<int>,greater<int>> q;

	for (int i = 0; i < scoville.size(); i++) {
		q.push(scoville[i]);
	}
	printf("%d\n", q.top());
	while (q.top() < K && q.size() > 1) {
		int min1 = q.top();
		q.pop();
		int min2 = q.top();
		q.pop();
		if (min1 == 0 && min2 == 0) {
			answer = -1;
			break;
		}
		int mixed = min1 + min2 * 2;
		q.push(mixed);
		answer++;
	}
	if (q.top < K) answer = -1;
	printf("%d\n", answer);
	
	return 0;
}