#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[12];
int op[4];
bool check[11];
int opArr[11];
int used[11];
int ansMin = 2000000000, ansMax = -2000000000;

void go(int cnt)
{
    if (cnt == N - 1)
    {
        int temp = arr[0];
        for (int i = 0; i < N - 1; i++)
        {
            if (used[i] == 1)
                temp += arr[i + 1];
            else if (used[i] == 2)
                temp -= arr[i + 1];
            else if (used[i] == 3)
                temp *= arr[i + 1];
            else if (used[i] == 4)
                temp /= arr[i + 1];
        }
        ansMax = max(ansMax, temp);
        ansMin = min(ansMin, temp);
        return;
    }

    for (int i = 0; i < N - 1; i++)
    {
        if (!check[i])
        {
            check[i] = true;
            used[cnt] = opArr[i];
            go(cnt + 1);
            check[i] = false;
            used[cnt] = 0;
        }
    }
    return;
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    for (int i = 0; i < 4; i++)
        scanf("%d", &op[i]);

    int idx = 0;
    for (int i = 0; i < 4; i++)
    {
        while (op[i])
        {
            opArr[idx++] = i + 1;
            op[i]--;
        }
    }
    go(0);
    printf("%d\n", ansMax);
    printf("%d", ansMin);
    return 0;
}