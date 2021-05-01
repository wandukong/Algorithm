#include <algorithm>
#include <iostream>

int N, a, b, c;
int tree[4000001];

void update(int n, int s, int e, int diff, int favor)
{
    if (s > favor || favor > e)
        return;
    else
        tree[n] += diff;
    if (s == e)
        return;
    int m = (s + e) / 2;
    update(n * 2, s, m, diff, favor);
    update(n * 2 + 1, m + 1, e, diff, favor);
}

int query(int n, int s, int e, int target)
{
    if (s == e)
        return s;
    int mid = (s + e) / 2;
    if (target <= tree[n * 2])
        return query(n * 2, s, mid, target);
    else
        return query(n * 2 + 1, mid + 1, e, target - tree[n * 2]);
}

int main()
{
    scanf("%d", &N);
    while (N--)
    {
        scanf("%d", &a);
        if (a == 1)
        {
            scanf("%d", &b);
            int favor = query(1, 1, 1000000, b);
            printf("%d\n", favor);
            update(1, 1, 1000000, -1, favor);
        }
        else
        {
            scanf("%d %d", &b, &c);
            update(1, 1, 1000000, c, b);
        }
    }
    return 0;
}