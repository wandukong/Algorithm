#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M;
char arr[101][101];
int dp[101][101];
int dr[] = {0, 0, -1, 1};
int dc[] = {1, -1, 0, 0};
vector<vector<pair<int, int>>> v;

void dijkstra(int r, int c)
{
    dp[r][c] = 0;
    queue<pair<int, int>> q;
    q.push({r, c});
    while (!q.empty())
    {
        r = q.front().first;
        c = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= M || nc >= N || nr < 0 || nc < 0)
                continue;
            if (arr[nr][nc] == '1' && dp[nr][nc] > dp[r][c] + 1)
            {
                dp[nr][nc] = dp[r][c] + 1;
                q.push({nr, nc});
            }
            else if (arr[nr][nc] == '0' && dp[nr][nc] > dp[r][c])
            {
                dp[nr][nc] = dp[r][c];
                q.push({nr, nc});
            }
        }
    }
}

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
        {
            scanf(" %c", &arr[i][j]);
            dp[i][j] = 987654321;
        }
    dijkstra(0, 0);
    printf("%d", dp[M - 1][N - 1]);
    return 0;
}