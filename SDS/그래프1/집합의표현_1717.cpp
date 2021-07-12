#include <iostream>
#include <algorithm>

using namespace std;

int N, M, parent[1000001];

int getParent(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = getParent(parent[x]);
}

void setParent(int a, int b)
{
    a = getParent(a), b = getParent(b);
    if (a > b)
        swap(a, b);
    parent[b] = a;
}

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++)
        parent[i] = i;
    while (M--)
    {
        int cal, a, b;
        scanf("%d %d %d", &cal, &a, &b);
        if (cal == 0)
            setParent(a, b);
        else
        {
            if (getParent(a) == getParent(b))
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}