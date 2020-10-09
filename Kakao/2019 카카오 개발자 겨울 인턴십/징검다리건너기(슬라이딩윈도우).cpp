#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main() {

	vector<int> stones = { 2, 4, 5, 3, 2, 1, 4, 2, 5, 1 };
	int k = 3;

	int answer = 200000001;

	if (stones[0] > stones[stones.size() - 1]) {
		for (int i = stones.size()-1 ; i >= k  - 1 ; i--) {
			int temp = 0, num = 0;
			for (int j = i; j >= i - k + 1; j--) { 
				if (stones[j] > temp) {
					temp = stones[j];
					num = j;
				}
			}
			i = num;
			answer = min(temp, answer);
		}
	}
	else { 
		for (int i = 0; i < stones.size() - k + 1; i++) {
			int temp = 0, num = 0;
			for (int j = i; j <= k - 1 + i; j++) {
				if (stones[j] > temp) {
					temp = stones[j];
					num = j;
				}
			}
			i = num;
			answer = min(temp, answer);
		}
	}
	printf("%d\n", answer);
	
	return 0;
}