package boj;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class 벽부수고이동하기_2206 {
	static class Info {
		int r, c, cnt;
		int is_breaked;

		Info(int r, int c, int is_breaked, int cnt) {
			this.r = r;
			this.c = c;
			this.is_breaked = is_breaked;
			this.cnt = cnt;
		}
	}

	static int N, M;
	static int[][] arr;
	static boolean[][][] check;
	static int[] dr = { 1, -1, 0, 0 };
	static int[] dc = { 0, 0, 1, -1 };

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());

		arr = new int[N + 1][M + 1];
		check = new boolean[N + 1][M + 1][2];

		for (int i = 1; i <= N; i++) {
			String[] str = br.readLine().split("");
			for (int j = 1; j <= M; j++) {
				arr[i][j] = Integer.parseInt(str[j - 1]);
			}
		}
		bfs();
	}

	static void bfs() {

		Queue<Info> q = new LinkedList<Info>();
		q.add(new Info(1, 1, 0, 1));
		check[1][1][0] = check[1][1][1] = false;

		while (!q.isEmpty()) {
			int r = q.peek().r;
			int c = q.peek().c;
			int is_breaked = q.peek().is_breaked;
			int cnt = q.peek().cnt;
			q.poll();

			if (r == N && c == M) {
				System.out.println(cnt);
				return;
			}

			for (int i = 0; i < 4; i++) {
				int nr = r + dr[i];
				int nc = c + dc[i];

				if (nr <= 0 || nc <= 0 || nr > N || nc > M)
					continue;
				if (arr[nr][nc] == 1) {
					if (is_breaked == 0 & !check[nr][nc][1]) {
						check[nr][nc][1] = true;
						q.add(new Info(nr, nc, 1, cnt + 1));
					}
				} else if (arr[nr][nc] == 0) {
					if (!check[nr][nc][is_breaked]) {
						check[nr][nc][is_breaked] = true;
						q.add(new Info(nr, nc, is_breaked, cnt + 1));
					}
				}
			}
		}
		System.out.println(-1);
	}
}