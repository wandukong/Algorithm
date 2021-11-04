package study;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 배열합치기_11728 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		int[] arr = new int[N];
		int[] arr2 = new int[M];
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++)
			arr[i] = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < M; i++)
			arr2[i] = Integer.parseInt(st.nextToken());
		int p1 = 0, p2=0;
		while(true) {
			if(arr[p1] < arr2[p2]) {
				sb.append(arr[p1]+ " ");
				p1++;
			}
			else if(arr[p1] > arr2[p2]) {
				sb.append(arr2[p2]+ " ");
				p2++;
			}else {
				sb.append(arr[p1]+ " ");
				sb.append(arr2[p2]+ " ");
				p1++;
				p2++;
			}
			if(p1 == N) {
				for(int i = p2 ; i < M ; i++)
					sb.append(arr2[i]+ " ");
				break;
			}
			if(p2 == M) {
				for(int i = p1 ; i < N ; i++)
					sb.append(arr[i]+ " ");
				break;
			}
		}
		System.out.println(sb);
	}
}