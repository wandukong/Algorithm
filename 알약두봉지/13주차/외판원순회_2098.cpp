#include <iostream>
#include <algorithm>
#include <string.h>

#define INF 987654321

using namespace std;

int N, arr[17][17], dp[17][1 << 17];

int TSP(int cur, int visited)
{
    if (visited == (1 << N) - 1)
    {
        if (arr[cur][0] == 0)
            return INF;
        return arr[cur][0];
    }

    int &result = dp[cur][visited];
    if (result != -1)
        return result;

    result = INF;
    for (int next = 0; next < N; next++)
    {
        if (visited & (1 << next))
            continue;
        else if (arr[cur][next] == 0)
            continue;
        result = min(result, arr[cur][next] + TSP(next, visited | (1 << next)));
    }
    return result;
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &arr[i][j]);
    memset(dp, -1, sizeof(dp));
    printf("%d", TSP(0, 1));
    return 0;
}