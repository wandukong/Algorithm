#include <string>
#include <vector>
#include <queue>

using namespace std;

int main() {
	string arrangement = "()(((()())(())()))(())";

	int answer = 0;
	int cnt = 0;

	for (int i = 0; i < arrangement.length(); i++) {
		if (arrangement[i] == '(') {
			cnt++;
		}
		else if (arrangement[i] == ')') {
			cnt--;
			if (arrangement[i - 1] == '(') {
				answer += cnt;
			}
			else {
				answer++;
			}
		}
	}
	printf("%d\n", answer);
	return answer;
}