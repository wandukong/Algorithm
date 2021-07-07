#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, godo[51][51];
char map[51][51];
int cnt_k, y_post, x_post;

int dr[] = {0, 1, 0, -1, -1, -1, 1, 1};
int dc[] = {1, 0, -1, 0, -1, 1, 1, -1};
vector<int> hhh;

// low ~ high의 고도사이로 탐색을 했을때, 배달 할 수 있는 집의 개수를 리턴
int bfs(int low, int high)
{
    int cnt = 0;
    bool visited[51][51] = {
        false,
    };
    queue<pair<int, int>> q;
    q.push({y_post, x_post});
    visited[y_post][x_post] = true;
    if (godo[y_post][x_post] < low || godo[y_post][x_post] > high)
        return -1;
    while (!q.empty() && cnt < cnt_k)
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nc < 0 || nr >= N || nc >= N)
                continue;
            if (visited[nr][nc])
                continue;
            if (godo[nr][nc] > high || godo[nr][nc] < low)
                continue;
            if (map[nr][nc] == 'K')
                cnt++;
            visited[nr][nc] = true;
            q.push({nr, nc});
        }
    }
    return cnt;
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf(" %c", &map[i][j]);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (map[i][j] == 'K')
                cnt_k++;
            else if (map[i][j] == 'P')
                y_post = i, x_post = j;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &godo[i][j]);
            hhh.push_back(godo[i][j]);
        }
    sort(hhh.begin(), hhh.end());
    int ans = hhh.back() - hhh[0];
    for (int low = 0, high = 0; low < hhh.size() && high < hhh.size() && low <= high;)
    {
        if (bfs(hhh[low], hhh[high]) == cnt_k)
        {
            ans = min(hhh[high] - hhh[low], ans);
            low++;
        }
        else
            high++;
    }
    printf("%d", ans);
}