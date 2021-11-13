package boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class 트리_4803 {
	static boolean[] check;
	static ArrayList<ArrayList<Integer>> graph;
	static ArrayList<Integer> visited;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		int T = 0;
		while (true) {
			T++;
			int ansCnt = 0;
			st = new StringTokenizer(br.readLine());
			int N = Integer.parseInt(st.nextToken());
			int M = Integer.parseInt(st.nextToken());
			if (N == 0 && M == 0)
				break;
			check = new boolean[N + 1];
			graph = new ArrayList<ArrayList<Integer>>();
			for (int i = 0; i <= N; i++)
				graph.add(new ArrayList<>());

			for (int i = 0; i < M; i++) {
				st = new StringTokenizer(br.readLine());
				int a = Integer.parseInt(st.nextToken());
				int b = Integer.parseInt(st.nextToken());
				graph.get(a).add(b);
				graph.get(b).add(a);
			}

			for (int i = 1; i <= N; i++) {
				if(!check[i]) {
					visited = new ArrayList<>();
					dfs(i);
					int cnt = 0;
					for(int edge : visited) {
						cnt += graph.get(edge).size();
					}
					if (cnt == (visited.size()-1)*2)
						ansCnt++;
				}
			}
			if(ansCnt == 0) {
				sb.append("Case "+ T + ": No trees.\n"); 
			}
			else if(ansCnt == 1) {
				sb.append("Case "+ T + ": There is one tree.\n");
			}
			else {
				sb.append("Case "+ T + ": A forest of ");
				sb.append(ansCnt+" trees.\n");
			}
		}
		System.out.print(sb);
	}

	static void dfs(int cur) {
		check[cur] = true;
		visited.add(cur);
		for(int next : graph.get(cur))
			if(!check[next])
				dfs(next);
	}
}
