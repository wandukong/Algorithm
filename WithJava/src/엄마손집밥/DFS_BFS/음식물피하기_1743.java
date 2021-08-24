package 엄마손집밥.DFS_BFS;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 음식물피하기_1743 {
	static int M, N, K;
	static int[] dr = { 1, -1, 0, 0 };
	static int[] dc = { 0, 0, 1, -1 };
	static char[][] arr;
	static boolean[][] check;
	static int cnt = 0;
	static int answer = 0;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		arr = new char[N+1][M+1];
		check = new boolean[N+1][M+1];
		for(int i = 0 ; i < K ; i++) {
			st = new StringTokenizer(br.readLine());
			int r= Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());
			arr[r][c] = '#';
		}
		
		for(int i = 1 ; i <= N ; i++) {
			for(int j = 1 ; j <= M ; j++) {
				if(arr[i][j]=='#' && !check[i][j]) {
					dfs(i,j);
					answer = Math.max(answer, cnt);
					cnt = 0;
				}
			}
		}
		System.out.println(answer);
	}
	
	static void dfs(int r, int c) {
		check[r][c] = true;
		cnt++;
		for(int i = 0 ; i < 4 ; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if(nr <= 0 || nc <= 0 || nr > N || nc > M)
				continue;
			if(!check[nr][nc] && arr[nr][nc] == '#')
				dfs(nr,nc);
		}
	}
}