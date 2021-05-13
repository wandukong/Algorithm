#include <string>
#include <vector>

using namespace std;

int dp[100001];

int solution(int n, vector<int> money)
{
    int answer = 0;
    for (int i = 0; i <= n; i++)
        if (i % money[0] == 0)
            dp[i] = 1;
        else
            dp[i] = 0;

    for (int i = 1; i < money.size(); i++)
        for (int j = money[i]; j <= n; j++)
            dp[j] += dp[j - money[i]];

    answer = dp[n] % 1000000007;
    return answer;
}

void print(int n, vector<int> money, int answer)
{
    if (answer == solution(n, money))
        printf("정답\n");
    else
        printf("오답\n");
}

int main()
{
    print(5, {1, 2, 5}, 4);
    return 0;
}