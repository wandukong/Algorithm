package boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;


public class 창영이와퇴근_22119 {
	static public class Info implements Comparable<Info>{
		int r, c, cost;
		public Info(int r, int c, int cost) {
			this.r = r;
			this.c = c;
			this.cost = cost;
		}
		@Override
		public int compareTo(Info o) {
			return this.cost - o.cost;
		}
	}
	
	static int[] dr = {0,1,0,-1};
	static int[] dc = {1,0,-1,0};
	static boolean[][] check;
	
	public static void main(String[] args) throws NumberFormatException, IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		int ans = 0;

		int[][] arr = new int[N+1][N+1];
		check = new boolean[N+1][N+1];
		for(int i = 1 ; i <= N ; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine(), " ");
			for(int j = 1; j <= N ; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		PriorityQueue<Info> pq = new PriorityQueue<>();
		pq.add(new Info(1,1,0));
		check[1][1] = true;

		while(!pq.isEmpty()) {
			int r = pq.peek().r;
			int c =pq.peek().c;
			int cost = pq.peek().cost;
			pq.poll();
			
			ans = Math.max(ans, cost);
			check[r][c] = true;
			if(r == N && c == N)
				break;
			
			for(int i = 0 ; i < 4 ; i++) {
				int nr = r + dr[i];
				int nc = c + dc[i];
			
				
				if(nr < 1 || nc < 1 || nc > N || nr > N)
					continue;
			
				if(check[nr][nc])
					continue;
				
				int nextCost = Math.abs(arr[r][c]-arr[nr][nc]);
				pq.add(new Info(nr,nc, nextCost));
				
			}
		}
		System.out.println(ans);
		

	}

}
