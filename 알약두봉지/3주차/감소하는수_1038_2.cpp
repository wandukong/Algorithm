#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N;
long long dp[1000005];
queue<long long> q;

int main()
{
    scanf("%d", &N);

    for (int i = 1; i < 10; i++)
    {
        dp[i] = i;
        q.push(i);
    }

    int idx = 10;
    while (!q.empty())
    {
        long long num = q.front();
        q.pop();

        int tail = num % 10;
        for (int i = 0; i < tail; i++)
        {
            long long newNum = num * 10 + i;
            dp[idx++] = newNum;
            q.push(newNum);
        }
    }
    if (N == 0 || (dp[N] != 0))
        printf("%lld", dp[N]);
    else
        printf("-1");

    return 0;
}