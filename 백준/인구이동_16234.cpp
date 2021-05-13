#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;
int N, L, R, ans, sum;
bool chk = false;
int arr[51][51];
bool check[51][51];
int dr[] = {0, 0, -1, 1};
int dc[] = {1, -1, 0, 0};

queue<pair<int, int>> q;

void dfs(int r, int c)
{
    q.push({r, c});
    sum += arr[r][c];
    check[r][c] = true;
    for (int i = 0; i < 4; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr < 0 || nc < 0 || nr >= N || nc >= N)
            continue;
        if (check[nr][nc])
            continue;
        int diff = abs(arr[r][c] - arr[nr][nc]);
        if (L <= diff && diff <= R)
        {
            chk = true;
            dfs(nr, nc);
        }
    }
}

int main()
{
    scanf("%d %d %d", &N, &L, &R);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &arr[i][j]);
    while (true)
    {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (!check[i][j])
                {
                    dfs(i, j);
                    int cnt = q.size();
                    while (!q.empty())
                    {
                        arr[q.front().first][q.front().second] = sum / cnt;
                        q.pop();
                    }
                    sum = 0;
                }
        if (!chk)
            break;
        else
        {
            chk = false;
            ans++;
            memset(check, 0, sizeof(check));
        }
    }
    printf("%d", ans);
    return 0;
}
