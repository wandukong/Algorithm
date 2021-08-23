package 엄마손집밥.완전탐색_분할정복;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 종이의개수_1780 {

	static int a = 0, b = 0, c = 0;
	static int[][] arr;

	static void go(int n, int x, int y) {
		int cur = arr[x][y];
		boolean chk = false;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				if (cur != arr[x + i][y + j]) {
					chk = true;
					break;
				}
			if (chk)
				break;
		}
		
		if(chk) {
			for(int i = 0 ; i< 3 ; i++) 
				for(int j = 0 ; j < 3 ; j++) 
					go(n/3, x+(n/3)*i, y+(n/3)*j);
		}else {
			if(cur == -1) 
				a++;
			else if(cur==0)
				b++;
			else if(cur == 1) 
				c++;
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		arr = new int[N][N];

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < N; j++)
				arr[i][j] = Integer.parseInt(st.nextToken());
		}
		go(N,0,0);
		System.out.println(a);
		System.out.println(b);
		System.out.println(c);
	}
}