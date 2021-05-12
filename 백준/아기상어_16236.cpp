#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>

using namespace std;

typedef struct
{
    int row;
    int col;
    int time;
} info;

struct compare
{
    bool operator()(info a, info b)
    {
        if (a.time == b.time)
        {
            if (a.row == b.row)
            {
                return a.col > b.col;
            }
            return a.row > b.row;
        }
        return a.time > b.time;
    }
};

int N, ans;
int shark = 2, exp = 0;
int arr[21][21];
int chk[21][21];
int dr[] = {0, 0, -1, 1};
int dc[] = {1, -1, 0, 0};
priority_queue<info, vector<info>, compare> pq;

void dfs(int r, int c, int t)
{
    chk[r][c] = t;
    if (chk[r][c] != 0 && arr[r][c] > 0 && arr[r][c] < shark)
        pq.push({r, c, t});

    for (int i = 0; i < 4; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr < 0 || nc < 0 || nr >= N || nc >= N)
            continue;
        if (arr[nr][nc] > shark)
            continue;
        if (chk[nr][nc] == -1 || chk[nr][nc] > t + 1)
            dfs(nr, nc, t + 1);
    }
}

void solve(int r, int c)
{
    while (true)
    {
        memset(chk, -1, sizeof(chk));
        dfs(r, c, 0);
        if (!pq.empty())
        {
            ans += pq.top().time;
            exp++;
            if (exp == shark)
            {
                exp = 0;
                shark++;
            }
            r = pq.top().row;
            c = pq.top().col;
            arr[r][c] = 0;
            pq = priority_queue<info, vector<info>, compare>();
        }
        else
            break;
    }
}

int main()
{
    scanf("%d", &N);
    int sn, sc;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &arr[i][j]);
            if (arr[i][j] == 9)
            {
                sn = i, sc = j;
                arr[i][j] = 0;
            }
        }
    solve(sn, sc);
    printf("%d", ans);
    return 0;
}