#include <iostream>
#include <algorithm>

using namespace std;

int N, ans;
long long height[55];
double slope[55];

int main()
{
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%lld", &height[i]);

    for (int i = 1; i <= N; i++)
    {
        int cnt = 0;
        double tempSlope = 0.0;
        bool start = false;

        for (int j = i - 1; j >= 1; j--) // 현재 빌딩 왼쪽 부분
        {
            slope[j] = (double)(height[i] - height[j]) / (double)(i - j);
            if (!start || (start && tempSlope > slope[j]))
            {
                tempSlope = slope[j];
                cnt++;
                start = true;
            }
        }
        start = false;
        tempSlope = 0.0;
        for (int j = i + 1; j <= N; j++) // 현재 빌딩 오른쪽 부분
        {
            slope[j] = (double)(height[i] - height[j]) / (double)(i - j);
            if (!start || (start && tempSlope < slope[j]))
            {
                tempSlope = slope[j];
                cnt++;
                start = true;
            }
        }
        ans = max(ans, cnt);
    }
    printf("%d\n", ans);
    return 0;
}