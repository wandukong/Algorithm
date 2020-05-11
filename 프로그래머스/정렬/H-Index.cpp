#include <string>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

	vector<int> citations = { 3, 0, 6, 1, 5 };

	int answer = 0;

	sort(citations.begin(), citations.end());
	int num = citations[citations.size() - 1];

	for (int i = 0; i <= num; i++) {
		int cnt = 0;
		for (int j = citations.size() - 1; j >= 0; j--) {
			if (citations[j] >= i)
				cnt++;
			else break;
		}
		if (cnt >= i)
			answer = i;
		else break;
	}
	
	printf("%d\n",answer);

	return 0;
}