package 엄마손집밥.DP;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 이동하기_11048 {
	static int N, M;
	static int[][] arr, dp;
	static int[] dr = { 0, 1, 1 };
	static int[] dc = { 1, 0, 1 };

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		arr = new int[N][M];
		dp = new int[N][M];
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < M; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
				dp[i][j] = -1;
			}
		}
		System.out.println(dfs(0, 0));
	}

	static int dfs(int r, int c) {
		if (r >= N || c >= M || r < 0 || c < 0)
			return 0;
		if(dp[r][c] != -1)
			return dp[r][c];
		return dp[r][c] = Math.max(dfs(r+1,c), Math.max(dfs(r,c+1), dfs(r+1,c+1))) + arr[r][c];
	}
}