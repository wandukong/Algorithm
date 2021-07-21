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
        // dq가 비어있지 않고, L 크기를 벗어 난 경우
        if (!dq.empty() && dq.front().first <= i - L)
            dq.pop_front();
        scanf("%d", &input);

        // 들어오는 값이 큐 뒤에 있는 것보다 작은 경우 기존의 들어있는 값 필요 없음.
        while (!dq.empty() && dq.back().second >= input)
            dq.pop_back();
        dq.push_back({i, input});
        printf("%d ", dq.front().second);
    }
    return 0;
}