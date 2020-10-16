#include <iostream>
#include <algorithm>

using namespace std;

int sum, ans1, ans2;
int arr[9];

int main()
{
    for (int i = 0; i < 9; i++)
    {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    for (int i = 0; i < 8; i++)
        for (int j = i + 1; j < 9; j++)
        {
            int temp = sum;
            temp -= (arr[i] + arr[j]);
            if (temp == 100)
                ans1 = arr[i], ans2 = arr[j];
        }
    sort(arr, arr + 9);

    for (int i = 0; i < 9; i++)
        if (arr[i] != ans1 && arr[i] != ans2)
            printf("%d\n", arr[i]);

    return 0;
}