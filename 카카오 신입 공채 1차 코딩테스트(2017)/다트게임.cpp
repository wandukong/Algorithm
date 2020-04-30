#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <math.h>

using namespace std;

int arr[4];
char str[10];


int main() {
	int cnt = 0;
	scanf("%s", str);

	for(int i = 0 ; i < strlen(str) ; i++) {

		if (48 <= str[i] && str[i] <= 57) {
			cnt++;
			arr[cnt] = str[i] - 48;
			if (str[i + 1] == 48)
				arr[cnt] *= 10;
		}
		else if (str[i] == 'D') 
			arr[cnt] = pow(arr[cnt],2);
		
		else if (str[i] == 'T') 
			arr[cnt] = pow(arr[cnt], 3);

		else if (str[i] == '*') {
			arr[cnt] = arr[cnt] * 2;
			if(cnt != 1)
				arr[cnt-1] = arr[cnt-1] * 2;
		}
		else if (str[i] == '#')
			arr[cnt] = arr[cnt]  * (- 1);	
	}
	printf("%d", arr[1] + arr[2] + arr[3]);

	return 0;
}
