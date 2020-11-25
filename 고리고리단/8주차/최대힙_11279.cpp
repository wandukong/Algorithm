#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int N;
priority_queue<int> q;

int main()
{
    scanf("%d", &N);

    while (N--)
    {
        int a;
        scanf("%d", &a);

        if (a == 0)
            if (!q.empty())
            {
                printf("->%d\n", q.top());
                q.pop();
            }
            else
                printf("->0\n");
        else
            q.push(a);
    }
    return 0;
}