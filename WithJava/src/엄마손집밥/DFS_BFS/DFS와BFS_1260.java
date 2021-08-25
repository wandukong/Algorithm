package 엄마손집밥.DFS_BFS;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class DFS와BFS_1260 {
	
	static int N;
	static int M;
	static int V;
	static ArrayList<ArrayList<Integer>> graph;
	static boolean[] check;
	static StringBuilder sb = new StringBuilder();
	
	static void dfs(int cur) {
		check[cur] = true;
		sb.append(cur + " ");
		for(int i = 0 ; i< graph.get(cur).size() ; i++) {
			int next = graph.get(cur).get(i);
			if(!check[next]) {
				dfs(next);
			}
		}
	}
	
	static void bfs(int cur) {
		Queue<Integer> q = new LinkedList<Integer>();
		q.add(cur);
		check[cur] = true;
		while(!q.isEmpty()) {
			cur = q.poll();
			sb.append(cur + " ");
			for(int i = 0 ; i < graph.get(cur).size() ; i++) {
				int next = graph.get(cur).get(i);
				if(!check[next]){
					q.add(next);
					check[next] = true;
				}
			}
		}
		
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		V = Integer.parseInt(st.nextToken());
		
		graph = new ArrayList<ArrayList<Integer>>(N+1);
		
		for(int i = 0; i <= N ; i++)
			graph.add(new ArrayList<Integer>());
		
		check = new boolean[N+1];
		for(int i = 0 ; i < M ; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			graph.get(a).add(b);	
			graph.get(b).add(a);
		}
		for(int i = 0; i <= N ; i++)
			Collections.sort(graph.get(i));
		dfs(V);
		sb.append("\n");
		check = new boolean[N+1];
		bfs(V);
		System.out.println(sb);

	}
}
