#include <algorithm>
#include <iostream>

using namespace std;

int N;
int arr[50];

int main()
{
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    if (N == 1)
    {
        printf("A");
    }
    else if (N == 2)
    {
        if (arr[0] != arr[1])
            printf("A");
        else
            printf("%d", arr[0]);
    }
    else
    {
        int temp = arr[1] - arr[0];
        int temp2 = arr[2] - arr[1];

        int a;
        if (temp != 0)
            a = temp2 / temp;
        int b = arr[1] - arr[0] * a;

        bool chk = true;
        for (int i = N - 1; i >= 1; i--)
        {
            if (arr[i - 1] * a + b != arr[i])
            {
                chk = false;
                break;
            }
        }
        if (chk)
            printf("%d", arr[N - 1] * a + b);
        else
            printf("B");
    }

    return 0;
}