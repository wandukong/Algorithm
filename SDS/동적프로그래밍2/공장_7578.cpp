#include <algorithm>
#include <iostream>

using namespace std;

#define PIV (1 << 19)

int tree[PIV * 2], N;
pair<int, int> arr[PIV];

int temp[1000001];

void update(int idx)
{
    idx += PIV;
    tree[idx] += 1;
    while (idx >>= 1)
        tree[idx] += 1;
}

int sum(int l, int r)
{
    l += PIV, r += PIV;
    int ret = 0;
    while (l <= r)
    {
        if (l % 2)
            ret += tree[l++];
        if (l % 2)
            ret += tree[r--];
        l /= 2, r /= 2;
    }
    return ret;
}

int main()
{
    scanf("%d", &N);
    for (int i = 1, num; i <= N; i++)
        scanf("%d", &num), arr[i].first = i, temp[num] = i;
    for (int i = 1, num; i <= N; i++)
        scanf("%d", &num), arr[i].second = temp[num];
    long long ans = 0;
    for (int i = 1; i <= N; i++)
    {
        ans += sum(arr[i].second + 1, N);
        update(arr[i].second);
    }
    printf("%lld", ans);
    return 0;
}