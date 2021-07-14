#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, PIVOT = 1;
vector<int> tree;

void update(int idx, int num)
{
    idx += PIVOT; // 리프노드로 이동
    tree[idx] = num;
    while (idx >>= 1)                                  // 나누기 2
        tree[idx] = tree[idx * 2] + tree[idx * 2 + 1]; // 조상값을 더하면서 올라간다.
}

int sum(int l, int r)
{
    l += PIVOT, r += PIVOT;
    int ret = 0;
    while (l <= r)
    {
        if (l % 2 == 1) //조상의 왼쪽 경계값이 아닌 경우 -> 조상의 가운데의 어느 수 (왼쪽 트리는 모두 짝수이다)
            ret += tree[l++];
        if (r % 2 == 0) //조상의 오른 경계값이 아닌 경우 -> 조상의 가운데의 어느 수 (오른쪽 트리는 모두 홀수이다)
            ret += tree[r--];
        l /= 2, r /= 2;
    }
    return ret;
}

int main()
{
    scanf("%d %d", &N, &M);
    while (PIVOT <= N)
        PIVOT <<= 1;
    tree.resize(2 * PIVOT);
    for (int i = 1; i <= N; i++)
    {
        int num;
        scanf("%d", &num);
        update(i - 1, num);
    }
    while (M--)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", sum(a - 1, b - 1));
    }
    return 0;
}