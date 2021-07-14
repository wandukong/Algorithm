#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define PIVOT 1 << 11 //  2000 <= N
int N, M;
vector<pair<int, int>> v;
int tree[PIVOT * PIVOT]; // °£¼±Àº Á¦°ö

void update(int idx)
{
    idx += PIVOT;
    tree[idx] += 1;
    while (idx >>= 1)
    {
        tree[idx] += 1;
    }
}

int sum(int l, int r)
{
    l += PIVOT, r += PIVOT;
    int ret = 0;
    while (l <= r)
    {
        if (l % 2)
            ret += tree[l++];
        if (!(r % 2))
            ret += tree[r--];
        l /= 2, r /= 2;
    }
    return ret;
}

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());
    long long ans = 0;
    for (int i = 0; i < M; i++)
    {
        ans += sum(v[i].second + 1, N);
        update(v[i].second);
    }
    printf("%lld", ans);
    return 0;
}