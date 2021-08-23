package boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class 나이트의의동_7562 {
	static boolean[][] check;
	static int sr;
	static int sc;
	static int er;
	static int ec;
	static int N;
	static int[] dr = { -2, -1, 1, 2, 2, 1, -1, -2 };
	static int[] dc = { 1, 2, 2, 1, -1, -2, -2, -1 };

	static class Pos {
		int r, c, cnt;
		public Pos(int r, int c, int cnt) {
			this.r = r;
			this.c = c;
			this.cnt = cnt;
		}
	}

	public static void main(String[] args) throws NumberFormatException, IOException {
		StringBuilder sb = new StringBuilder();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		StringTokenizer st;
		while ((T--) > 0) {
			N = Integer.parseInt(br.readLine());
			st = new StringTokenizer(br.readLine());
			sr = Integer.parseInt(st.nextToken());
			sc = Integer.parseInt(st.nextToken());
			st = new StringTokenizer(br.readLine());
			er = Integer.parseInt(st.nextToken());
			ec = Integer.parseInt(st.nextToken());
			sb.append(bfs() + "\n");
		}
		System.out.println(sb);
	}

	static int bfs() {
		boolean[][] check = new boolean[N][N];
		Queue<Pos> q = new LinkedList<Pos>();
		q.add(new Pos(sr, sc, 0));
		check[sr][sc] = true;

		while (!q.isEmpty()) {
			int r = q.peek().r;
			int c = q.peek().c;
			int cnt = q.peek().cnt;
			q.poll();
			
			if (r == er && c == ec)
				return cnt;
			
			for(int i = 0 ; i < 8 ; i++) {
				int nr = r + dr[i];
				int nc = c + dc[i];
				if(nr < 0 || nc < 0 || nr >= N || nc >= N)
					continue;
				if(!check[nr][nc]) {
					q.add(new Pos(nr,nc,cnt+1));
					check[nr][nc] = true;
				}
			}
		}
		return -1;
	}
}
