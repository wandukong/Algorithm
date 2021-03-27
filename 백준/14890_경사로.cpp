#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int N, L, ans;
int arr[201][101];
int cnt[11];

int main()
{
    scanf("%d %d", &N, &L);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &arr[i][j]);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            arr[i + N][j] = arr[j][i];
    ans = N * 2;

    for (int i = 0; i < N * 2; i++)
    {
        int cur = 0;
        cnt[arr[i][0]]++;
        int next = 1;
        int lowCnt = 0;
        int lowNum;
        while (cur + next < N)
        {
            if (abs(arr[i][cur] - arr[i][cur + next]) > 1)
            {
                ans--;
                break;
            }
            if (arr[i][cur] > arr[i][cur + next])
            {
                lowNum = arr[i][cur + next];
                for (int j = cur + next; j < cur + next + L; j++)
                {

                    if (arr[i][j] == lowNum)
                    {
                        lowCnt++;
                    }
                }
                if (lowCnt != L)
                {
                    ans--;
                    break;
                }
                else
                {
                    lowCnt = 0;
                    cur = cur + L;
                    next = 1;
                    memset(cnt, 0, sizeof(cnt));
                }
            }
            else if (arr[i][cur] < arr[i][cur + next])
            {
                cnt[arr[i][cur + next]]++;
                if (cnt[arr[i][cur]] < L)
                {
                    ans--;
                    break;
                }
                else
                {
                    cur = cur + next;
                    next = 1;
                }
            }
            else
            {
                cnt[arr[i][cur + next]]++;
                next++;
            }
        }
        memset(cnt, 0, sizeof(cnt));
    }
    printf("%d", ans);
    return 0;
}