#include <iostream>
#include <algorithm>

using namespace std;

int G, P, uf[100001], ans;

int getParent(int x)
{
    if (uf[x] == x)
        return x;
    return uf[x] = getParent(uf[x]);
}

void setParent(int a, int b)
{
    a = getParent(a), b = getParent(b);
    uf[b] = a;
}

int main()
{
    scanf("%d %d", &G, &P);

    for (int i = 0; i <= G; i++)
        uf[i] = i;

    for (int i = 0; i < P; i++)
    {
        int a;
        scanf("%d", &a);
        int in = getParent(a);
        if (in == 0)
            break;
        setParent(in - 1, in);
        ans++;
    }
    printf("%d", ans);
    return 0;
}
