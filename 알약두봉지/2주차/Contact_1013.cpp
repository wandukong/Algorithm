#include <iostream>
#include <algorithm>

using namespace std;

int N;
string str;

int main()
{
    scanf("%d", &N);
    while (N--)
    {
        cin >> str;
        int i = 0;
        bool first = false, second = false; // 첫번째, 두번째 조건 시작 여부
        bool chk = false;                   // 끝이 0으로 끝나는지 검사
        int zeroCheck = 0;                  // 첫번째 조건 0두개 왔는지 확인

        for (; i < str.size(); i++)
        {
            int tempStr = str[i] - '0';
            int prevStr = -1; //앞 값
            if (i != 0)
                prevStr = str[i - 1] - '0';
            int prevStr2 = -1; // 앞앞 값
            if (i > 1)
                prevStr2 = str[i - 2] - '0';
            int nextStr = -1; // 다음 값
            if (i + 1 <= str.size() - 1)
                nextStr = str[i + 1] - '0';

            if (!first && !second) // 조건 확인
            {
                if (tempStr) // 1이면 첫번째 조건 시작
                {
                    first = true;
                    continue;
                }
                else // 0이면 두번째 조건 시작
                {
                    second = true;
                    if (prevStr2 == 1 && prevStr == 1 && nextStr == 0)
                    {
                        first = true;
                        second = false;
                        zeroCheck = 1;
                    }
                    continue;
                }
            }
            else if (second && tempStr) // 두번째 조건 끝
            {
                second = false;
                continue;
            }
            else if (first)
            {
                if (zeroCheck >= 2 && tempStr) // 0이 2번 이상오고, 현재 값이 1이 온 경우
                {
                    if (nextStr == 1)
                        continue;          // 다음 값이 1이면 첫번째 조건 진행
                    else if (nextStr == 0) // 다음 값이 0이면 첫번째 조건 끝
                    {
                        zeroCheck = 0;
                        first = false;
                        continue;
                    }
                    else if (nextStr == -1) // 다음 값이 없을 경우, 첫번째 조건 끝 -> 첫번째 조건 부합.
                    {
                        printf("YES\n");
                        chk = true;
                        break;
                    }
                }
                else if (!tempStr) // 0이면 첫번째 조건 진행
                {
                    zeroCheck++;
                    continue;
                }
                else
                    break; // 0 없이 1이 연속으로 나올때
            }
            else
                break;
        }
        if (str[str.size() - 1] == '0')
            printf("NO\n");
        else if (!chk)
            if (!first && !second && i == str.size())
                printf("YES\n");
            else
                printf("NO\n");
    }
    return 0;
}