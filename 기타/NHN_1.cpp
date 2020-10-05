#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int N, cnt = 1;
vector<int> v;
int arr[11][11];
int check[11][11];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, 1, -1};

int bfs(int r, int c)
{
    check[r][c] = 1;
    queue<pair<int, int>> q;
    q.push({r, c});

    while (!q.empty())
    {
        r = q.front().first;
        c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (0 > nr || nr >= N || 0 > nc || nc >= N || check[nr][nc] || !arr[nr][nc])
                continue;

            check[nr][nc] = 1;
            q.push({nr, nc});
            cnt++;
        }
    }
    return cnt;
}

int main()
{

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &arr[i][j]);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            if (!check[i][j] && arr[i][j])
                v.push_back(bfs(i, j));
            cnt = 1;
        }

    sort(v.begin(), v.end());
    printf("%d\n", v.size());
    for (int i = 0; i < v.size(); i++)
    {
        printf("%d", v[i]);
        if (i != v.size() - 1)
            printf(" ");
    }
    return 0;
}

/*

출처 : NHN 

모든 원소가 0 또는 1 인 행렬이 있습니다. 1 로 표시된 원소는 영역을 나타냅니다. 여기에서 상하좌우에 인접한 1
은 같은 영역이라고 가정합니다. 각 영역의 크기는 1 의 개수로 정의합니다. 주어진 N x N 크기의 행렬에서 영역의
개수와 각 영역의 크기를 오름차순으로 출력하세요.

6
0 1 1 0 0 0 
0 1 1 0 1 1
0 0 0 0 1 1
0 0 0 0 1 1
1 1 0 0 1 0
1 1 1 0 0 0
 
4
1 0 0 0
1 0 0 0
0 0 0 0
0 0 1 1  
 */