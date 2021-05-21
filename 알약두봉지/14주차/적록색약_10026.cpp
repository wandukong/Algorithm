#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>

using namespace std;

int N;
char arr[101][101];
bool check[101][101];
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};

void bfs1(int r, int c, char color)
{
    queue<pair<int, int>> q;
    q.push({r, c});
    while (!q.empty())
    {
        r = q.front().first;
        c = q.front().second;
        q.pop();
        check[r][c] = true;
        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= N || nc >= N || nr < 0 || nc < 0)
                continue;
            if (check[nr][nc])
                continue;
            if (arr[nr][nc] != color) // 적록색약 x
                continue;
            q.push({nr, nc});
        }
    }
}

void bfs2(int r, int c, char color)
{
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

            if (nr >= N || nc >= N || nr < 0 || nc < 0)
                continue;
            if (check[nr][nc])
                continue;
            if ((color == 'R' || color == 'G') && arr[nr][nc] != 'B'){
                q.push({nr, nc});
                
            else if (arr[nr][nc] == 'B' && color == 'B')
                q.push({nr, nc});
        }
    }
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf(" %c", &arr[i][j]);

    int ans1 = 0, ans2 = 0;
    for (int i = 0; i < N; i++) // 적록색약 x
        for (int j = 0; j < N; j++)
            if (!check[i][j])
            {
                bfs1(i, j, arr[i][j]);
                ans1++;
            }
    memset(check, 0, sizeof(check));
    for (int i = 0; i < N; i++) // 적록색약 O
        for (int j = 0; j < N; j++)
            if (!check[i][j])
            {
                bfs2(i, j, arr[i][j]);
                ans2++;
            }
    printf("%d %d", ans1, ans2);
    return 0;
}