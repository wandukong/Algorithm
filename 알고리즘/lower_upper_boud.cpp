//lower_bound
//n���� �̷���� ���� ���տ��� ���ϴ� �� k �̻��� ���� ó������ �����ϴ� ��ġ�� ã���ÿ�
//key���� ������ key������ ū ���� ���� ���� ���� ã���ϴ�.

//upper_bound
//n���� �̷���� ���� ���տ��� ���ϴ� �� k ���� ū ���� ó������ �����ϴ� ��ġ�� ã���ÿ�

#include <iostream>
#include <algorithm> //�������
using namespace std;

int main(void)
{
    int arr[10] = {1, 2, 4, 5, 6, 6, 7, 7, 7, 9};

    cout << "lower_bound(6) : " << lower_bound(arr, arr + 10, 6) - arr << endl;
    cout << "lower_bound(7) : " << lower_bound(arr, arr + 10, 7) - arr << endl;
    cout << "lower_bound(8) : " << lower_bound(arr, arr + 10, 8) - arr << endl;
    cout << "lower_bound(9) : " << lower_bound(arr, arr + 10, 9) - arr << endl;
    cout << "\n";
    cout << "upper_bound(6) : " << upper_bound(arr, arr + 10, 6) - arr << endl;
    cout << "upper_bound(7) : " << upper_bound(arr, arr + 10, 7) - arr << endl;
    cout << "upper_bound(8) : " << upper_bound(arr, arr + 10, 8) - arr << endl;
    cout << "upper_bound(9) : " << upper_bound(arr, arr + 10, 9) - arr << endl;
    return 0;
}
