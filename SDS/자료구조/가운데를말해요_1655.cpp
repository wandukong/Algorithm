#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N;
priority_queue<int> max_q;
priority_queue<int, vector<int>, greater<int>> min_q;

int main()
{
    scanf("%d", &N);
    while (N--)
    {
        int a;
        scanf("%d", &a);
        if (min_q.size() == max_q.size())
            max_q.push(a);
        else
            min_q.push(a);
        if (!max_q.empty() && !min_q.empty() && min_q.top() < max_q.top())
        {
            max_q.push(min_q.top());
            min_q.push(max_q.top());
            max_q.pop();
            min_q.pop();
        }
        printf("%d\n", max_q.top());
    }
    return 0;
}