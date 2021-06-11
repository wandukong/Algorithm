#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int F, S, G, U, D;
bool check[1000002];

int bfs()
{
    queue<pair<int, int>> q;
    q.push({S, 0});
    check[S] = 1;
    while (!q.empty())
    {
        int floor = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (floor == G)
            return cnt;
        if (floor + U <= F && !check[floor + U])
        {
            q.push({floor + U, cnt + 1});
            check[floor + U] = true;
        }
        if (floor - D > 0 && !check[floor - D])
        {
            q.push({floor - D, cnt + 1});
            check[floor - D] = true;
        }
    }
    return -1;
}

int main()
{
    scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);
    int ans = bfs();
    if (ans == -1)
        printf("use the stairs");
    else
        printf("%d", ans);
    return 0;
}