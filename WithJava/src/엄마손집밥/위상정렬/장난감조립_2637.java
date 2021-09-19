package 엄마손집밥.위상정렬;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class 장난감조립_2637 {
	static class Info {
		int e, w;
		public Info(int e, int w) {
			this.e = e;
			this.w = w;
		}
	}
	static int N, M, cnt = 0;
	static int[] indegree, outdegree;
	static int[] dp;
	static ArrayList<ArrayList<Info>> graph = new ArrayList<ArrayList<Info>>();

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		M = Integer.parseInt(br.readLine());
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		indegree = new int[N + 1];
		outdegree = new int[N + 1];
		dp = new int[N + 1];
		for (int i = 0; i <= N; i++)
			graph.add(new ArrayList<Info>());
		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
			int a, b, c;
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			c = Integer.parseInt(st.nextToken());
			graph.get(a).add(new Info(b, c));
			indegree[b]++;
			outdegree[a]++;
		}
		
		Queue<Integer> q = new LinkedList<>();
		q.add(N);
		dp[N] = 1;
		while (!q.isEmpty()) {
			int cur = q.poll();
			int cost = dp[cur];
			for (int i = 0; i < graph.get(cur).size(); i++) {
				int next = graph.get(cur).get(i).e;
				int nextCost = graph.get(cur).get(i).w;
				dp[next] += cost * nextCost;
				if ((--indegree[next]) == 0)
					q.add(next);
			}
		}
		for (int i = 1; i <= N; i++)
			if (outdegree[i] == 0)
				sb.append(i + " " + dp[i] + "\n");
		System.out.println(sb);
	}
}