#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

bool cmp(string a, string b) {
	return a + b > b + a;
}

int main() {

	vector<int> numbers = { 3, 30, 34, 5, 9 };

	string answer = "";
	vector<string> temp;

	for (int i = 0; i < numbers.size(); i++)
		temp.push_back(to_string(numbers[i]));

	sort(temp.begin(), temp.end(), cmp);
	if (temp.at(0) == "0")
		return 0;

	for (int i = 0; i < temp.size(); i++)
		answer += temp[i].c_str();

	printf("%s", answer.c_str());

	return 0;
}