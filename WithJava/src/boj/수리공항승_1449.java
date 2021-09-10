package boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class 수리공항승_1449 {
	static int N, L, ans = 0;
	static boolean check[];
	static int arr[];

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		L = Integer.parseInt(st.nextToken());
		arr = new int[N];
		check = new boolean[2002];
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++)
			arr[i] = Integer.parseInt(st.nextToken());
		Arrays.sort(arr);
		for (int i = 0; i < N; i++) {
			if(!check[arr[i]]) {
				for(int j = arr[i] ; j < arr[i] + L ; j++) {
					check[j] = true;
				}
				ans++;
			}
		}
		System.out.println(ans);
	}
}