#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int N, K, S, X, Y;
int arr[201][201];
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};

struct info
{
    int cnt, r, c, v;
};

struct compare
{
    bool operator()(info A, info B)
    {
        if (A.cnt == B.cnt)
            return A.v > B.v;
        return A.cnt > B.cnt;
    }
};
priority_queue<info, vector<info>, compare> q;

int bfs()
{
    while (!q.empty())
    {
        int r = q.top().r;
        int c = q.top().c;
        int v = q.top().v;
        int cnt = q.top().cnt;
        q.pop();
        if (S == cnt)
            return arr[X][Y];
        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr <= 0 || nc <= 0 || nc > N || nr > N)
                continue;
            if (arr[nr][nc] != 0)
                continue;
            arr[nr][nc] = v;
            q.push({cnt + 1, nr, nc, v});
        }
    }
    return arr[X][Y];
}

int main()
{
    scanf("%d %d", &N, &K);
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
        {
            scanf("%d", &arr[i][j]);
            if (arr[i][j])
                q.push({0, i, j, arr[i][j]});
        }
    scanf("%d %d %d", &S, &X, &Y);
    printf("%d", bfs());
    return 0;
}