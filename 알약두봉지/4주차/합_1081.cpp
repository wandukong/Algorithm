#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
long long L, U;

int sumN(int num)
{
    return (num * (num + 1)) / 2;
}

long long solve(long long num)
{
    if (num <= 0)
        return 0;
    long long cnt = 1; // �ڸ���
    long long sum = 0;
    int cnt2 = 0;

    string str = to_string(num);
    int w = str.size(); // ���� ��ġ

    while (w)
    {
        long long n = num;
        long long q, r;             // ��� ������
        int loc = str[w - 1] - '0'; // ���� ��ġ�� ��

        q = n / (cnt * 10);
        r = n % cnt;

        if (cnt != 1)
        {
            for (int i = 0; i < cnt2; i++)
                q *= 10;
            sum += sumN(loc - 1) * cnt; // �ش� ������ �ش� �ڸ��� �������� ��� ��
            sum += loc * (r + 1);       // ���� ��ġ�� * �ش� �ڸ��� �Ʒ��� ���� ����
        }
        else
        {
            sum += sumN(loc);
        }
        sum += q * 45;
        cnt *= 10;
        cnt2++;
        w--;
    }
    return sum;
}

int main()
{
    scanf("%lld %lld", &L, &U);
    printf("%lld", solve(U) - solve(L - 1));
    return 0;
}
