package boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class 경쟁적전염_18405 {
	static int[] dr = { 0, 1, 0, -1 };
	static int[] dc = { 1, 0, -1, 0 };

	static class Info implements Comparable<Info> {
		int r, c, cnt, num;

		public Info(int r, int c, int cnt, int num) {
			this.r = r;
			this.c = c;
			this.cnt = cnt;
			this.num = num;
		}

		@Override
		public int compareTo(Info o) {
			if (this.cnt == o.cnt) {
				return this.num - o.num;
			}
			return this.cnt - o.cnt;
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(st.nextToken());
		int arr[][] = new int[N][N];

		PriorityQueue<Info> pq = new PriorityQueue<>();

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < N; j++) {
				int num = Integer.parseInt(st.nextToken());
				if (num != 0) {
					arr[i][j] = num;
					pq.add(new Info(i, j, 0, num));
				}
			}
		}
		st = new StringTokenizer(br.readLine());
		int S = Integer.parseInt(st.nextToken());
		int X = Integer.parseInt(st.nextToken());
		int Y = Integer.parseInt(st.nextToken());

		while (!pq.isEmpty()) {
			int r = pq.peek().r;
			int c = pq.peek().c;
			int cnt = pq.peek().cnt;
			int num = pq.peek().num;
			pq.poll();

			if (cnt == S)
				break;

			for (int i = 0; i < 4; i++) {
				int nr = r + dr[i];
				int nc = c + dc[i];

				if (nr < 0 | nc < 0 || nr >= N || nc >= N)
					continue;
				if (arr[nr][nc] != 0)
					continue;

				arr[nr][nc] = num;
				pq.add(new Info(nr, nc, cnt + 1, num));
			}
		}
		System.out.println(arr[X - 1][Y - 1]);
	}
}
