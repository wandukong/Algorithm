#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
	vector<int> answers = { 1,2,3,4,5 };

	vector<int> answer;

	int p1[5] = { 1,2,3,4,5 };
	int p2[8] = { 2, 1, 2, 3, 2, 4, 2, 5 };
	int p3[10] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

	int cnt1 = 0, cnt2 = 0, cnt3 = 0, m = 0;

	for (int i = 0; i < answers.size(); i++) {
		if (answers[i] == p1[i % 5]) cnt1++;
		if (answers[i] == p2[i % 8]) cnt2++;
		if (answers[i] == p3[i % 10]) cnt3++;
	}
	m = max(cnt1, max(cnt2, cnt3));

	if (cnt1 == m) answer.push_back(1);
	if (cnt2 == m) answer.push_back(2);
	if (cnt3 == m) answer.push_back(3);

	for (int i = 0; i < answer.size(); i++) 
		printf("%d\n", answer[i]);
	

	return 0;
}