#include <algorithm>
#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int N, M, R, C, D, ans = 1;
int arr[52][52];
bool check[52][52];
int dr[] = {-1, 0, 1, 0, -1, 0, 1, 0}; // 북 서 남 동
int dc[] = {0, -1, 0, 1, 0, -1, 0, 1};

void bfs(int r, int c)
{
    queue<pair<int, int>> q;
    check[r][c] = true;
    q.push({r, c});
    while (!q.empty())
    {
        bool chk = false;
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        int nd = (D + 1) % 4;             // 다음 방향
        for (int i = nd; i < nd + 4; i++) // 2-a,b
        {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 1 || nc < 1 || nc > M || nr > N || check[nr][nc] || arr[nr][nc])
                continue;

            if (arr[nr][nc] == 0 && !check[nr][nc])
            {
                q.push({nr, nc});
                ans++;
                check[nr][nc] = true;
                chk = true;
                D = i;
                break;
            }
        }
        if (chk)
            continue;
        else
        {
            int back = D + 2;
            back %= 4;
            int br = r + dr[back];
            int bc = c + dc[back]; // 후진할곳
            if (br < 1 || bc < 1 || bc > M || br > N || arr[br][bc])
                break;        // 2-d
            q.push({br, bc}); // 2-c
        }
    }
}

int main()
{
    scanf("%d %d", &N, &M);
    scanf("%d %d %d", &R, &C, &D);

    if (D == 1)
        D = 3;
    else if (D == 3)
        D = 1;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            scanf("%d", &arr[i][j]);
    bfs(R + 1, C + 1);
    printf("%d", ans);
    return 0;
}
