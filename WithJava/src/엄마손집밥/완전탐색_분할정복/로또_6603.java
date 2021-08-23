package 엄마손집밥.완전탐색_분할정복;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 로또_6603 {
	
	static int N;
	static int[] arr, check, ans;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		while(true) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			
			N = Integer.parseInt(st.nextToken());
			if(N==0)
				break;
			arr = new int[N];
			check = new int[N];
			ans = new int[6];
			
			for(int i = 0 ; i < N ; i++) 
				arr[i] = Integer.parseInt(st.nextToken());
			go(0,0);
			System.out.println();
		}
	}
	
	static void go(int cur, int cnt) {
		if(cnt == 6){
			for(int i = 0 ; i < 6 ;i++)
				System.out.print(ans[i] + " ");
			System.out.println();
			return;
		}
		
		for(int i = cur ; i < N ; i++) {
			if(check[i] == 0) {
				check[i] = 1;
				ans[cnt] = arr[i];
				go(i+1, cnt+1);
				check[i] = 0;
			}
		}
	}
}