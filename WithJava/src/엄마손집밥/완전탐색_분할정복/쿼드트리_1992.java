package 엄마손집밥.완전탐색_분할정복;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 쿼드트리_1992 {

	static StringBuilder sb = new StringBuilder();
	static char[][] arr;

	static void quadTree(int n, int x, int y) {
		char ch = arr[x][y];
		boolean chk = false;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				if (arr[x + i][y + j] != ch) {
					chk = true;
					break;
				}
				if (chk)
					break;
			}
		if (chk) {
			sb.append('(');
			for (int i = 0; i < 2; i++)
				for (int j = 0; j < 2; j++) {
					quadTree(n / 2, x + (i * n / 2), y + (j * n / 2));
				}
			sb.append(')');
		} else
			sb.append(ch);
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		arr = new char[N][N];
		for (int i = 0; i < N; i++) {
			String temp = br.readLine();
			for (int j = 0; j < N; j++) 
				arr[i][j] = temp.charAt(j);
		}
		quadTree(N, 0, 0);
		System.out.println(sb);
	}
}
