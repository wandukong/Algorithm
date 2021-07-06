#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
vector<int> A, B;

int binarySearch(int num)
{
    int left = 0, right = N - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (A[mid] <= num)
        {
            left = mid + 1;
            if (A[mid] == num)
                return 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return 0;
}

int main()
{
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        int a;
        scanf("%d", &a);
        A.push_back(a);
    }
    scanf("%d", &M);
    for (int i = 0; i < M; i++)
    {
        int a;
        scanf("%d", &a);
        B.push_back(a);
    }
    sort(A.begin(), A.end());
    for (int i = 0; i < B.size(); i++)
        printf("%d\n", binarySearch(B[i]));
    return 0;
}