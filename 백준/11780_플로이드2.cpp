#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, a, b, c, arr[101][101], route[101][101];
int INF = 987654321;
vector<int> path;
void findRoute(int start, int end)
{
    if (route[start][end] == 0)
    {
        path.push_back(start);
        path.push_back(end);
        return;
    }

    findRoute(start, route[start][end]);
    path.pop_back();
    findRoute(route[start][end], end);
}

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            if (i == j)
                arr[i][j] = 0;
            else
                arr[i][j] = INF;
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        arr[a][b] = min(arr[a][b], c);
    }
    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
            {
                if (arr[i][j] > arr[i][k] + arr[k][j])
                {
                    arr[i][j] = arr[i][k] + arr[k][j];
                    route[i][j] = k;
                }
            }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
            if (arr[i][j] == INF)
                printf("0 ");
            else
                printf("%d ", arr[i][j]);
        printf("\n");
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (i == j)
            {
                printf("0\n");
                continue;
            }
            findRoute(i, j);
            printf("%d ", path.size());
            for (int i = 0; i < path.size(); i++)
                printf("%d ", path[i]);
            printf("\n");
            path.clear();
        }
    }
    return 0;
}
