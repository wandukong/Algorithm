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

��ó : NHN 

��� ���Ұ� 0 �Ǵ� 1 �� ����� �ֽ��ϴ�. 1 �� ǥ�õ� ���Ҵ� ������ ��Ÿ���ϴ�. ���⿡�� �����¿쿡 ������ 1
�� ���� �����̶�� �����մϴ�. �� ������ ũ��� 1 �� ������ �����մϴ�. �־��� N x N ũ���� ��Ŀ��� ������
������ �� ������ ũ�⸦ ������������ ����ϼ���.

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