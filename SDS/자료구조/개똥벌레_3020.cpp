#include <iostream>
#include <algorithm>

using namespace std;

int N, H, ans, cnt;
int sum[500001];

int main()
{
    scanf("%d %d", &N, &H);
    for (int i = 0; i < N; i++)
    {
        int bar;
        scanf("%d", &bar);
        if (i & 1) // Ȧ
            sum[H - bar + 1]++;
        else //¦
        {
            sum[1]++;
            sum[bar + 1]--;
        }
    }
    ans = -1;
    for (int i = 1; i <= H; i++)
    {
        sum[i] += sum[i - 1];
        if (ans == -1 || sum[i] < ans)
        {
            ans = sum[i];
            cnt = 1;
        }
        else if (sum[i] == ans)
            cnt++;
    }
    printf("%d %d", ans, cnt);
    return 0;
}