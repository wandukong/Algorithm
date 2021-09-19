package 엄마손집밥.위상정렬;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class 게임개발_1516 {

	static class Info {
		int edge, time;
		public Info(int edge, int time) {
			this.edge = edge;
			this.time = time;
		}
	}
	static ArrayList<ArrayList<Integer>> graph = new ArrayList<ArrayList<Integer>>();
	static int[] indegree, dp, arr;
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int N = Integer.parseInt(br.readLine());
		indegree = new int[N + 1];
		arr = new int[N+1];
		dp = new int[N + 1];
		for (int i = 0; i <= N; i++) 
			graph.add(new ArrayList<>());
		for (int i = 1; i <= N; i++) {
			st = new StringTokenizer(br.readLine());
			int time = Integer.parseInt(st.nextToken());
			arr[i] = time;
			while (true) {
				int num = Integer.parseInt(st.nextToken());
				if (num == -1)
					break;
				graph.get(num).add(i);	
				indegree[i]++;
			}
		}
		
		Queue<Info> q = new LinkedList<>();
		for(int i = 1 ; i <= N ; i++)
			if(indegree[i]==0) {
				q.add(new Info(i,arr[i]));
				dp[i] = arr[i];
			}
		
		while(!q.isEmpty()) {
			int cur = q.peek().edge;
			int time = q.peek().time;
			q.poll();
			
			for(int i = 0 ; i < graph.get(cur).size() ; i++) {
				int next = graph.get(cur).get(i);
				int nextTime = time + arr[next];
				if(dp[next] < nextTime)
					dp[next] = nextTime;
				indegree[next]--;
				if(indegree[next] == 0)
					q.add(new Info(next, dp[next]));
			}
		}
		StringBuilder sb = new StringBuilder();
		for(int i = 1 ; i <= N ; i++)
			sb.append(dp[i] + "\n");
		System.out.println(sb);
	}
}