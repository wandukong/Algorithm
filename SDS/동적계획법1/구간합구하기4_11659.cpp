#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, PIVOT = 1;
vector<int> tree;

void update(int idx, int num)
{
    idx += PIVOT; // �������� �̵�
    tree[idx] = num;
    while (idx >>= 1)                                  // ������ 2
        tree[idx] = tree[idx * 2] + tree[idx * 2 + 1]; // ������ ���ϸ鼭 �ö󰣴�.
}

int sum(int l, int r)
{
    l += PIVOT, r += PIVOT;
    int ret = 0;
    while (l <= r)
    {
        if (l % 2 == 1) //������ ���� ��谪�� �ƴ� ��� -> ������ ����� ��� �� (���� Ʈ���� ��� ¦���̴�)
            ret += tree[l++];
        if (r % 2 == 0) //������ ���� ��谪�� �ƴ� ��� -> ������ ����� ��� �� (������ Ʈ���� ��� Ȧ���̴�)
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