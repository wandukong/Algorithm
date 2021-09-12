package 엄마손집밥.DP;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 팰린드롬_10942 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int N = Integer.parseInt(br.readLine());
		int[] arr = new int[N + 1];
		int[][] dp = new int[N + 1][N + 1];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 1; i <= N; i++)
			arr[i] = Integer.parseInt(st.nextToken());

		for (int i = 1; i <= N; i++)
			dp[i][i] = 1;

		for (int i = 1; i < N; i++)
			if (arr[i] == arr[i + 1])
				dp[i][i + 1] = 1;

		for (int i = 2; i < N; i++) // 길이
			for (int j = 1; j <= N - i; j++) // 시작점 끝점
				if (arr[j] == arr[j + i] && dp[j + 1][j + i - 1] == 1)
					dp[j][j + i] = 1;

		int M = Integer.parseInt(br.readLine());
		while (M-- > 0) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			sb.append(dp[a][b] + "\n");
		}
		System.out.println(sb);
	}
}