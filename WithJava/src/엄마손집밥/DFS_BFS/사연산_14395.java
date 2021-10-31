package 엄마손집밥.DFS_BFS;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;
import java.util.StringTokenizer;

public class 사연산_14395 {

	static long S, T;
	static Map<Long, Boolean> map = new HashMap<>();
	static char[] op = { '*', '+', '-', '/' };
	static boolean ansChk = false;
	static String answer = "";

	static public class Info {
		Long number;
		String str;

		public Info(Long number, String str) {
			this.number = number;
			this.str = str;
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		S = Integer.parseInt(st.nextToken());
		T = Integer.parseInt(st.nextToken());

		if (S == T)
			System.out.println(0);
		else {
			bfs();
			if (!ansChk)
				System.out.println(-1);
			else
				System.out.println(answer);
		}
	}

	static long cal(int idx, long num) {
		if (idx == 0)
			return num * num;
		else if (idx == 1)
			return num + num;
		else if (idx == 2)
			return num - num;
		else
			return num / num;
	}

	static void bfs() {
		Queue<Info> q = new LinkedList<>();
		q.add(new Info(S, ""));
		map.put(S, true);
		while (!q.isEmpty()) {
			long cur = q.peek().number;
			String str = q.peek().str;
			q.poll();

			for (int i = 0; i < 4; i++) {
				if (i != 3 || cur != 0) {
					long next = cal(i, cur);
					if (!map.containsKey(next)) {
						map.put(next, true);
						String nextStr = str + op[i];
						if (next == T) {
							answer = nextStr;
							ansChk = true;
							return;
						}
						q.add(new Info(next, nextStr));
					}
				}
			}
		}
	}
}
