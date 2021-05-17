#include <algorithm>
#include <iostream>

using namespace std;

int N, M, R, arr[302][302];
int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};

void rotate(int idx, int len)
{
    for (int i = 0; i < R % len; i++)
    {

        int temp = arr[idx][idx];
        int r = idx, c = idx;

        int dir = 0;
        while (dir < 4)
        {
            int nr = r + dr[dir];
            int nc = c + dc[dir];
            if (nr == idx && nc == idx)
                break;
            if (idx > nr || idx > nc || nr >= N - idx || nc >= M - idx)
            {
                dir++;
                continue;
            }
            arr[r][c] = arr[nr][nc];
            r = nr, c = nc;
        }
        arr[idx + 1][idx] = temp;
    }
}

int main()
{
    scanf("%d %d %d", &N, &M, &R);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            scanf("%d", &arr[i][j]);
    int cnt = min(N, M) / 2;
    int n = N, m = M;
    for (int i = 0; i < cnt; i++)
    {
        rotate(i, n * 2 + m * 2 - 4);
        n -= 2, m -= 2;
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
    return 0;
}