#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool go(vector<int> v, int num, int cnt) {
	int temp = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] - num <= 0)
			temp++;
		else 
			temp = 0;
		if (temp >= cnt)
			return false;
	}
	return true;
}

int main() {

	vector<int> stones = { 2, 4, 5, 3, 2, 1, 4, 2, 5, 1 };
	int k = 3;

	int left = 1, right = 200000000;

	while (left <= right) {
		int mid = (left + right) / 2;
		if (go(stones, mid, k)) {
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	printf("%d\n", left);
	
	return 0;
}