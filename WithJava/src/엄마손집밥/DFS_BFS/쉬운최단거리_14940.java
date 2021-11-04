package 엄마손집밥.DFS_BFS;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class 쉬운최단거리_14940 {
	static int[] dr = { 1, -1, 0, 0 };
	static int[] dc = { 0, 0, 1, -1 };
	static int N, M;
	static int arr[][], check[][];
	static Queue<Info> q = new LinkedList<>();

	static class Info {
		int r, c;

		public Info(int r, int c) {
			this.r = r;
			this.c = c;
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		arr = new int[N][M];
		check = new int[N][M];

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < M; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
				if (arr[i][j] == 2)
					q.add(new Info(i, j));
			}
		}
		bfs();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arr[i][j] == 0)
					System.out.print("0 ");
				else if (arr[i][j] == 1 && check[i][j] == 0)
					System.out.print("-1 ");
				else
					System.out.print(check[i][j] + " ");
			}
			System.out.println();
		}
	}

	static void bfs() {

		while (!q.isEmpty()) {
			int r = q.peek().r;
			int c = q.peek().c;
			q.poll();

			for (int i = 0; i < 4; i++) {
				int nr = r + dr[i];
				int nc = c + dc[i];

				if (nr < 0 || nc < 0 || nr >= N || nc >= M)
					continue;

				if (arr[nr][nc] == 0 || arr[nr][nc] == 2)
					continue;

				if (check[nr][nc] > check[r][c] + 1 || check[nr][nc] == 0) {
					q.add(new Info(nr, nc));
					check[nr][nc] = check[r][c] + 1;
				}
			}
		}
	}
}
