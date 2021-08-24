package 엄마손집밥.DFS_BFS;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 미친로봇_1405 {
	static int N;
	static int[] dr = { 0, 0, 1, -1 };
	static int[] dc = { 1, -1, 0, 0 };
	static double[] percentages = new double[4];
	static int[][] arr = new int[29][29]; // 0~28;
	static double[][] result = new double[29][29];
	static boolean[][] check = new boolean[29][29]; // 0~28;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		for (int i = 0; i < 4; i++) 
			percentages[i] = (double) (Integer.parseInt(st.nextToken()) / 100.0);
		
		dfs(14, 14, 0, 1.0);
		double answer = 0;
		for (int i = 0; i < 29; i++)
			for (int j = 0; j < 29; j++)
				answer += result[i][j];
		System.out.println(answer);
	}

	static void dfs(int r, int c, int cnt, double res) {
		check[r][c] = true;
		if (cnt == N) {
			result[r][c] += res;
			return;
		}
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (!check[nr][nc]) {
				dfs(nr, nc, cnt + 1, res * percentages[i]);
				check[nr][nc] = false;
			}
		}
	}
}