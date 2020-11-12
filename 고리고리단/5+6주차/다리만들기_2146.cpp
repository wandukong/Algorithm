#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

int N, island, ans = 987654321;

int arr[101][101];
int check[101][101];
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, -1, 1};

void dfs(int r, int c) // 섬들을 구별하기 위해서 숫자를 바꿔준다.
{
    check[r][c] = 1;
    for (int i = 0; i < 4; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr < 0 || nc < 0 || nr >= N || nc >= N || !arr[nr][nc] || check[nr][nc])
            continue;
        arr[nr][nc] = island;
        dfs(nr, nc);
    }
}

int bfs(int r, int c, int cnt)
{
    queue<pair<pair<int, int>, int>> q;
    q.push({{r, c}, cnt});

    while (!q.empty())
    {
        r = q.front().first.first;
        c = q.front().first.second;
        int cnt = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nc < 0 || nr >= N || nc >= N)
                continue;

            if (arr[nr][nc] == 0 && !check[nr][nc]) // 방문하지 않고 다음 이동할 곳이 바다인 경우
            {
                check[nr][nc] = 1;
                q.push({{nr, nc}, cnt + 1});
            }
            else if (arr[nr][nc] != island && arr[nr][nc] != 0) // 바다가 아닌 다른 섬을 만났을때
                return cnt;
        }
    }
    return 987654321;
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &arr[i][j]);

    island = 1;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (arr[i][j] & !check[i][j])
            {
                arr[i][j] = island;
                dfs(i, j);
                island++;
            }
    memset(check, 0, sizeof(check));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (arr[i][j]) // 섬의 일부분만 bfs()를 돌린다.
            {
                island = arr[i][j];
                ans = min(bfs(i, j, 0), ans);
                memset(check, 0, sizeof(check));
            }
    if (ans == 987654321)
        printf("0\n");
    else
        printf("%d\n", ans);
    return 0;
}