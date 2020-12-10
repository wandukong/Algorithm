#include <iostream>
#include <algorithm>

using namespace std;

int n;
int dp[1005][3];
int arr[1005][3];

int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < 3; j++)
			scanf("%d", &arr[i][j]);
	
	dp[1][0] = arr[1][0];
	dp[1][1] = arr[1][1];
	dp[1][2] = arr[1][2];
	for (int i = 2; i <= n; i++){
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + arr[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + arr[i][1];
		dp[i][2] = min(dp[i - 1][1], dp[i - 1][0]) + arr[i][2];
	}
	printf("%d\n", min(dp[n][0], min(dp[n][1], dp[n][2])));
	return 0;
}