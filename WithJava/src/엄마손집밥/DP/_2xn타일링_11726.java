package 엄마손집밥.DP;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class _2xn타일링_11726 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		int[] arr = new int[1001];
		arr[1] = 1;
		arr[2] = 2;
		for(int i = 3 ; i<=N ; i++)
			arr[i] = ((arr[i-1] % 10007) + (arr[i-2] % 10007))% 10007;
		System.out.println(arr[N]);
	}
}
