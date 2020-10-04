#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

int tc, n;

int arr[1005];

int main()
{
    scanf("%d", &tc);

    while (tc--)
    {
        int sum = 0, avg, cnt = 0;
        memset(arr, 0, sizeof(arr));
        scanf("%d", &n);

        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
            sum += arr[i];
        }

        avg = sum / n;

        for (int i = 0; i < n; i++)
            if (arr[i] > avg)
                cnt++;

        printf("%.3f%%\n", cnt / (double)n * 100);
    }

    return 0;
}