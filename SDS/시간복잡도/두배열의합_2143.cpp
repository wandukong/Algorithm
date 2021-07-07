#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, T;
int A[1001], B[1001];
vector<int> AS, BS;

int main()
{
    scanf("%d", &T);
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
        AS.push_back(A[i]);
    }
    scanf("%d", &M);
    for (int i = 0; i < M; i++)
    {
        scanf("%d", &B[i]);
        BS.push_back(B[i]);
    }

    for (int i = 0; i < N - 1; i++)
    {
        int sum = A[i];
        for (int j = i + 1; j < N; j++)
        {
            sum += A[j];
            AS.push_back(sum);
        }
    }
    for (int i = 0; i < M - 1; i++)
    {
        int sum = B[i];
        for (int j = i + 1; j < M; j++)
        {
            sum += B[j];
            BS.push_back(sum);
        }
    }
    sort(AS.begin(), AS.end());
    sort(BS.begin(), BS.end());
    long long ans = 0;
    for (int i = 0; i < AS.size(); i++)
        ans += upper_bound(BS.begin(), BS.end(), T - AS[i]) - lower_bound(BS.begin(), BS.end(), T - AS[i]);
    printf("%lld", ans);
    return 0;
}