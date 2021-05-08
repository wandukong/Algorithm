#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>

#define INF 987654321

using namespace std;

int N, arr[17][17], dp[17][1 << 17], path[17][1 << 17];

int TSP(int cur, int visited)
{
    if (visited == (1 << N) - 1)
    {
        if (arr[cur][0] == 0)
            return INF;
        return arr[cur][0];
    }

    int &result = dp[cur][visited];
    if (result != 0)
        return result;

    result = INF;
    for (int next = 0; next < N; next++)
    {
        if (visited & (1 << next))
            continue;
        else if (arr[cur][next] == 0)
            continue;
        if (result > arr[cur][next] + TSP(next, visited | (1 << next)))
        {
            result = arr[cur][next] + TSP(next, visited | (1 << next));
            path[cur][visited] = next;
        }
    }
    return result;
}

void printPath(int node, int visited) // 처음부터 최적 상태 따라가면서 노드 출력
{
    if (node == -1)
        return;
    printf("%d ", node);
    int nextNode = path[node][visited];
    printPath(nextNode, visited | (1 << nextNode));
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &arr[i][j]);
    memset(path, -1, sizeof(path));
    int result = TSP(0, 1);
    printf("%d\n", result);
    printPath(0, 1);
    printf("0", result);
    return 0;
}
