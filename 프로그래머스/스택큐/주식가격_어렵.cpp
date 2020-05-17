#include <string>
#include <vector>
#include <stack>

using namespace std;

int main() {
	vector<int> prices = { 1, 2, 3, 2, 3 };

	int size = prices.size();
	vector<int> answer(size);
	stack<int> st;
	for (int i = 0; i < size; i++) {
		while (!st.empty() && prices[st.top()] > prices[i]) {
			answer[st.top()] = i - st.top();
			st.pop();
		}
		st.push(i);
	}
	while (!st.empty()) {
		answer[st.top()] = size - st.top() - 1;
		st.pop();
	}
	for(int i = 0 ; i < answer.size() ; i++)
		printf("%d\n", answer[i]);
	return 0;
}