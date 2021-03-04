#include <iostream>
#include <algorithm>

using namespace std;

int N, ans = 101;
int arr[21][21];
int check[21];
int start[21];
int link[21];

void go(int location, int cnt)
{
    if (cnt == N / 2)
    {
        int startSum = 0, linkSum = 0, idx = 0;
        for (int i = 0; i < N; i++)
            if (!check[i])
                link[idx++] = i;

        for (int i = 0; i < cnt; i++)
        {
            for (int j = 0; j < cnt; j++)
            {
                if (i == j)
                    continue;
                startSum += arr[start[i]][start[j]];
                linkSum += arr[link[i]][link[j]];
            }
        }
        ans = min(ans, abs(startSum - linkSum));
        return;
    }

    for (int i = location; i < N; i++)
        if (!check[i])
        {
            check[i] = 1;
            start[cnt] = i;
            go(i + 1, cnt + 1);
            check[i] = 0;
            start[cnt] = 0;
        }
    return;
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &arr[i][j]);
    go(0, 0);
    printf("%d", ans);
    return 0;
}