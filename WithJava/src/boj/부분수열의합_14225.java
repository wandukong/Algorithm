package boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class 부분수열의합_14225 {

	static int N;
	static int[] arr;
	static ArrayList<Integer> al = new ArrayList<Integer>();

	static void go(int sum, int cnt) {
		if (cnt == N)
			return;
		sum += arr[cnt];
		al.add(sum);
		go(sum - arr[cnt], cnt + 1);
		go(sum, cnt + 1);
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		arr = new int[N];
		for (int i = 0; i < N; i++)
			arr[i] = Integer.parseInt(st.nextToken());

		go(0, 0);
		Collections.sort(al);
		int searchValue = 1;
		for (int i = 0; i < al.size(); i++) {
			if (searchValue == al.get(i))
				searchValue++;
			else if (searchValue > al.get(i))
				continue;
			else {
				System.out.println(searchValue);
				return;
			}
		}
		System.out.println(searchValue);
	}
}