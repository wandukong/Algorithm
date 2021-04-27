#include <iostream>
#include <algorithm>

using namespace std;

int arr[100001], maxTree[400001], minTree[400001];
int N, M;

int maxInit(int n, int s, int e)
{
    if (s == e)
        return maxTree[n] = arr[s];
    int mid = (s + e) / 2;
    return maxTree[n] = max(maxInit(n * 2, s, mid), maxInit(n * 2 + 1, mid + 1, e));
}

int minInit(int n, int s, int e)
{
    if (s == e)
        return minTree[n] = arr[s];
    int mid = (s + e) / 2;
    return minTree[n] = min(minInit(n * 2, s, mid), minInit(n * 2 + 1, mid + 1, e));
}

int getMaxValue(int l, int r, int n, int s, int e)
{
    if (r < s || e < l)
        return 0;
    if (l <= s && e <= r)
        return maxTree[n];
    int mid = (s + e) / 2;
    return max(getMaxValue(l, r, n * 2, s, mid), getMaxValue(l, r, n * 2 + 1, mid + 1, e));
}

int getMinValue(int l, int r, int n, int s, int e)
{
    if (r < s || e < l)
        return 1000000001;
    if (l <= s && e <= r)
        return minTree[n];
    int mid = (s + e) / 2;
    return min(getMinValue(l, r, n * 2, s, mid), getMinValue(l, r, n * 2 + 1, mid + 1, e));
}

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++)
        scanf("%d", &arr[i]);
    for (int i = 1; i <= N * 4; i++)
        minTree[i] = 1000000001;
    maxInit(1, 1, N);
    minInit(1, 1, N);
    while (M--)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d %d\n", getMinValue(a, b, 1, 1, N), getMaxValue(a, b, 1, 1, N));
    }
    return 0;
}