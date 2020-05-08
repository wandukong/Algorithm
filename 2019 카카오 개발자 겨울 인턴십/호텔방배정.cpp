#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<long long, long long> check;

long long go(long long number) {
	if (check[number] == 0) return number;
	else return check[number] = go(check[number]);
}


int main() {
	vector<long long> room_number = { 1, 3, 4, 1, 3, 1 };
	long long k = 10;

	vector<long long> answer;

	for (long long number : room_number) {
		long long room = go(number);
		answer.push_back(room);
		check[room] = room + 1;
	}

	for (int i = 0; i < answer.size(); i++) {
		printf("%d\n", answer[i]);
	}

	return 0;
}