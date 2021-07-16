#include <algorithm>
#include <iostream>

using namespace std;

string A, B;
int dp[4001][4001], ans = 0;

int main()
{
    cin >> A >> B;
    for (int i = 0; i < A.size(); i++)
        for (int j = 0; j < B.size(); j++)
        {
            if (A[i] == B[j])
            {
                dp[i + 1][j + 1] = dp[i][j] + 1;
                ans = max(ans, dp[i + 1][j + 1]);
            }
        }
    printf("%d", ans);
    return 0;
}