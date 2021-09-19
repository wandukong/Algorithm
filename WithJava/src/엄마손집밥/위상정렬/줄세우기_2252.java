package 엄마손집밥.위상정렬;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class 줄세우기_2252 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		int[] indegree = new int[N+1];
		ArrayList<ArrayList<Integer>> graph = new ArrayList<ArrayList<Integer>>();
		for(int i = 0 ; i <= N ; i++)
			graph.add(new ArrayList<>());
		for(int i = 0 ; i < M ; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			graph.get(a).add(b);
			indegree[b]++;
		}
		Queue<Integer> q = new LinkedList<>();
		for(int i = 1; i <= N ; i++)
			if(indegree[i] == 0) 
				q.add(i);
		StringBuilder sb = new StringBuilder();
		while(!q.isEmpty()) {
			int cur = q.poll();
			sb.append(cur + " ");
			for(int next : graph.get(cur)) {
				indegree[next]--;
				if(indegree[next] == 0)
					q.add(next);
			}
		}
		System.out.println(sb);
	}
}