#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

string A, B;

int main()
{
    int n;
    string s = "";
    cin >> A >> B;
    n = A.size() > B.size() ? A.size() : B.size();
    int m = abs((int)A.size() - B.size());
    for (int i = 0; i < m; i++)
        if (A.size() > B.size())
            B.insert(B.begin(), '0');
        else
            A.insert(A.begin(), '0');
    bool chk = false;
    for (int i = n - 1; i >= 0; i--)
    {
        int a = A[i] - '0';
        int b = B[i] - '0';
        int sum = a + b;
        sum = chk ? sum + 1 : sum;
        if (sum >= 10)
        {
            s.insert(s.begin(), sum - 10 + '0');
            chk = true;
        }
        else
        {
            s.insert(s.begin(), sum + '0');
            chk = false;
        }
    }
    if (chk)
        s.insert(s.begin(), '1');
    printf("%s", s.c_str());
    return 0;
}