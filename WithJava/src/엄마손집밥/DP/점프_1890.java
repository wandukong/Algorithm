package 엄마손집밥.DP;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 점프_1890 {
	static int N;
	static int[][] arr;
	static long[][] dp;
	static int dr[] = {0,1};
	static int dc[] = {1,0};
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		StringTokenizer st;
		arr = new int[N][N];
		dp = new long[N][N];
		for(int i = 0 ; i < N ; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j = 0 ; j < N ; j++)
				arr[i][j] = Integer.parseInt(st.nextToken());
		}
		System.out.println(dfs(0,0));
	}
	
	static long dfs(int r, int c) {
		if(r == N-1 && c == N-1)
			return 1;
		if(arr[r][c] == 0)
			return 0;
		if(dp[r][c] != 0)
			return dp[r][c];
		for(int i = 0 ; i < 2; i++) {
			int nr = r + arr[r][c] * dr[i];
			int nc = c + arr[r][c] * dc[i];
			if(nr < 0 || nc < 0 || nr >= N || nc >= N) 
				continue;
			dp[r][c] += dfs(nr,nc);
		}
		return dp[r][c];
	}
}