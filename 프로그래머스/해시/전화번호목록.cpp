#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;


int main() {
	vector<string> phone_book = {"119", "97674223", "1195524421"};

	bool answer = true;

	sort(phone_book.begin(), phone_book.end());

	for (int i = 0; i < phone_book.size() - 1; i++) 
		if (phone_book[i + 1].find(phone_book[i], 0) != string::npos)
			answer = false;
	
	printf("%s\n", answer ? "true" : "false");

	return 0;
}