package 엄마손집밥.DFS_BFS;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class 유기농배추_1012 {

	static int M, N, K;
	static int[] dr = { 1, -1, 0, 0 };
	static int[] dc = { 0, 0, 1, -1 };
	static char[][] arr;
	static boolean[][] check;

	static class Pos {
		int r, c;

		public Pos(int r, int c) {
			this.r = r;
			this.c = c;
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		int T = Integer.parseInt(br.readLine());
		while (T-- > 0) {
			int answer = 0;
			st = new StringTokenizer(br.readLine());
			M = Integer.parseInt(st.nextToken());
			N = Integer.parseInt(st.nextToken());
			K = Integer.parseInt(st.nextToken());
			arr = new char[N][M];
			check = new boolean[N][M];

			for (int i = 0; i < K; i++) {
				st = new StringTokenizer(br.readLine());
				int c = Integer.parseInt(st.nextToken());
				int r = Integer.parseInt(st.nextToken());
				arr[r][c] = '@';
			}

			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					if (!check[i][j] && arr[i][j] == '@') {
						bfs(i, j);
						answer++;
					}
				}
			}
			sb.append(answer + "\n");
		}
		System.out.println(sb);
	}

	static void bfs(int r, int c) {
		Queue<Pos> q = new LinkedList<Pos>();
		q.add(new Pos(r, c));

		while (!q.isEmpty()) {
			r = q.peek().r;
			c = q.peek().c;
			q.poll();

			for (int i = 0; i < 4; i++) {
				int nr = r + dr[i];
				int nc = c + dc[i];

				if (nr < 0 || nc < 0 || nr >= N || nc >= M)
					continue;
				if (!check[nr][nc] && arr[nr][nc] == '@') {
					q.add(new Pos(nr, nc));
					check[nr][nc] = true;
				}
			}
		}
	}

}
