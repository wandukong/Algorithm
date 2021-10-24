package 엄마손집밥.DFS_BFS;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Gaaaaaaaaaarden_18809 {

	static int N, M, G, R, ans, tempAns;
	static char[][] arr;
	static int[][] check;

	static boolean[] waterChk;
	static List<String> waterOrder = new ArrayList<>();

	static int seedAreaCnt = 0;
	static boolean[] seedChk;
	static List<Info> seedOrder = new ArrayList<>();

	static Queue<Info> q;

	static int[] dr = { -1, 1, 0, 0 };
	static int[] dc = { 0, 0, -1, 1 };

	static class Info {
		int r, c;
		char w;

		public Info(int r, int c) {
			this.r = r;
			this.c = c;
		}

		public Info(int r, int c, char w) {
			this.r = r;
			this.c = c;
			this.w = w;
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		G = Integer.parseInt(st.nextToken());
		R = Integer.parseInt(st.nextToken());

		arr = new char[N][M];
		waterChk = new boolean[G + R];

		waterbf(0, 0);

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < M; j++) {
				arr[i][j] = st.nextToken().charAt(0);
				if (arr[i][j] == '2') {
					seedAreaCnt++;
					seedOrder.add(new Info(i, j));
				}
			}
		}
		seedChk = new boolean[seedAreaCnt];
		seedbf(0, 0);
		System.out.println(ans);
	}

	static void waterbf(int cnt, int loc) {
		if (cnt == G) {
			String temp = "";
			for (int i = 0; i < G + R; i++) {
				if (waterChk[i])
					temp += 'G';
				else
					temp += 'R';
			}
			waterOrder.add(temp);
			return;
		}
		for (int i = loc; i < G + R; i++)
			if (!waterChk[i]) {
				waterChk[i] = true;
				waterbf(cnt + 1, i + 1);
				waterChk[i] = false;
			}
	}

	static void seedbf(int cnt, int loc) {
		if (cnt == R + G) {
			for (String s : waterOrder) {
				int cnt2 = 0;
				q = new LinkedList<>();
				check = new int[N][M];
				char[][] temp = new char[arr.length][arr[0].length];
				for (int i = 0; i < arr.length; i++)
					System.arraycopy(arr[i], 0, temp[i], 0, arr[i].length);

				for (int i = 0; i < seedAreaCnt; i++)
					if (seedChk[i]) {
						int r = seedOrder.get(i).r;
						int c = seedOrder.get(i).c;
						char w = s.charAt(cnt2);
						arr[r][c] = w;
						check[r][c] = 1;
						q.add(new Info(r, c, w));
						cnt2++;
					}
				bfs();
				ans = Math.max(ans, tempAns);

				for (int i = 0; i < arr.length; i++)
					System.arraycopy(temp[i], 0, arr[i], 0, arr[i].length);
			}
		}
		for (int i = loc; i < seedAreaCnt; i++)
			if (!seedChk[i]) {
				seedChk[i] = true;
				seedbf(cnt + 1, i + 1);
				seedChk[i] = false;
			}
	}

	static void bfs() {
		tempAns = 0;

		int sec = 1;
		while (!q.isEmpty()) {
			sec++;
			int qSize = q.size();
			for (int k = 0; k < qSize; k++) {
				int r = q.peek().r;
				int c = q.peek().c;
				char w = q.peek().w;
				q.poll();
				
				if(arr[r][c] == 'F')
					continue;
				
				for (int i = 0; i < 4; i++) {
					int nr = r + dr[i];
					int nc = c + dc[i];

					if (nr < 0 || nc < 0 || nr >= N || nc >= M)
						continue;
					if (arr[nr][nc] == 'F' || arr[nr][nc] == '0')
						continue;
					
					if(arr[nr][nc] == '1' && check[nr][nc] == 0) {
						check[nr][nc] = sec;
						arr[nr][nc] = w;
						q.add(new Info(nr,nc,w));
					}
					else if(arr[nr][nc] == '2' && check[nr][nc] == 0) {
						check[nr][nc] = sec;
						arr[nr][nc] = w;
						q.add(new Info(nr,nc,w));
					}
					else if(arr[nr][nc] == 'G' && w == 'R' && check[nr][nc] == sec) {
						arr[nr][nc] = 'F';
						tempAns++;
					}
					else if(arr[nr][nc] == 'R' && w == 'G' && check[nr][nc] == sec) {
						arr[nr][nc] = 'F';
						tempAns++;
					}
				}
			}
		}
	}
}
