#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

int N, M, bfNum;
vector<int> bf;            // ������ �ƴ� �����
vector<vector<int>> v;     // �׷���
int check[55];             // �ҹ��� ���ĵ� ����, �ҹ��� �ƴ� ��� üũ �迭
vector<vector<int>> party; // ��Ƽ ����

void dfs(int n)
{
    check[n] = 1;
    for (int i = 0; i < v[n].size(); i++)
        if (!check[v[n][i]])
            dfs(v[n][i]);
    return;
}

int main()
{
    scanf("%d %d", &N, &M);
    scanf("%d", &bfNum);
    int a, b;
    int ans = M;
    for (int i = 0; i < bfNum; i++)
    {
        scanf("%d", &a);
        bf.push_back(a);
    }
    v.resize(N + 1);
    party.resize(M);
    for (int i = 0; i < M; i++)
    {
        int cnt, a, b;
        scanf("%d", &cnt);
        for (int j = 0; j < cnt; j++)
        {
            scanf("%d", &b);
            party[i].push_back(b);
            if (j != 0)
            {
                v[a].push_back(b);
                v[b].push_back(a);
            }
            a = b;
        }
    }
    for (int i = 0; i < bf.size(); i++)
        dfs(bf[i]);
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < party[i].size(); j++)
        {
            if (check[party[i][j]])
            {
                ans--;
                break;
            }
        }
    }
    printf("%d", ans);
    return 0;
}