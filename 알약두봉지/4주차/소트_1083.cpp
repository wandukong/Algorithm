#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int N, S, arr[51];
bool check[1000002];

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);
    scanf("%d", &S);
    int cnt = 0;

    for (int i = 0; i < N; i++)
    {
        priority_queue<pair<int, int>> q;
        for (int j = 0; j < N; j++)
            if (!check[arr[j]])
                q.push({arr[j], j});

        while (!q.empty())
        {
            bool flag = false;
            int num = q.top().first;
            int where = q.top().second;
            q.pop();

            if (arr[i] == num)
                break;
            if (0 < where - i && where - i <= S)
            {
                check[num] = true;
                int a = where - 1, b = where;
                while (true)
                {
                    swap(arr[a], arr[b]);
                    S--;
                    b -= 1;
                    a = b - 1;
                    if (b == i)
                    {
                        flag = true;
                        break;
                    }
                }
                if (flag)
                    break;
            }
        }
    }
    for (int j = 0; j < N; j++)
        printf("%d ", arr[j]);
    printf("\n");
}