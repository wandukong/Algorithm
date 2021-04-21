#include <iostream>
#include <algorithm>

using namespace std;

int N, M, uf[2001];

int getParent(int x)
{
    if (uf[x] == x)
        return x;
    return uf[x] = getParent(uf[x]);
}

void setParent(int a, int b)
{
    a = getParent(a), b = getParent(b);
    if (a < b)
        uf[b] = a;
    else
        uf[a] = b;
}

int main()
{
    scanf("%d %d", &N, &M);

    for (int i = 1; i <= N; i++)
        uf[i] = i;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
        {
            int x;
            scanf("%d", &x);
            if (x == 1)
            {
                setParent(i, j);
            }
        }

    int temp;
    for (int i = 1; i <= M; i++)
    {
        int x;
        scanf("%d", &x);

        if (i == 1)
        {
            temp = uf[x];
            continue;
        }
        if (temp != uf[x])
        {
            printf("NO");
            return 0;
        }
    }
    printf("YES");
    return 0;
}