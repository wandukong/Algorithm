package boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class 월드컵_6987 {

	static int[][] arr = new int[6][3];
	static int ans = 0;

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		int t = 4;
		while (t-- > 0) {
			boolean chk = true;
			ans = 0;
			st = new StringTokenizer(br.readLine());
			for (int i = 0; i < 6; i++)
				for (int j = 0; j < 3; j++) {
					arr[i][j] = Integer.parseInt(st.nextToken());
					if (arr[i][j] > 5)
						chk = false;
				}
			if (chk)
				go(0, 1);
			System.out.print(ans + " ");
		}
	}

	static void go(int a, int b) {
		if (a == 5)
			ans = 1;

		// a가 승리한 경우
		if (arr[a][0] > 0 && arr[b][2] > 0) {
			arr[a][0]--;
			arr[b][2]--;
			if (b == 5)
				go(a + 1, a + 2);
			else
				go(a, b + 1);
			arr[a][0]++;
			arr[b][2]++;
		}

		// 무승부한 경우
		if (arr[a][1] > 0 && arr[b][1] > 0) {
			arr[a][1]--;
			arr[b][1]--;
			if (b == 5)
				go(a + 1, a + 2);
			else
				go(a, b + 1);
			arr[a][1]++;
			arr[b][1]++;
		}

		// b가 승리한 경우
		if (arr[a][2] > 0 && arr[b][0] > 0) {
			arr[a][2]--;
			arr[b][0]--;
			if (b == 5)
				go(a + 1, a + 2);
			else
				go(a, b + 1);
			arr[a][2]++;
			arr[b][0]++;
		}
	}
}
