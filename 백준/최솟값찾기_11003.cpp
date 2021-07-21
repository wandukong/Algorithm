#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N, L, input;
deque<pair<int, int>> dq;

int main()
{
    scanf("%d %d", &N, &L);
    for (int i = 0; i < N; i++)
    {
        // dq�� ������� �ʰ�, L ũ�⸦ ���� �� ���
        if (!dq.empty() && dq.front().first <= i - L)
            dq.pop_front();
        scanf("%d", &input);

        // ������ ���� ť �ڿ� �ִ� �ͺ��� ���� ��� ������ ����ִ� �� �ʿ� ����.
        while (!dq.empty() && dq.back().second >= input)
            dq.pop_back();
        dq.push_back({i, input});
        printf("%d ", dq.front().second);
    }
    return 0;
}