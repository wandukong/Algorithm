#include <algorithm>
#include <iostream>

using namespace std;

string A, B;
int ans = 987654321;

int main()
{
    cin >> A >> B;
    for (int i = 0; i <= B.size() - A.size(); i++)
    {
        int cnt = 0;
        for (int j = 0; j < A.size(); j++)
            if (B[j + i] != A[j])
                cnt++;
        ans = min(ans, cnt);
    }
    printf("%d", ans);
    return 0;
}