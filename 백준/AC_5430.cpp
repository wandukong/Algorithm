#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int N, T;

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        deque<int> dq;
        string s, arr, temp = "";
        cin >> s;
        scanf("%d", &N);

        cin >> arr;
        if (N > 0)
            for (int i = 1; i < arr.size(); i++)
            {
                if ('0' <= arr[i] && arr[i] <= '9')
                {
                    temp += arr[i];
                }
                else
                {
                    dq.push_back(stoi(temp));
                    temp = "";
                }
            }
        bool chk = true, reverseChk = true;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'R')
            {
                reverseChk = !reverseChk;
            }
            else
            {
                if (dq.empty())
                {
                    chk = false;
                    break;
                }
                if (reverseChk)
                    dq.pop_front();
                else
                    dq.pop_back();
            }
        }
        if (!chk)
        {
            printf("error\n");
            continue;
        }
        printf("[");
        if (reverseChk)
            for (int i = 0; i < dq.size(); i++)
            {
                if (i == dq.size() - 1)
                    printf("%d", dq[i]);
                else
                    printf("%d,", dq[i]);
            }
        else
        {
            for (int i = dq.size() - 1; i >= 0; i--)
            {
                if (i == 0)
                    printf("%d", dq[i]);
                else
                    printf("%d,", dq[i]);
            }
        }
        printf("]\n");
    }
    return 0;
}