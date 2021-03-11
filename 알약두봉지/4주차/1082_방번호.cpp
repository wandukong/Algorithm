#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <string.h>

using namespace std;
int N, M;
int arr[51];
string dp[51];

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
        dp[arr[i]] = '0' + i;
    }
    scanf("%d", &M);

    for (int i = 1; i <= M; i++) // 사용 가능한 돈
    {
        for (int j = N - 1; j >= 0; j--) // 구입할 숫자
        {
            if (i - arr[j] < 0)
                continue;
            else if (i - arr[j] == 0)
                dp[i] = max(to_string(j), dp[i]);
            else if (dp[i - arr[j]] == "")
                dp[i] = max(dp[i], dp[i - 1]);

            string prev = dp[i - arr[j]];
            vector<int> sortArr;
            for (int k = 0; k < prev.size(); k++)
                sortArr.push_back(prev[k] - '0');
            if (!(prev == "0" && j == 0))
                sortArr.push_back(j);
            sort(sortArr.begin(), sortArr.end(), greater<int>());

            string str = "";
            for (int k = 0; k < sortArr.size(); k++)
                str += '0' + sortArr[k];

            if (dp[i].size() < str.size())
                dp[i] = str;
            else if (dp[i].size() == str.size())
            {
                int temp1 = dp[i][0] - '0';
                int temp2 = str[0] - '0';
                if (temp1 < temp2)
                    dp[i] = str;
            }
        }
    }
    printf("%s", dp[M].c_str());
    return 0;
}