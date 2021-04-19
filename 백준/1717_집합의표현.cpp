#include <iostream>
#include <algorithm>

using namespace std;

int N, M, parent[1000001];

int find(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

void set(int a, int b)
{
    a = find(a), b = find(b);
    if (a < b)
        parent[b] = a;
    else
        parent[a] = b;
}

int main()
{
    scanf("%d %d", &N, &M);

    for (int i = 1; i <= N; i++)
        parent[i] = i;

    while (M--)
    {
        int a, b, c;
        scanf("%d %d %d", &c, &a, &b);
        if (c == 0)
        {
            set(a, b);
        }
        else if (c == 1)
        {
            if (find(a) == find(b))
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}