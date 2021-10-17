package 엄마손집밥.위상정렬;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class 텀프로젝트_9466 {
	static int N;
	static int[] indegree;
	static ArrayList<ArrayList<Integer>> graph;
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		while(T-- > 0) {
			int answer = 0;
			int N = Integer.parseInt(br.readLine());
			indegree = new int[N+1];
			graph = new ArrayList<ArrayList<Integer>>();
			for(int i = 0 ; i <= N ; i++) {
				graph.add(new ArrayList<Integer>());
			}
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int i = 1 ; i <= N ; i++) {
				int num = Integer.parseInt(st.nextToken());
				graph.get(i).add(num);
				indegree[num]++; 
			}
			Queue<Integer> q = new LinkedList<>();
			for(int i = 1 ; i <= N ; i++) 
				if(indegree[i]==0)
					q.add(i);
			while(!q.isEmpty()) {
				int cur = q.poll();
				answer++;
				for(int next : graph.get(cur))
					if(--indegree[next] == 0)
						q.add(next);
			}
			System.out.println(answer);
		}
	}
}