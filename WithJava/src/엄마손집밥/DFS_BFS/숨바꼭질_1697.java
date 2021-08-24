package 엄마손집밥.DFS_BFS;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class 숨바꼭질_1697 {
	static int N;
	static int K;
	static class Info {
		int num, cnt;

		public Info(int num, int cnt) {
			this.num = num;
			this.cnt = cnt;
		}
	}

	static boolean[] check = new boolean[100001];

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		System.out.println(bfs(N));
	}

	static int bfs(int cur) {
		Queue<Info> q = new LinkedList<Info>();
		q.add(new Info(cur, 0));
		check[cur] = true;

		while (!q.isEmpty()) {
			cur = q.peek().num;
			int cnt = q.peek().cnt;
			q.poll();
			
			if (cur == K)
				return cnt;
			
			if (cur-1 >= 0 && !check[cur - 1]) {
				q.add(new Info(cur - 1, cnt + 1));
				check[cur-1] = true;
			}
			if (cur+1 <= 100000 && !check[cur + 1]) {
				q.add(new Info(cur + 1, cnt + 1));
				check[cur+1] = true;
			}
			if (cur*2 <= 100000 && !check[cur * 2]) {
				q.add(new Info(cur * 2, cnt + 1));
				check[cur*2] = true;
			}
		}
		return -1;
	}
}