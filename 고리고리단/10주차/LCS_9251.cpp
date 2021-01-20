#include <iostream>
#include <algorithm>
using namespace std;

string A, B;
int dp[1001][1001];

using namespace std;

int main()
{
    cin >> A;
    cin >> B;

    for (int i = 1; i <= A.size(); i++)
    {
        for (int j = 1; j <= B.size(); j++)
        {
            if (A[j - 1] == B[i - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    printf("%d", dp[A.size()][B.size()]);
}