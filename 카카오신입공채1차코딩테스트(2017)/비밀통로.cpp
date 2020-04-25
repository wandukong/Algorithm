#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <vector>

using namespace std;

int N;
int arr[20];
int arr2[20];
char ans[20][20];

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &arr[i]);

	for (int i = 1; i <= N; i++)
		scanf("%d", &arr2[i]);


	for (int i = 1; i <= N; i++) {
		int num = (arr[i] | arr2[i]);
		int temp = N;												
		while (num > 1) {
			ans[i][temp--] = num % 2 == 1 ? '#' : ' ';
			num /= 2;
		}
		ans[i][temp] = num == 1 ? '#' : ' ';
	}
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (ans[i][j - 1] == ' ' && ans[i][j] == ' ')
				continue;
			printf("%1c", ans[i][j]);
		}
		printf("");
		printf("\n");
	}

	

	
	return 0;
}
