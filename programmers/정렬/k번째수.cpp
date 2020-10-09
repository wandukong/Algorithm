#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main() {

	vector<int> array = { 1, 5, 2, 6, 3, 7, 4 };
	vector<vector<int>> commands = {{ 2, 5, 3 },{4, 4, 1 }, { 1, 7, 3}};
	vector <int> answer;

	for (int i = 0; i < commands.size(); i++) {
		int start = commands[i][0];
		int end = commands[i][1];

		vector<int> temp;

		for (int j = start - 1; j < end; j++)
			temp.push_back(array[j]);

		sort(temp.begin(), temp.end());
		answer.push_back(temp[commands[i][2] - 1]);
	}

	for (int i = 0; i < answer.size(); i++) {
		printf("%d\n", answer[i]);
	}

	return 0;
}