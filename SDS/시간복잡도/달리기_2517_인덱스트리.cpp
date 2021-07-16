#include <iostream>
#include <algorithm>

using namespace std;

#define piv (1 << 19)

int N, num;
pair<int, int> arr[piv];
int tree[piv * 2];

bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

void update(int idx)
{
    idx += piv;
    tree[idx] += 1;
    while (idx >>= 1)
        tree[idx] += 1;
}

int sum(int l, int r)
{
    l += piv, r += piv;
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
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        int power;
        scanf("%d", &power);
        arr[i] = {i, power};
    }
    sort(arr + 1, arr + N + 1, compare);
    for (int i = 1; i <= N; i++)
        arr[i].second = ++num; // power를 1부터 N까지로 라벨링
    sort(arr + 1, arr + N + 1);
    for (int i = 1; i <= N; i++)
    {
        printf("%d\n", sum(arr[i].second + 1, N) + 1);
        update(arr[i].second);
    }
    return 0;
}