#include <string>
#include <string.h>
#include <queue>
#include <algorithm>

using namespace std;


int main() {

	vector<int> progresses = { 93, 30, 55, 60, 40, 65 };
	vector<int> speeds = { 1, 30, 5, 10, 60, 7 };

	vector<int> answer;

	queue<int> q;
	
	int curWork = 0;
	int days = 0;

	while (curWork  < progresses.size()) {
		int cnt = 1;
		q.push(progresses[curWork]);

		if ((100 - progresses[curWork]) % speeds[curWork] == 0) days = (100 - progresses[curWork]) / speeds[curWork];
		else days = (100 - progresses[curWork]) / speeds[curWork] + 1;

		curWork++;
		for (int i = curWork; i < progresses.size(); i++) {
			if (speeds[i] * days >= 100 - progresses[i]) {
				cnt++;
				curWork++;
			}
			else break;
		}
		answer.push_back(cnt);
	}
	
	for(int i = 0 ; i < answer.size() ; i++)
		printf("%d\n", answer[i]);

	return 0;
}