#include <string>
#include <string.h>
#include <queue>
#include <algorithm>

using namespace std;


int main() {

	int bridge_length = 2;
	int weight = 10;
	vector<int> truck_weights = { 7,4,5,6 };

	queue<int> q;
	int answer = 0;
	int curWeight = 0;
	int truck = 0;

	while (true) {
		answer++;

		if (q.size() == bridge_length) {
			curWeight -= q.front();
			q.pop();
		}
		if (curWeight + truck_weights[truck] <= weight) {

			if (truck == truck_weights.size() - 1) {
				answer += bridge_length;
				break;
			}
			q.push(truck_weights[truck]);
			curWeight += truck_weights[truck];
			truck++;
		}
		else {
			q.push(0);
		}
	}


	printf("%d\n",answer);

	return 0;
}