package 엄마손집밥.DP;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class 기업투자_2662 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		int[][] arr = new int[M + 1][N + 1];
		int[][] dp = new int[M + 1][N + 1];
		int[][] route = new int[M + 1][N + 1];
		for (int i = 1; i <= N; i++) {
			st = new StringTokenizer(br.readLine());
			int pay = Integer.parseInt(st.nextToken());
			for (int j = 1; j <= M; j++) {
				arr[j][pay] = Integer.parseInt(st.nextToken());
			}
		}
		for (int i = 1; i <= M; i++) {
			for (int j = 1; j <= N; j++) {
				for (int k = 0; k <= j; k++) {
					int temp = dp[i - 1][j - k] + arr[i][k];
					if (temp > dp[i][j]) {
						dp[i][j] = temp;
						route[i][j] = k;
					}
				}
			}
		}
		System.out.println(dp[M][N]);

		List<Integer> al = new ArrayList<>();
		int cost = N;
		int company = M;
		while (company > 0) {
			int c = route[company][cost];
			al.add(c);
			cost -= c;
			company--;
		}
		 Collections.reverse(al);
		for (int c : al) {
			System.out.print(c + " ");
		}
	}
}
