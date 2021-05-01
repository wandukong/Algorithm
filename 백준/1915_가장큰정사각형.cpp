#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int n, m, answer;
int arr[1001][1001];

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%1d", &arr[i][j]);
    answer = arr[0][0];
    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
        {
            if (arr[i][j] != 0)
            {
                arr[i][j] = min(arr[i - 1][j], min(arr[i][j - 1], arr[i - 1][j - 1])) + 1;
                answer = max(answer, arr[i][j]);
            }
        }
    printf("%d\n", answer * answer);
    return 0;
}