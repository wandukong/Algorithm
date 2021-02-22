#include <iostream>
#include <algorithm>

using namespace std;

int N, M, K, ans;
string arr[51];

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    scanf("%d", &K);

    for (int i = 0; i < N; i++)
    {
        int zeroCnt = 0; // �� �࿡ �ִ� 0�� ����
        int sameCnt = 1; // ���� ������ ���� ���� ����
        for (int j = 0; j < arr[i].size(); j++)
        {
            if (arr[i][j] == '0')
                zeroCnt++;
        }
        if (zeroCnt % 2 != K % 2)
            continue;

        for (int j = 0; j < N; j++)
        {
            if (i != j && arr[i] == arr[j])
                sameCnt++;
        }
        if (zeroCnt <= K && sameCnt > ans)
        {
            ans = sameCnt;
        }
    }
    printf("%d\n", ans);

    return 0;
}