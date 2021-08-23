package 엄마손집밥.완전탐색_분할정복;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 모든순열_10974 {

	static int N;
	static boolean[] check;
	static int[] arr;

	static void go(int cnt) {
		if (cnt == N) {
			for (int i = 0; i < N; i++)
				System.out.print(arr[i]+" ");
			System.out.println();
			return;
		}
		for (int i = 1; i <= N; i++) {
			if (!check[i]) {
				check[i] = true;
				arr[cnt] = i;
				go(cnt + 1);
				check[i] = false;
			}
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		check = new boolean[N + 1];
		arr = new int[N + 1];
		go(0);

	}
}
