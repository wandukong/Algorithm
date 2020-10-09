#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
	vector<int> answer;

	int brown = 10, yellow = 2;
	int sum = brown + yellow;

	for (int i = 2; i < sqrt(sum); i++) {
		if (sum%i == 0) {
			if (sum / i * 2 + (i - 2) * 2 == brown) {
				answer.push_back(i);
				answer.push_back(sum/i);
			}
		}
	}

	printf("%d %d", answer[0], answer[1]);
	

	return 0;
}