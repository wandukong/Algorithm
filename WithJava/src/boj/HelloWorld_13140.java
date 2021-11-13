package boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class HelloWorld_13140 {

	static int N, ans1, ans2;
	static boolean[] check = new boolean[10];
	static int[] used = new int[7];
	static boolean ansChk = false;

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		go(0);
		if (ansChk) {
			System.out.printf("%7d\n", ans1);
			System.out.printf("+ %5d\n", ans2);
			System.out.println("-------");
			System.out.printf("%7d", ans1 + ans2);
		} else
			System.out.println("No Answer");
	}

	static void go(int cnt) {
		if (cnt == 7) {
			int temp1 = used[0] * 10000 + used[1] * 1000 + used[2] * 100 + used[2] * 10 + used[3];
			int temp2 = used[4] * 10000 + used[3] * 1000 + used[5] * 100 + used[2] * 10 + used[6];
			if (temp1 + temp2 == N && used[0] != 0 && used[4] != 0) {
				ans1 = temp1;
				ans2 = temp2;
				ansChk = true;
			}
			return;
		}
		for (int i = 0; i < 10; i++) {
			if (!check[i]) {
				used[cnt] = i;
				check[i] = true;
				go(cnt + 1);
				check[i] = false;
			}
		}
	}
}