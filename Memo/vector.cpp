#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};

    v.erase(v.begin() + 1, v.begin() + 3); // �ι�° ����° ����  // 1 4 5

    for (int i = 0; i < v.size(); i++)
    {
        printf("%d\n", v[i]);
    }

    v.insert(v.begin() + 1, 3); // 2��° �ڸ��� 3 ���� // 1 3 4 5

    for (int i = 0; i < v.size(); i++)
    {
        printf("%d\n", v[i]);
    }
}