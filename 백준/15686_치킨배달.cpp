#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M, idx = 0, ans = 987654321;
int arr[13];
int check[13];
vector<vector<int>> v;          // 조합
vector<pair<int, int>> home;    // 집
vector<pair<int, int>> chicken; // 치킨집

int combination(int n, int r)
{
    if (n == r || r == 0)
        return 1;
    else
        return combination(n - 1, r - 1) + combination(n - 1, r);
}

void go(int location, int cnt)
{
    if (cnt == M)
    {
        for (int i = 0; i < M; i++)
            v[idx].push_back(arr[i]);
        idx++;
    }
    for (int i = location; i < chicken.size(); i++)
        if (!check[i])
        {
            check[i] = true;
            arr[cnt] = i;
            go(i + 1, cnt + 1);
            check[i] = false;
            arr[cnt] = 0;
        }
    return;
}

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
        {
            int a;
            scanf("%d", &a);
            if (a == 1)
                home.push_back({i, j});
            else if (a == 2)
                chicken.push_back({i, j});
        }

    v.resize(combination(chicken.size(), M));
    go(0, 0);

    for (int i = 0; i < v.size(); i++)
    {
        int sum = 0;
        for (int k = 0; k < home.size(); k++)
        {
            int minDistance = 987654321;
            for (int j = 0; j < v[i].size(); j++)
                minDistance = min(minDistance, abs(chicken[v[i][j]].first - home[k].first) + abs(chicken[v[i][j]].second - home[k].second));
            sum += minDistance;
        }
        ans = min(ans, sum);
    }
    printf("%d\n", ans);
    return 0;
}