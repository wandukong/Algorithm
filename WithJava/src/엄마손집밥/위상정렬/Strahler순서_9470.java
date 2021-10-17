package 엄마손집밥.위상정렬;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Strahler순서_9470 {
	static public class Info {
		int node, value;

		public Info(int node, int value) {
			this.node = node;
			this.value = value;
		}
	}
	static int[] indegree;
	static ArrayList<ArrayList<Integer>> graph;
	static ArrayList<ArrayList<Integer>> maxValue;
	static Queue<Info> q;

	public static void main(String[] args) throws NumberFormatException, IOException {
		StringBuilder sb = new StringBuilder();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());

		while (T-- > 0) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int K = Integer.parseInt(st.nextToken());
			int M = Integer.parseInt(st.nextToken());
			int P = Integer.parseInt(st.nextToken());
			indegree = new int[M + 1];
			q = new LinkedList<Info>();
			graph = new ArrayList<ArrayList<Integer>>();
			maxValue = new ArrayList<ArrayList<Integer>>();
			for (int i = 0; i <= M; i++) {
				graph.add(new ArrayList<Integer>());
				maxValue.add(new ArrayList<Integer>());
			}
			for (int i = 0; i < P; i++) {
				st = new StringTokenizer(br.readLine());
				int a = Integer.parseInt(st.nextToken());
				int b = Integer.parseInt(st.nextToken());
				graph.get(a).add(b);
				indegree[b]++;
			}
			for (int i = 1; i <= M; i++) 
				if (indegree[i] == 0)
					q.add(new Info(i, 1));
			int ans = 0;
			while (!q.isEmpty()) {
				int cur = q.peek().node;
				int value = q.peek().value;
				q.poll();
				if(cur==M)
					ans = value;
				for (int next : graph.get(cur)) {
					maxValue.get(next).add(value);
					if (--indegree[next] == 0) {
						Collections.sort(maxValue.get(next), Collections.reverseOrder());
						int maxValueNum = maxValue.get(next).get(0);
						if (maxValue.get(next).size() > 1 && maxValueNum == maxValue.get(next).get(1))
							q.add(new Info(next, maxValueNum + 1));
						else
							q.add(new Info(next, maxValueNum));
					}

				}
			}
			sb.append(K + " " + ans + "\n");
		}
		System.out.print(sb);
	}

}
