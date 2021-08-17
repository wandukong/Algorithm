package boj;


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class 서강그라운드_14938 {
	
	static class Pair implements Comparable<Pair> {
		int edge, weight;
		public Pair(int edge, int weight) {
			this.edge = edge;
			this.weight = weight;
		}
		@Override
		public int compareTo(Pair arg0) {
			return this.weight - arg0.weight;
		}
	}
	
	static int N, M, R;
	static ArrayList<ArrayList<Pair>> info = new ArrayList<ArrayList<Pair>>(100);
	static int[] value;

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		R = Integer.parseInt(st.nextToken());

		st = new StringTokenizer(br.readLine());
		value = new int[N + 1];
		for (int i = 1; i <= N; i++)
			value[i] = Integer.parseInt(st.nextToken());

		for (int i = 0; i <= N; i++)
			info.add(new ArrayList<>());

		for (int i = 0; i < R; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());
			info.get(a).add(new Pair(b, c));
			info.get(b).add(new Pair(a, c));
		}
		int ans = 0;
		for (int i = 1; i <= N; i++)
			ans = Math.max(ans, dijkstra(i));
		System.out.println(ans);
	}

	private static int dijkstra(int n) {
		int[] dp = new int[N + 1];
		for (int i = 1; i <= N; i++)
			dp[i] = Integer.MAX_VALUE;

		PriorityQueue<Pair> pq = new PriorityQueue<>();
		pq.add(new Pair(n, 0));
		dp[n] = 0;

		while (!pq.isEmpty()) {
			int cur = pq.peek().edge;
			int cost = pq.peek().weight;
			pq.poll();

			if (dp[cur] < cost)
				continue;
			for (Pair item : info.get(cur)) {
				int next = item.edge;
				int nextCost = cost + item.weight;
				if (dp[next] > nextCost) {
					dp[next] = nextCost;
					pq.add(new Pair(next, nextCost));
				}
			}
		}
		int ret = 0;
		for (int i = 1; i <= N; i++)
			if (dp[i] <= M)
				ret += value[i];
		return ret;
	}
}