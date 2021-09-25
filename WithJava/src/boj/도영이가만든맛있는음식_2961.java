package boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 도영이가만든맛있는음식_2961 {

	static int N, ans = Integer.MAX_VALUE;
	static int[] sin, sseun;

	public static void main(String[] args) throws NumberFormatException, IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		sin = new int[N + 1];
		sseun = new int[N + 1];
		StringTokenizer st;
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			sin[i] = Integer.parseInt(st.nextToken());
			sseun[i] = Integer.parseInt(st.nextToken());
		}
		go(0, 1, 0, 0);
		System.out.println(ans);
	}

	static void go(int cnt, int v1, int v2, int select) {
		if (cnt == N + 1) {
			return;
		}
		if (cnt != 0 && select != 0) {
			ans = Math.min(ans, Math.abs(v1 - v2));
		}
		go(cnt + 1, v1 * sin[cnt], v2 + sseun[cnt], select + 1);
		go(cnt + 1, v1, v2, select);
	}
}
