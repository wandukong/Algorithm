#include <iostream>
#include <algorithm>
#include <string.h>
#define INF 1000000010

using namespace std;

int N, M, K, dp[101][101];
string answer;

int getAZ(int a, int b)
{
    if (a == 0 || b == 0)
        return 1;
    if (dp[a][b] != -1)
        return dp[a][b];

    dp[a][b] = getAZ(a - 1, b) + getAZ(a, b - 1);
    if (dp[a][b] >= INF) // 10억이 상한선
        dp[a][b] = INF;
    return dp[a][b];
}

int main()
{
    scanf("%d%d%d", &N, &M, &K);
    memset(dp, -1, sizeof(dp));
    if (getAZ(N, M) < K) // K보다 전체 경우의수가 작으면 답 못찾음
    {
        printf("-1");
        return 0;
    }
    int countA = N, countZ = M;
    for (int i = 0; i < N + M; i++)
    {
        if (countA > 0)
        {
            int tmp = getAZ(countA - 1, countZ); // 미리 A를 넣었 때의 경우의 수를 구한다.
            if (tmp < K)                         // A를 넣었을 때의 경우의 수가 K보다 작으면 Z로 넘어가야한다!
            {
                answer.push_back('z');
                K -= tmp;
                countZ--;
            }
            else
            {
                answer.push_back('a');
                countA--;
            }
        }
        else
            answer.push_back('z');
    }
    printf("%s\n", answer.c_str());
    return 0;
}