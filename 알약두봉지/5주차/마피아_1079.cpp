#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int N, M, ans;
int guilty[17];
int check[17];
int R[17][17];

void go(int people, int cnt)
{
    if (check[M] || people == 1) // ���Ǿư� �׾��� �� or ���Ǿư� ȥ�� ���������
    {
        ans = max(ans, cnt);
        return;
    }

    if (people % 2) // Ȧ�� : �� ���� ������ �Ǻ�
    {
        int idx, maxG = 0;
        for (int i = 0; i < N; i++)
        {
            if (maxG < guilty[i] && !check[i])
            {
                maxG = guilty[i];
                idx = i;
            }
        }
        if (idx == M)
        {
            if (cnt > ans)
                ans = cnt;
            return;
        }
        check[idx] = 1;
        go(people - 1, cnt);
        check[idx] = 0;
    }
    else // ¦�� : �� ���Ǿư� ����
    {
        for (int i = 0; i < N; i++)
        {
            if (M == i)
                continue;
            if (!check[i])
            {
                check[i] = 1;
                for (int j = 0; j < N; j++)
                {
                    if (i == j || check[j])
                        continue;
                    guilty[j] += R[i][j];
                }
                go(people - 1, cnt + 1);
                for (int j = 0; j < N; j++)
                {
                    if (i == j || check[j])
                        continue;
                    guilty[j] -= R[i][j];
                }
                check[i] = 0;
            }
        }
    }
    return;
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &guilty[i]);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &R[i][j]);
    scanf("%d", &M);
    go(N, 0);
    printf("%d", ans);
    return 0;
}