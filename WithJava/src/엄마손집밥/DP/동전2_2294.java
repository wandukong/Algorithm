package 엄마손집밥.DP;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class 동전2_2294 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		int arr[] = new int[N+1];
		int dp[][] = new int[N+1][M+1];
		for(int i = 1 ; i <= N ; i++)
			arr[i] = Integer.parseInt(br.readLine());
		Arrays.sort(arr);
		
		for(int i = 1 ; i <= M ; i++)
			dp[0][i] = Integer.MAX_VALUE;	
		dp[1][0] = 0;
		for(int i = 1 ; i <= N ; i++) {
			for(int j = 1 ; j <= M ; j++) {
				if( j-arr[i] >= 0 && dp[i][j-arr[i]] != Integer.MAX_VALUE ) {
					dp[i][j] = Math.min(dp[i-1][j], dp[i][j-arr[i]]+1);
				}else
					dp[i][j] = dp[i-1][j];
			}
		}
		System.out.println(dp[N][M] == Integer.MAX_VALUE ? -1 : dp[N][M]);
	}

}
