#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

int main()
{
    // next_permutation() : ���� ������ ���ϰ� true�� ��ȯ�Ѵ�. ���� ������ ���ٸ� false�� ��ȯ�Ѵ�.
    // prev_permutation() : ���� ������ ���ϰ� true�� ��ȯ�Ѵ�. ���� ������ ���ٸ� false�� ��ȯ�Ѵ�.

    vector<int> arr{1, 2, 3, 4, 5};
    do
    {
        for (int i = 0; i < 5; i++)
            printf("%d", arr[i]);
        printf("\n");
    } while (next_permutation(arr.begin(), arr.end()));

    printf("==============================================================\n");

    vector<int> arr2{5, 4, 3, 2, 1};
    do
    {
        for (int i = 0; i < 5; i++)
            printf("%d", arr2[i]);
        printf("\n");
    } while (prev_permutation(arr2.begin(), arr2.end()));

    return 0;
}