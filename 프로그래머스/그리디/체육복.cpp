#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <functional>
#include <string.h>

using namespace std;

int lostCheck[31];
int reserveCheck[31];
int check[31];

int main() {
	int n = 5;
	vector<int> lost = { 2,3,4 };
	vector<int> reserve = { 3,4,5 };

	int answer = 0;
	for (int i = 0; i < lost.size(); i++)
		lostCheck[lost[i]] = 1;
	for (int i = 0; i < reserve.size(); i++)
		reserveCheck[reserve[i]] = 1;
	for (int i = 1; i <= n; i++) {
		check[i] = 1;
		if (lostCheck[i]) check[i] = 0;
		if (reserveCheck[i] && !check[i]) {
			check[i] = 1;
			reserveCheck[i] = 0;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (reserveCheck[i] && !check[i - 1] && i - 1 >= 1) {
			check[i - 1] = 1;
			reserveCheck[i] = 0;
		}
		else if (reserveCheck[i] && !check[i + 1] && i + 1 <= n) {
			check[i + 1] = 1;
			reserveCheck[i] = 0;
		}
	}
	for (int i = 1; i <= n; i++)
		if (check[i]) answer++;
	printf("%d\n", answer);
	return 0;
}