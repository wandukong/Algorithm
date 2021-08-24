package 엄마손집밥.완전탐색_분할정복;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class 부분수열의합_1182 {

	static int N, S, ans = 0;
	static int[] arr;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		S = Integer.parseInt(st.nextToken());
		arr = new int[N];

		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++)
			arr[i] = Integer.parseInt(st.nextToken());
		go(0,0);
		System.out.println(ans);
	}
	
	static void go(int idx, int sum) {
		if(idx == N) return;
		sum+=arr[idx];
		if(sum == S)
			ans++;
		go(idx+1, sum - arr[idx]);
		go(idx+1, sum);
	}
}
