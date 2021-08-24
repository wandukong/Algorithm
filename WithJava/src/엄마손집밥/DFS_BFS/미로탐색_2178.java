package 엄마손집밥.DFS_BFS;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class 미로탐색_2178 {
	static int N;
	static int M;
	static char[][] arr;
	static boolean[][] check;
	static int[] dr = { 1, -1, 0, 0 };
	static int[] dc = { 0, 0, 1, -1 };

	static class Pos {
		int r, c, cnt;

		public Pos(int r, int c, int cnt) {
			this.r = r;
			this.c = c;
			this.cnt = cnt;
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		arr = new char[N][M];
		check = new boolean[N][M];
		for (int i = 0; i < N; i++) {
			String input = br.readLine();
			for (int j = 0; j < M; j++) {
				arr[i][j] = input.charAt(j);
			}
		}
		System.out.println(bfs());
	}

	static int bfs() {
		Queue<Pos> q = new LinkedList<Pos>();
		q.add(new Pos(0, 0, 1));
		check[0][0] = true;

		while (!q.isEmpty()) {
			int r = q.peek().r;
			int c = q.peek().c;
			int cnt = q.peek().cnt;
			q.poll();

			if (r == N - 1 && c == M - 1)
				return cnt;

			for (int i = 0; i < 4; i++) {
				int nr = r + dr[i];
				int nc = c + dc[i];

				if (nr >= N || nc >= M || nr < 0 || nc < 0)
					continue;
				if (!check[nr][nc] && arr[nr][nc] == '1') {
					check[nr][nc] = true;
					q.add(new Pos(nr, nc, cnt+1));
				}
			}
		}
		return -1;
	}
}
