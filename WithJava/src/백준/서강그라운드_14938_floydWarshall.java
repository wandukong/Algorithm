package 백준;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 서강그라운드_14938_floydWarshall {
	static int N, M, R;
	static int[] value;
	static int[][] dp;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		R = Integer.parseInt(st.nextToken());

		value = new int[N + 1];
		dp = new int[N + 1][N + 1];

		for (int i = 1; i <= N; i++) 
			for (int j = 1; j <= N; j++) 
				dp[i][j] = 987654231;

		st = new StringTokenizer(br.readLine());
		for (int i = 1; i <= N; i++) {
			value[i] = Integer.parseInt(st.nextToken());
			dp[i][i] = 0;
		}

		for (int i = 0; i < R; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());
			dp[a][b] = dp[b][a] = c;
		}
		for (int k = 1; k <= N; k++) 
			for (int i = 1; i <= N; i++) 
				for (int j = 1; j <= N; j++) 
					if ((dp[i][j] > dp[i][k] + dp[k][j]) == true) 
						dp[i][j] = dp[i][k] + dp[k][j];
		int ans = 0;
		for (int i = 1; i <= N; i++) {
			int temp = 0;
			for (int j = 1; j <= N; j++)
				if(dp[i][j] <= M)
					temp += value[j];
			ans = Integer.max(ans, temp);
		}
		System.out.println(ans);
	}
}