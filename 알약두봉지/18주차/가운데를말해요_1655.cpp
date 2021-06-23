#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N;
int main()
{
    scanf("%d", &N);
    int a;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    while (N--)
    {
        scanf("%d", &a);
        if (maxHeap.empty())
            maxHeap.push(a);
        else
        {
            if (maxHeap.size() == minHeap.size())
                maxHeap.push(a);
            else
                minHeap.push(a);
            if (maxHeap.top() > minHeap.top())
            {
                minHeap.push(maxHeap.top());
                maxHeap.push(minHeap.top());
                minHeap.pop();
                maxHeap.pop();
            }
        }
        printf("%d\n", maxHeap.top());
    }
    return 0;
}