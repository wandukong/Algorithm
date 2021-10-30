package boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 빗물_14719 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int ans = 0;
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());

		int[][] arr = new int[N][M];
		st = new StringTokenizer(br.readLine());

		for (int i = 0; i < M; i++) {
			int num = Integer.parseInt(st.nextToken());
			int height = 0, r = N - 1;
			while (height < num) {
				arr[r - height++][i] = 1;
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				System.out.print(arr[i][j]);
			}
			System.out.println();
		}
		

		for (int i = 0; i < N; i++) {
			int start = -1;
			for (int j = 0; j < M; j++) {
				if (arr[i][j] == 1) {
					if (start == -1) {
						start = j;
					}else {
						System.out.println(i +" => "+ start + " " + j);
						ans+=j-start-1;
						start = j;
					}
				}

			}
		}
		System.out.println(ans);
	}

}
