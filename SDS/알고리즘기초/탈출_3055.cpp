#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

int R, C, ans = -1;
char arr[51][51];
int water_visted[51][51];
int S_visted[51][51];
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};
queue<pair<int, int>> water;
queue<pair<int, int>> q;

bool bfs()
{
    while (!q.empty())
    {
        int water_size = water.size();
        for (int i = 0; i < water_size; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                int nr = water.front().first + dr[j];
                int nc = water.front().second + dc[j];
                if (nr < 0 || nc < 0 || nr >= R || nc >= C)
                    continue;
                if (arr[nr][nc] == 'X' || arr[nr][nc] == 'D' || water_visted[nr][nc] != 0)
                    continue;
                water_visted[nr][nc] = water_visted[water.front().first][water.front().second] + 1;
                water.push({nr, nc});
            }
            water.pop();
        }
        int s_size = q.size();
        for (int i = 0; i < s_size; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                int nr = q.front().first + dr[j];
                int nc = q.front().second + dc[j];
                if (nr < 0 || nc < 0 || nr >= R || nc >= C)
                    continue;
                if (arr[nr][nc] == 'X' || water_visted[nr][nc] != 0 || S_visted[nr][nc] != 0)
                    continue;
                if (arr[nr][nc] == 'D')
                {
                    ans = S_visted[q.front().first][q.front().second];
                    return true;
                }
                else
                {
                    S_visted[nr][nc] = S_visted[q.front().first][q.front().second] + 1;
                    q.push({nr, nc});
                }
            }
            q.pop();
        }
    }
    return false;
}

int main()
{
    scanf("%d %d", &R, &C);
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
        {
            scanf(" %c", &arr[i][j]);
            if (arr[i][j] == 'S')
            {
                q.push({i, j});
                S_visted[i][j] = 1;
            }
            else if (arr[i][j] == '*')
            {
                water.push({i, j});
                water_visted[i][j] = 1;
            }
        }
    if (bfs())
        printf("%d", ans);
    else
        printf("KAKTUS");
    return 0;
}