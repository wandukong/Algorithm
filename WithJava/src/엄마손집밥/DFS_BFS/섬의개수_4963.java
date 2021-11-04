package 엄마손집밥.DFS_BFS;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 섬의개수_4963 {

	static int C, R;
	static int arr[][], chk[][];
	static int dr[] = {1,-1,0,0,1,1,-1,-1};
	static int dc[] = {0,0,1,-1,-1,1,1,-1};
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		while(true) {
			int ans = 0;
			StringTokenizer st = new StringTokenizer(br.readLine());
			C = Integer.parseInt(st.nextToken());
			R = Integer.parseInt(st.nextToken());
			if(C==0 && R==0)
				break;
			arr = new int[R][C];
			chk = new int[R][C];
			for(int i = 0 ; i < R ; i++) {
				st = new StringTokenizer(br.readLine());
				for(int j = 0 ; j < C ; j++)
					arr[i][j] = Integer.parseInt(st.nextToken());
			}
			for(int i = 0 ; i < R ; i++) {
				for(int j = 0 ; j < C ; j++)
					if(arr[i][j] == 1 && chk[i][j] == 0){
						ans++;
						dfs(i,j);
					}
			}
			System.out.println(ans);
		}
	}
	
	static void dfs(int r, int c) {
		chk[r][c] = 1;
		for(int i = 0 ; i < 8 ;i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if(nr < 0 || nc < 0 || nr>= R || nc>=C )
				continue;
			if(chk[nr][nc] == 1)
				continue;
			if(chk[nr][nc]==0 && arr[nr][nc] == 1)
				dfs(nr,nc);
		}
	}
}
