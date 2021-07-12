#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N, M, map[501][501], ans;

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= M; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        map[a][b] = 1;
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
            printf("%d ", map[i][j]);
        printf("\n");
    }
    int cnt1 = 0, cnt2 = 0;
    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                if (map[i][k] && map[k][j])
                    map[i][j] = 1;
    for (int i = 1; i <= N; i++)
    {
        int cnt1 = 0, cnt2 = 0;
        for (int j = 1; j <= N; j++)
        {
            if (map[i][j])
                cnt1++;
            if (map[j][i])
                cnt2++;
        }
        if (cnt1 + cnt2 == N - 1)
            ans++;
    }
    printf("%d", ans);
    return 0;
}