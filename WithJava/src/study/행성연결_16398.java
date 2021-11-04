package study;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class 행성연결_16398 {
	static public class Info implements Comparable<Info> {
		int v1, v2, cost;

		public Info(int v1, int v2, int cost) {
			this.v1 = v1;
			this.v2 = v2;
			this.cost = cost;
		}
		@Override
		public int compareTo(Info o) {
			return this.cost - o.cost;
		}
	}
	static int[] parent;
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		int[][] arr = new int[N + 1][N + 1];
		parent = new int[N + 1];
		for (int i = 1; i <= N; i++)
			parent[i] = i;
		for (int i = 1; i <= N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			for (int j = 1; j <= N; j++) 
				arr[i][j] = Integer.parseInt(st.nextToken());
		}
		PriorityQueue<Info> pq = new PriorityQueue<Info>();
		for (int i = 1; i <= N; i++) 
			for (int j = i + 1; j <= N; j++) 
				pq.add(new Info(i, j, arr[i][j]));
		long answer = 0;
		while (!pq.isEmpty()) {
			int v1 = pq.peek().v1;
			int v2 = pq.peek().v2;
			int cost = pq.peek().cost;
			pq.poll();
			if(!is_merged(v1,v2)) {
				merge(v1,v2);
				answer+= cost;
			}
		}
		System.out.println(answer);
	}

	static int search(int x) {
		if (parent[x] == x)
			return x;
		return parent[x] = search(parent[x]);
	}

	static void merge(int a, int b) {
		a = search(a);
		b = search(b);
		if (a > b)
			parent[a] = b;
		else if (a < b)
			parent[b] = a;

	}
	
	static boolean is_merged(int a, int b) {
		a = search(a);
		b= search(b);
		if(a==b)
			return true;
		return false;
	}
}
