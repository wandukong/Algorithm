#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, arr[101], cnt[100][80001];
bool isNotPrime[1000001];
vector<int> prime;
int answer1, answer2, totalCnt[80001], gcdCnt[80001];

int main()
{
    for (int i = 2; i <= 1000000; i++)
    {
        if (isNotPrime[i])
            continue;
        for (int j = i + i; j <= 1000000; j += i)
            isNotPrime[j] = true;
    }
    for (int i = 2; i <= 1000000; i++)
        if (!isNotPrime[i])
            prime.push_back(i);

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    for (int i = 0; i < N; i++)
    {
        int num = arr[i];
        for (int j = 0; j < prime.size(); j++)
        {
            while (num % prime[j] == 0)
            {
                cnt[i][j]++;
                totalCnt[j]++;
                num /= prime[j];
            }
        }
    }
    for (int i = 0; i < prime.size(); i++) // 최대공약수의 소수 갯수 새기
        gcdCnt[i] = totalCnt[i] / N;

    answer1 = 1;
    for (int i = 0; i < prime.size(); i++)
    {
        for (int j = 0; j < gcdCnt[i]; j++) // 최대공약수 구하기
            answer1 *= prime[i];

        for (int j = 0; j < N; j++)
            if (cnt[j][i] < gcdCnt[i]) // 최대공약수의 소수가 부족한지 체크 후, 더하기
                answer2 += gcdCnt[i] - cnt[j][i];
    }
    printf("%d %d", answer1, answer2);
    return 0;
}