//lower_bound
//n개로 이루어진 정수 집합에서 원하는 수 k 이상인 수가 처음으로 등장하는 위치를 찾으시오
//key값이 없으면 key값보다 큰 가장 작은 정수 값을 찾습니다.

//upper_bound
//n개로 이루어진 정수 집합에서 원하는 수 k 보다 큰 수가 처음으로 등장하는 위치를 찾으시오

#include <iostream>
#include <algorithm> //헤더파일
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
