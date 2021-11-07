package 엄마손집밥.DFS_BFS;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class 진우의민트초코우유_20208 {

	static int N, M, H, sr, sc, ans;
	static int arr[][];
	static boolean chk[][];
	static List<Info> mincho = new ArrayList<>();

	static class Info {
		int r, c;
		boolean chk;

		public Info(int r, int c, boolean chk) {
			this.r = r;
			this.c = c;
			this.chk = chk;
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		H = Integer.parseInt(st.nextToken());
		arr = new int[N][N];
		chk = new boolean[N][N];

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < N; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
				if (arr[i][j] == 1) {
					sr = i;
					sc = j;
				} else if (arr[i][j] == 2) {
					mincho.add(new Info(i, j, false));
				}
			}
		}
		dfs(sr, sc, M, 0);
		System.out.println(ans);
	}

	static void dfs(int r, int c, int m, int e) { // m : 남은 체력 / e : 먹은 민초

		if(m <= 0)
			return;
		
		if (Math.abs(r - sr) + Math.abs(c - sc) <= m)
			ans = Math.max(ans, e);
		
		if(e == mincho.size())
			return;

		for (Info info : mincho) {
			int nr = info.r;
			int nc = info.c;

			int d = Math.abs(r - nr) + Math.abs(c - nc);
			if (d <= m) {
				if (!info.chk) {
					info.chk = true;
					dfs(info.r, info.c, m - d + H, e + 1);
					info.chk = true;
				}
			}

		}

	}
}
