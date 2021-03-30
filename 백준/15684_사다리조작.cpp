#include <iostream>
#include <algorithm>

using namespace std;

int N, M, H, ans = 987654321;
bool arr[12][32];

bool ladder()
{
    for (int i = 1; i <= N; i++)
    {
        int cur = i;
        for (int j = 1; j <= H; j++)
        {
            if (arr[cur][j])
                cur += 1;
            else if (arr[cur - 1][j])
                cur -= 1;
        }
        if (cur != i)
            return false;
    }
    return true;
}

void go(int loc, int cnt)
{
    if (cnt > 3)
        return;

    if (ladder())
    {
        ans = min(ans, cnt);
        return;
    }

    for (int i = loc; i <= H; i++)
    {
        for (int j = 1; j < N; j++)
        {
            if (arr[j][i])
                continue;
            if (arr[j - 1][i])
                continue;
            if (arr[j + 1][i])
                continue;

            arr[j][i] = true;
            go(i, cnt + 1);
            arr[j][i] = false;
        }
    }
}

int main()
{
    scanf("%d%d%d", &N, &M, &H);

    for (int i = 0; i < M; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        arr[b][a] = true;
    }
    go(1, 0);
    if (ans == 987654321)
        printf("-1");
    else
        printf("%d", ans);
    return 0;
}