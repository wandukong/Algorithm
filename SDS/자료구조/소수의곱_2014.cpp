#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int arr[101];
int N, K;
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
        pq.push(arr[i]);
    }
    long long answer = -1;
    int pre_num = -1, cnt = 0;
    while (cnt != K)
    {
        answer = pq.top();
        pq.pop();
        if (pre_num == answer)
            continue;
        pre_num = answer;
        for (int i = 0; i < N; i++)
        {
            long long num = answer * arr[i];
            if (num > 2147483647)
                continue;
            pq.push(num);
        }
        cnt++;
    }
    printf("%lld", answer);
    return 0;
}