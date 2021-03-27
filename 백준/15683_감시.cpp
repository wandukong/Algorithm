#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

int N, M, ans = 987654321;
char arr[10][10];
int dr[] = {0, -1, 0, 1}; // 오른쪽, 위쪽, 왼쪽, 아래쪽
int dc[] = {1, 0, -1, 0};
vector<pair<char, pair<int, int>>> v;

void go(int r, int c, int dir)
{
    int f = 1;
    while (true)
    {
        int nr = r + dr[dir] * f;
        int nc = c + dc[dir] * f;
        if (nr < 0 || nc < 0 || nr >= N || nc >= M || arr[nr][nc] == '6')
            return;
        arr[nr][nc] = '#';
        f++;
    }
}

void dfs(int cnt)
{
    if (cnt == v.size())
    {
        int temp = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (arr[i][j] == '0')
                    temp++;
        ans = min(ans, temp);
        return;
    }
    char tempArr[10][10];

    switch (v[cnt].first)
    {
    case '1':
        for (int i = 0; i < 4; i++)
        {
            memcpy(tempArr, arr, sizeof(arr));
            go(v[cnt].second.first, v[cnt].second.second, i);
            dfs(cnt + 1);
            memcpy(arr, tempArr, sizeof(tempArr));
        }
        break;
    case '2':
        for (int i = 0; i < 2; i++)
        {
            memcpy(tempArr, arr, sizeof(arr));
            go(v[cnt].second.first, v[cnt].second.second, i);
            go(v[cnt].second.first, v[cnt].second.second, i + 2);
            dfs(cnt + 1);
            memcpy(arr, tempArr, sizeof(tempArr));
        }
        break;
    case '3':
        for (int i = 0; i < 4; i++)
        {
            memcpy(tempArr, arr, sizeof(arr));
            go(v[cnt].second.first, v[cnt].second.second, i % 4);
            go(v[cnt].second.first, v[cnt].second.second, (i + 1) % 4);
            dfs(cnt + 1);
            memcpy(arr, tempArr, sizeof(tempArr));
        }
        break;
    case '4':
        for (int i = 0; i < 4; i++)
        {
            memcpy(tempArr, arr, sizeof(arr));
            go(v[cnt].second.first, v[cnt].second.second, i % 4);
            go(v[cnt].second.first, v[cnt].second.second, (i + 1) % 4);
            go(v[cnt].second.first, v[cnt].second.second, (i + 2) % 4);
            dfs(cnt + 1);
            memcpy(arr, tempArr, sizeof(tempArr));
        }
        break;
    case '5':
        memcpy(tempArr, arr, sizeof(arr));
        for (int i = 0; i < 4; i++)
            go(v[cnt].second.first, v[cnt].second.second, i);
        dfs(cnt + 1);
        memcpy(arr, tempArr, sizeof(tempArr));
        break;
    }
}

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
            if (49 <= arr[i][j] && arr[i][j] <= 53)
                v.push_back({arr[i][j], {i, j}});
        }
    dfs(0);
    printf("%d", ans);
    return 0;
}