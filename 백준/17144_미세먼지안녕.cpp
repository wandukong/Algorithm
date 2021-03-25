#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

int R, C, T, ans;
int arr[51][51];
int temp[51][51];
int dr[] = {0, 0, -1, 1};
int dc[] = {1, -1, 0, 0};
vector<int> robot; // 로봇 위치한 행

void bfs()
{
    queue<pair<int, int>> q;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            if (arr[i][j] != -1 && arr[i][j] != 0)
                q.push({i, j});
    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        int cnt = 0;
        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr < 0 || nc < 0 || nr >= R || nc >= C || arr[nr][nc] == -1)
                continue;
            cnt++;
            temp[nr][nc] += arr[r][c] / 5;
        }
        temp[r][c] -= cnt * (arr[r][c] / 5);
    }
}

void move()
{

    for (int i = 1; i < C - 1; i++) // -> 이동
    {
        temp[robot[0]][i + 1] = arr[robot[0]][i];
        temp[robot[1]][i + 1] = arr[robot[1]][i];
    }
    for (int i = C - 1; i > 0; i--) // <- 이동
    {
        temp[0][i - 1] = arr[0][i];
        temp[R - 1][i - 1] = arr[R - 1][i];
    }
    for (int i = robot[0]; i >= 1; i--) // ↑ 이동 (윗부분)
        temp[i - 1][C - 1] = arr[i][C - 1];
    for (int i = R - 1; i > robot[1] + 1; i--) // ↑ 이동 (아랫부분)
        temp[i - 1][0] = arr[i][0];

    for (int i = 0; i < robot[0] - 1; i++) // ↓ 이동 (윗부분)
        temp[i + 1][0] = arr[i][0];

    for (int i = robot[1]; i < R - 1; i++) // ↓ 이동 (아랫부분)
        temp[i + 1][C - 1] = arr[i][C - 1];

    for (int i = 0; i < R; i++)
        if (i == 0 || i == robot[0] || i == robot[1] || i == R - 1)
            for (int j = 0; j < C; j++)
                arr[i][j] = temp[i][j];
    for (int i = 0; i < R; i++)
    {
        arr[i][0] = temp[i][0];
        arr[i][C - 1] = temp[i][C - 1];
    }
}

int main()
{
    scanf("%d %d %d", &R, &C, &T);
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
        {
            scanf("%d", &arr[i][j]);
            if (arr[i][j] == -1)
                robot.push_back(i);
        }

    while (T--)
    {
        bfs();
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                arr[i][j] += temp[i][j];
        memset(temp, 0, sizeof(temp));
        move();
        memset(temp, 0, sizeof(temp));
    }
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            if (arr[i][j] != -1)
                ans += arr[i][j];
    printf("%d", ans);
    return 0;
}