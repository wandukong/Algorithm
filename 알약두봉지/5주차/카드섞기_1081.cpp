#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int N, ans;
int endValue = 3 * 5 * 7 * 8 * 11 * 13 + 1; // �� ����Ŭ�� �ֱ⸦ ���� �� �� ���� ū ���� ������ ��� + 1
bool chk;

int P[50]; // ��ǥ�� �ϴ� ī�� ���
int S[50]; // ī�� �̵� ��Ģ

int cur[50];  // ���� ī�� ���
int temp[50]; // �ӽ� ī�� ���

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