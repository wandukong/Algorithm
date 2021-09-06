package 엄마손집밥.DP;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 가장긴증가하는부분수열_11053 {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		int[] arr = new int[N];
		int[] dp = new int[N];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i = 0 ; i < N ; i++)
			arr[i] = Integer.parseInt(st.nextToken());
		
		int ans = 0;
		for(int i = 0 ; i < N ; i++) {
			dp[i] = 1;
			for(int j = 0 ; j < i ; j++) {
				if(arr[j] < arr[i] && dp[i] < dp[j] + 1) {
					dp[i] = dp[j] + 1;
				}
			}
			ans = Math.max(ans, dp[i]);
		}
		System.out.println(ans);
	}
}