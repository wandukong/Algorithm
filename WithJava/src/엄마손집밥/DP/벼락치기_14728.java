package 엄마손집밥.DP;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 벼락치기_14728 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int N = Integer.parseInt(st.nextToken());
		int T = Integer.parseInt(st.nextToken());
		
		int time[] = new int[N+1];
		int score[] = new int[N+1];
		int dp[][] = new int[N+1][T+1];

		for (int i = 1; i <= N; i++) {
			st = new StringTokenizer(br.readLine());
			time[i] = Integer.parseInt(st.nextToken());
			score[i] = Integer.parseInt(st.nextToken());
		}
		
		for(int i = 1 ; i <= N ; i++) 
			for(int j = 1 ; j <= T ; j++) {
				if(j-time[i] >= 0) 
					dp[i][j] = Math.max(dp[i-1][j], dp[i-1][j-time[i]] + score[i]);
				else 
					dp[i][j] = dp[i-1][j];
			}
		System.out.println(dp[N][T]);
	}
}