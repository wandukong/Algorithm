package 엄마손집밥.DFS_BFS;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class 토마토_7576 {

    static class Pos {
		int r, c;

		public Pos(int r, int c) {
			this.r = r;
			this.c = c;
		}
	}
	static int M, N;
	static int[] dr = { 1, -1, 0, 0 };
	static int[] dc = { 0, 0, 1, -1 };
	static int[][] arr;
	static boolean[][] check;
	static Queue<Pos> q = new LinkedList<Pos>();

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		M = Integer.parseInt(st.nextToken());
		N = Integer.parseInt(st.nextToken());
		arr = new int[N][M];
		check = new boolean[N][M];
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < M; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
				if (arr[i][j] == 1) {
					q.add(new Pos(i, j));
					check[i][j] = true;
				}
			}
		}
		int answer = bfs();
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++) {
				if (arr[i][j] == 0) {
					answer = -1;
					System.out.println(answer);
					return;
				}
				answer = Math.max(answer, arr[i][j]);
			}
		System.out.println(answer-2);
	}

	static int bfs() {
		int cnt = 2;
		while (!q.isEmpty()) {
			int qSize = q.size();
			for (int i = 0; i < qSize; i++) {
				int r = q.peek().r;
				int c = q.peek().c;
				q.poll();

				for (int j = 0; j < 4; j++) {
					int nr = r + dr[j];
					int nc = c + dc[j];

					if (nr < 0 || nc < 0 || nr >= N || nc >= M)
						continue;
					if (arr[nr][nc] == -1 || check[nr][nc] || arr[nr][nc] == 1)
						continue;
					if (!check[nr][nc]) {
						check[nr][nc] = true;
						arr[nr][nc] = cnt;
						q.add(new Pos(nr, nc));
					}
				}
			}
			if(q.isEmpty()) return cnt;
			cnt++;
		}
		return cnt;
	}
}