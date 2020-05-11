#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main() {

	vector<int> heights = { 6,9,5,7,4 };
	vector <int> answer;

	stack<int> s;

	for (int i = heights.size() - 1; i >= 0; i--) {
		bool check = false;
		for (int j = i - 1;j >= 0; j--) {
			if (heights[j] > heights[i]) {
				s.push(j+1);
				check = true;
				break;
			}
		}
		if (!check) {
			s.push(0);	
		}
	}

	while (!s.empty()) {
		answer.push_back(s.top());
		s.pop();
	}

	for (int i = 0; i < answer.size(); i++) {
		printf("%d\n", answer[i]);
	}

	return 0;
}