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

void dfs(int r, int c) // ������ �����ϱ� ���ؼ� ���ڸ� �ٲ��ش�.
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

            if (arr[nr][nc] == 0 && !check[nr][nc]) // �湮���� �ʰ� ���� �̵��� ���� �ٴ��� ���
            {
                check[nr][nc] = 1;
                q.push({{nr, nc}, cnt + 1});
            }
            else if (arr[nr][nc] != island && arr[nr][nc] != 0) // �ٴٰ� �ƴ� �ٸ� ���� ��������
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
            if (arr[i][j]) // ���� �Ϻκи� bfs()�� ������.
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