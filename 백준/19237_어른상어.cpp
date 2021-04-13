#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>

using namespace std;

typedef struct
{
    int n, r, c, d, cnt;
} sharkInfo;

bool cmp(sharkInfo a, sharkInfo b)
{
    return a.n < b.n;
}

int N, M, K, temp[401], curCnt = 1;
pair<int, int> smell[20][20], preSmell[20][20];
int direction[401][4][4];

vector<sharkInfo> shark;

int dr[] = {-1, 1, 0, 0}; // 상하좌우
int dc[] = {0, 0, -1, 1}; // 상하좌우

void solve()
{
    while (shark.size() > 1)
    {
        int num = shark.front().n;
        int dir = shark.front().d;
        int r = shark.front().r;
        int c = shark.front().c;
        int cnt = shark.front().cnt;
        shark.erase(shark.begin());

        if (cnt > 1000)
        {
            curCnt = -1;
            return;
        }

        if (cnt > curCnt)
        {

            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++)
                {
                    if (smell[i][j].second > 0)
                        smell[i][j].second--;
                    if (smell[i][j].second == 0)
                        smell[i][j] = {0, 0};
                }
            curCnt++;
            memcpy(preSmell, smell, sizeof(smell));
        }

        bool chk = false;
        bool chk2 = false;

        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[direction[num][dir][i]];
            int nc = c + dc[direction[num][dir][i]];

            if (0 > nr || 0 > nc || nc >= N || nr >= N)
                continue;
            if (smell[nr][nc].second == K + 1 && preSmell[nr][nc].second == 0)
            {
                chk2 = true;
                break;
            }
            if (smell[nr][nc].second > 0) //  냄새가 이미 존재
                continue;
            chk = true;
            smell[nr][nc] = {num, K + 1};
            shark.push_back({num, nr, nc, direction[num][dir][i], cnt + 1});
            break;
        }
        if (!chk && !chk2) // 자기 냄새 있는 곳으로
        {
            for (int i = 0; i < 4; i++)
            {
                int nr = r + dr[direction[num][dir][i]];
                int nc = c + dc[direction[num][dir][i]];

                if (0 > nr || 0 > nc || nc >= N || nr >= N)
                    continue;
                if (smell[nr][nc].first != num) //  다른 상어의 냄새
                    continue;
                smell[nr][nc] = {num, K + 1};
                shark.push_back({num, nr, nc, direction[num][dir][i], cnt + 1});
                break;
            }
        }
    }
}

int main()
{
    scanf("%d %d %d", &N, &M, &K);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            int a;
            scanf("%d", &a);
            if (a != 0)
                smell[i][j] = {a, K};
        }

    for (int i = 1; i <= M; i++)
    {
        int a;
        scanf("%d", &a);
        temp[i] = a - 1;
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (smell[i][j].first > 0)
                shark.push_back({smell[i][j].first, i, j, temp[smell[i][j].first], 1});
    sort(shark.begin(), shark.end(), cmp);

    for (int i = 1; i <= M; i++)
        for (int j = 0; j < 4; j++)
            for (int k = 0; k < 4; k++)
            {
                int a;
                scanf("%d", &a);
                direction[i][j][k] = a - 1;
            }
    solve();
    memcpy(preSmell, smell, sizeof(smell));
    printf("%d", curCnt);
    return 0;
}