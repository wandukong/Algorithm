package study;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class 공유기_2110 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int C = Integer.parseInt(st.nextToken());
		int[] arr = new int[N];
		for(int i = 0 ; i < N ; i++)
			arr[i] = Integer.parseInt(br.readLine());
		Arrays.sort(arr);
		int start = 1;
		int end = arr[N-1];
		int ans = 0;
		
		while(start <= end) {
			int mid = (start + end)/2;
			int house = arr[0];
			int cnt = 1;
			for(int i = 1 ; i < N ; i++) 
				if(arr[i]- house >= mid) {
					cnt++;
					house = arr[i];
				}
			if(cnt>= C) {
				start = mid + 1;
				ans = Math.max(ans, mid);
			}
			else
				end = mid-1;
		}
		System.out.println(ans);
	}
}
