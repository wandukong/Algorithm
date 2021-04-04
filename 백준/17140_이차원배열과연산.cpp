#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

int R, C, K, ans = 1, cntR, cntC;
int arr[101][101];
int cnt[101];
vector<pair<int, int>> v;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
        return a.second < b.second;
    else
        return a.first < b.first;
}

void calR()
{
    int maxC = 0;
    for (int i = 1; i <= cntR; i++)
    {
        int maxNum = 0;
        for (int j = 1; j <= cntC; j++)
        {
            if (arr[i][j] == 0)
                continue;
            cnt[arr[i][j]]++;
            maxNum = max(arr[i][j], maxNum);
        }
        for (int j = 1; j <= maxNum; j++)
        {
            if (cnt[j] == 0)
                continue;
            v.push_back({cnt[j], j});
        }
        sort(v.begin(), v.end(), cmp);
        memset(arr[i], 0, sizeof(arr[i]));
        for (int j = 0; j < v.size(); j++)
        {
            if (j == 50)
                break;
            arr[i][(j + 1) * 2 - 1] = v[j].second;
            arr[i][(j + 1) * 2] = v[j].first;
            maxC = max(maxC, (j + 1) * 2);
        }
        v = vector<pair<int, int>>();
        memset(cnt, 0, sizeof(cnt));
    }
    cntC = maxC;
}

void calC()
{
    int maxR = 0;
    for (int i = 1; i <= cntC; i++)
    {
        int maxNum = 0;
        for (int j = 1; j <= cntR; j++)
        {
            if (arr[j][i] == 0)
                continue;
            cnt[arr[j][i]]++;
            maxNum = max(arr[j][i], maxNum);
        }
        for (int j = 1; j <= maxNum; j++)
        {
            if (cnt[j] == 0)
                continue;
            v.push_back({cnt[j], j});
        }
        sort(v.begin(), v.end(), cmp);
        for (int j = 1; j <= cntR; j++)
            arr[j][i] = 0;

        for (int j = 0; j < v.size(); j++)
        {
            if (j == 50)
                break;
            arr[(j + 1) * 2 - 1][i] = v[j].second;
            arr[(j + 1) * 2][i] = v[j].first;

            maxR = max(maxR, (j + 1) * 2);
        }
        v = vector<pair<int, int>>();
        memset(cnt, 0, sizeof(cnt));
    }
    cntR = maxR;
}

int main()
{
    scanf("%d %d %d", &R, &C, &K);

    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= 3; j++)
            scanf("%d", &arr[i][j]);

    cntR = 3, cntC = 3;
    if (arr[R][C] == K)
    {
        printf("0");
        return 0;
    }

    while (true)
    {
        if (cntR >= cntC)
            calR();
        else
            calC();
        if (arr[R][C] == K)
            break;
        if (ans > 100)
        {
            printf("-1");
            return 0;
        }
        ans++;
    }

    printf("%d", ans);
    return 0;
}