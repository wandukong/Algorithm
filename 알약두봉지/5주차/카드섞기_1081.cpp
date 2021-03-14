#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int N, ans;
int endValue = 3 * 5 * 7 * 8 * 11 * 13 + 1; // 각 사이클의 주기를 곱한 것 중 가장 큰 값이 나오는 경우 + 1
bool chk;

int P[50]; // 목표로 하는 카드 배분
int S[50]; // 카드 이동 규칙

int cur[50];  // 현재 카드 배분
int temp[50]; // 임시 카드 배분

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &P[i]);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &S[i]);
        temp[i] = cur[i] = i % 3;
    }

    while (true)
    {
        chk = false;
        for (int j = 0; j < N; j++)
            if (temp[j] != P[j])
                chk = true; 
        if (chk)
            ans++;
        else
            break;
        for (int j = 0; j < N; j++)
            temp[j] = cur[S[j]];
        copy(temp, temp + N, cur);
        if (ans > endValue)
        {
            ans = -1;
            break;
        }
    }
    printf("%d", ans);
    return 0;
}