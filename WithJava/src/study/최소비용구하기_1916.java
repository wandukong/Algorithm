package study;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class 최소비용구하기_1916 {
	static class Info implements Comparable<Info>{
		int edge, cost;
		Info(int edge, int cost) {
			this.edge = edge;
			this.cost = cost;
		}
		@Override
		public int compareTo(Info o) {
			return this.cost - o.cost;
		}
	}

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N= Integer.parseInt(br.readLine());
		int M= Integer.parseInt(br.readLine());
		PriorityQueue<Info> pq = new PriorityQueue<>();
		ArrayList<ArrayList<Info>> list = new ArrayList<>();	
		for(int i = 0 ; i <= N; i++)
			list.add(new ArrayList<Info>());
		int dp[] = new int[N+1];
		int path[] = new int[N+1];
		Arrays.fill(dp, Integer.MAX_VALUE);
		
		for (int i = 0; i < M; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());
			list.get(a).add(new Info(b,c));
		}
		StringTokenizer st = new StringTokenizer(br.readLine());
		int start = Integer.parseInt(st.nextToken());
		int end = Integer.parseInt(st.nextToken());
		dp[start] = 0;
		pq.add(new Info(start, 0));
		
		while(!pq.isEmpty()) {
			int cur = pq.peek().edge;
			int cost = pq.peek().cost;
			pq.poll();
			
			if(cur == end) {
				System.out.println(dp[cur]);
				ArrayList<Integer> al = new ArrayList<>();
				for(int c = end ; c != start ; c = path[c]) {
					al.add(c);
				}
				al.add(start);
				for(int i : al) {
					System.out.println(i);
				}
				return;
			}
			if(cost > dp[cur])
				continue;
			
			for(Info i : list.get(cur)) {
				int next = i.edge;
				int nextCost = cost + i.cost;
				
				if(dp[next] >= nextCost) {
					dp[next] = nextCost;
					pq.add(new Info(next, nextCost));
					path[next] = cur;
				}
			}
		}
	}
}