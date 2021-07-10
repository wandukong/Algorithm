#include <iostream>
#include <algorithm>

using namespace std;

int N, num;
pair<int, int> arr[500001];
int tree[1 << 20];

bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int getSum(int s, int e, int n, int l, int r)
{
    if (r < s || e < l)
        return 0;
    if (l <= s && e <= r)
        return tree[n];
    return tree[n] = getSum(s, (s + e) / 2, n * 2, l, r) + getSum((s + e) / 2 + 1, e, n * 2 + 1, l, r);
}

void update(int s, int e, int n, int idx, int value)
{
    if (idx < s || e < idx)
        return;
    if (s == e)
        tree[n] = value;
    else
    {
        update(s, (s + e) / 2, n * 2, idx, value);
        update((s + e) / 2 + 1, e, n * 2 + 1, idx, value);
        tree[n] = tree[n * 2] + tree[n * 2 + 1];
    }
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        int power;
        scanf("%d", &power);
        arr[i] = {i, power};
    }
    sort(arr, arr + N, compare);
    for (int i = 0; i < N; i++)
        arr[i].second = ++num; // power를 1부터 N까지로 라벨링
    sort(arr, arr + N);
    for (int i = 0; i < N; i++)
    {
        int curPower = arr[i].second;
        int cnt = 0;
        if (i != 0)
            cnt = getSum(1, N, 1, 1, curPower - 1);
        update(1, N, 1, curPower, 1);
        printf("%d\n", i + 1 - cnt);
    }
    return 0;
}