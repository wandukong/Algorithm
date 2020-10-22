#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> v = {1, 2, 3, 4, 5};

vector<string> gems{"DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"};
vector<string> gems2{"DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"};
int main()
{
    //***********************************************
    // 1. Ư�� ��ġ �� �����ϱ�.
    //***********************************************
    v.erase(v.begin() + 1, v.begin() + 3); // �ι�° ����° ����  // 1 4 5
    // v.erase(v.begin() + n, v.begin() + m)  v[n]~v[m-1] ����

    for (int i = 0; i < v.size(); i++)
        printf("%d ", v[i]);
    printf("\n");

    //***********************************************
    // 2. Ư�� ��ġ �� �����ϱ�.
    //***********************************************
    v.insert(v.begin() + 1, 3); // 2��° �ڸ��� 3 ���� // 1 3 4 5

    for (int i = 0; i < v.size(); i++)
        printf("%d ", v[i]);
    printf("\n");

    //***********************************************
    // 3. Ư�� �� �����ϱ�
    //***********************************************
    v.erase(remove(v.begin(), v.end(), 1), v.end()); // �� 1 ����.
    for (int i = 0; i < v.size(); i++)
        printf("%d ", v[i]);
    printf("\n");

    gems.erase(remove(gems.begin(), gems.end(), "DIA"), gems.end()); // �ߺ� ���� �� ��������
    for (int i = 0; i < gems.size(); i++)
        printf("%s ", gems[i].c_str());
    printf("\n");

    //***********************************************
    // 4. �ߺ� �� �����ϱ�
    //***********************************************

    sort(gems2.begin(), gems2.end());
    gems2.erase(unique(gems2.begin(), gems2.end()), gems2.end()); // �ߺ� ���� �� ��������
    for (int i = 0; i < gems2.size(); i++)
        printf("%s ", gems2[i].c_str());
    printf("\n");

    //***********************************************
    // 5. Ư�� �� ��ġ ã�� find(v.begin(), v.end(), 5) - v.begin()
    //***********************************************

    for (int i = 0; i < v.size(); i++)
        printf("%d ", v[i]);
    printf("\n");

    find(v.begin(), v.end(), 5) - v.begin();
    printf("5. %d\n", find(v.begin(), v.end(), 5) - v.begin());
}