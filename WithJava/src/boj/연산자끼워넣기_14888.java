package boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class 연산자끼워넣기_14888 {
	static int N, ansMax = Integer.MIN_VALUE, ansMin = Integer.MAX_VALUE;
	static int[] arr;
	static boolean[] check;
	static ArrayList<Character> al = new ArrayList<>();

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		arr = new int[N];
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++)
			arr[i] = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < 4; i++) {
			int num = Integer.parseInt(st.nextToken());
			for (int j = 0; j < num; j++) {
				if (i == 0)
					al.add('+');
				else if (i == 1)
					al.add('-');
				else if (i == 2)
					al.add('*');
				else if (i == 3)
					al.add('/');
			}
		}
		check = new boolean[al.size()];
		dfs(1, arr[0]);
		System.out.println(ansMax);
		System.out.println(ansMin);
	}

	static void dfs(int cnt, int num) {

		if (al.size()+1 == cnt) {
			ansMax = Math.max(num, ansMax);
			ansMin = Math.min(num, ansMin);
			return;
		}

		for (int i = 0; i < al.size(); i++) {
			if (!check[i]) {
				check[i] = true;
				char cur = al.get(i);
				if (cur == '+')
					dfs(cnt + 1, num + arr[cnt]);
				else if (cur == '-')
					dfs(cnt + 1, num - arr[cnt]);
				else if (cur == '*')
					dfs(cnt + 1, num * arr[cnt]);
				else if (cur == '/')
					dfs(cnt + 1, num / arr[cnt]);
				check[i] = false;
			}
		}

	}
}
