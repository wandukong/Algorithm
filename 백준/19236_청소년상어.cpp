#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>

using namespace std;

typedef struct
{
    int r;
    int c;
    int dir;
} fish;
int N, arr[4][4], ans, sum;
fish fishArr[17];
bool check[17];
int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[] = {0, -1, -1, -1, 0, 1, 1, 1};

void move(int shark)
{
    for (int i = 1; i <= 16; i++)
    {
        if (i == shark || check[i])
            continue;
        int curR = fishArr[i].r;
        int curC = fishArr[i].c;
        int curD = fishArr[i].dir;
        int nr, nc;
        for (int j = 0; j < 8; j++)
        {
            nr = curR + dr[(curD + j) % 8];
            nc = curC + dc[(curD + j) % 8];

            if (nr < 0 || nc < 0 || nr >= 4 || nc >= 4 || (fishArr[shark].r == nr && fishArr[shark].c == nc))
                continue;

            fishArr[i].dir = (curD + j) % 8;
            break;
        }

        int temp = arr[nr][nc];
        arr[nr][nc] = arr[curR][curC];
        arr[curR][curC] = temp;

        fishArr[i].r = nr, fishArr[i].c = nc;
        fishArr[temp].r = curR, fishArr[temp].c = curC;
    }
}

void dfs(int shark)
{
    move(shark);
    int cnt = 1;
    int sharkR, sharkC;
    queue<pair<int, int>> q;
    while (true)
    {
        sharkR = fishArr[shark].r + dr[fishArr[shark].dir] * cnt;
        sharkC = fishArr[shark].c + dc[fishArr[shark].dir] * cnt;

        if (0 <= sharkR && 0 <= sharkC && sharkC < 4 && sharkR < 4)
        {
            q.push({sharkR, sharkC});
            cnt++;
        }
        else
            break;
    }
    while (!q.empty())
    {
        sharkR = q.front().first;
        sharkC = q.front().second;
        q.pop();
        int temp[4][4];
        fish temp2[17];
        if (!check[arr[sharkR][sharkC]])
        {

            memcpy(temp, arr, sizeof(arr));
            copy(fishArr, fishArr + 17, temp2);
            sum += arr[sharkR][sharkC];
            ans = max(ans, sum);
            check[arr[sharkR][sharkC]] = true;
            dfs(arr[sharkR][sharkC]);
            sum -= arr[sharkR][sharkC];
            check[arr[sharkR][sharkC]] = false;
            memcpy(arr, temp, sizeof(temp));
            copy(temp2, temp2 + 17, fishArr);
        }
    }
}

int main()
{
    int a, b;

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
        {
            scanf("%d %d", &a, &b);
            fishArr[a] = {i, j, b - 1};
            arr[i][j] = a;
        }

    sum = arr[0][0];
    check[arr[0][0]] = true;
    dfs(arr[0][0]);
    printf("%d", ans);
    return 0;
}