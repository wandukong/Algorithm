#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int bfs(vector<int> numbers, int target)
{
    int ans = 0;
    queue<pair<int, int>> q;
    q.push({numbers[0], 0});
    q.push({numbers[0] * -1, 0});

    while (!q.empty())
    {
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (cnt > numbers.size() - 1)
        {
            continue;
        }
        if (cnt == numbers.size() - 1 && cur == target)
        {
            ans++;
            continue;
        }
        q.push({cur + numbers[cnt + 1], cnt + 1});
        q.push({cur + numbers[cnt + 1] * -1, cnt + 1});
    }
    return ans;
}

int main()
{
    vector<int> numbers = {1, 1, 1, 1, 1};
    int target = 3;
    int answer = bfs(numbers, target);
    printf("%d", answer);
    return 0;
}