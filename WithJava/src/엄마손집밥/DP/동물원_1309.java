package 엄마손집밥.DP;

import java.util.Scanner;

public class 동물원_1309 {

	public static void main(String[] args) {
		int N = new Scanner(System.in).nextInt();
		int[] dp = new int[N + 2];
		dp[1] = 3;
		dp[2] = 7;
		for (int i = 3; i <= N; i++) 
			dp[i] = ((dp[i - 1] * 2) % 9901 + dp[i - 2] % 9901) % 9901;
		System.out.println(dp[N]);
	}

}
