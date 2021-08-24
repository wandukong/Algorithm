package 엄마손집밥.DFS_BFS;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 알파벳_1987 {

	static int R;
	static int C;
	static int answer = 1;
	static char[][] arr;
	static boolean[][] check;
	static boolean[] used = new boolean[26];

	static int[] dr = { 1, -1, 0, 0 };
	static int[] dc = { 0, 0, 1, -1 };

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());

		arr = new char[R][C];
		check = new boolean[R][C];
		for (int i = 0; i < R; i++) {
			String str = br.readLine();
			for (int j = 0; j < C; j++)
				arr[i][j] = str.charAt(j);
		}
		dfs(0,0, 1);
		System.out.println(answer);
	}

	static void dfs(int r, int c, int cnt) {
		check[r][c] = true;
		used[arr[r][c]-'A'] = true;
		answer = Math.max(answer, cnt);
		
		for(int i = 0 ; i < 4 ; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if(nr < 0 || nc < 0 || nr>=R || nc >= C)
				continue;
			if(!check[nr][nc] && !used[arr[nr][nc]-'A']) {
				used[arr[nr][nc]-'A'] = true;
				check[nr][nc] = true;
				dfs(nr,nc, cnt+1);
				used[arr[nr][nc]-'A'] = false;
				check[nr][nc] = false;
			}
		}
	}
}
