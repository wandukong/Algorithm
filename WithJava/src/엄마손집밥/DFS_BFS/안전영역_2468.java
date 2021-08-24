package 엄마손집밥.DFS_BFS;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 안전영역_2468 {
	static int N;
	static int[] dr = { 1, -1, 0, 0 };
	static int[] dc = { 0, 0, 1, -1 };
	static int[][] arr;
	static boolean[][] check;
	static int answer = 0;

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		StringTokenizer st;
		arr = new int[N][N];	
		check= new boolean[N][N];

		int maxHeight = 1, minHeight= 101;
		for (int i = 0; i < N; i++) {
			 st = new StringTokenizer(br.readLine()); 
		 	for (int j = 0; j < N; j++) {
		 		arr[i][j] = Integer.parseInt(st.nextToken());
		 		maxHeight = Math.max(maxHeight, arr[i][j]);
		 		minHeight = Math.min(minHeight, arr[i][j]);
		 	}
		}
		for(int h = 100 ; h >= 1 ; h--) {
			int cnt = 0;
			for (int i = 0; i < N; i++) 
				for (int j = 0; j < N; j++) 
					if(!check[i][j] && arr[i][j] > h) {
						dfs(i,j, h);
						cnt++;
					}
			answer = Math.max(cnt, answer);
			check= new boolean[N][N];
		}
		System.out.println(answer);
	}
	
	static void dfs(int r, int c, int h) {
		check[r][c] = true;
		for(int i = 0 ; i < 4 ; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if(nr < 0 || nc < 0 || nr >= N || nc>= N)
				continue;
			if(!check[nr][nc] && arr[nr][nc] > h)
				dfs(nr,nc, h);
		}
	}
}