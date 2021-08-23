package 엄마손집밥.완전탐색_분할정복;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class 수정렬하기2_mergersort_2751 {

	static int N;
	static int[] arr;
	static int[] sorted;

	static void merge(int[] array, int s, int m, int e) {
		int i = s;
		int j = m + 1;
		int cnt = s;

		while (i <= m && j <= e) {
			if (arr[i] < arr[j]) {
				sorted[cnt++] = arr[i++];
			} else {
				sorted[cnt++] = arr[j++];
			}
		}
		if (i > m) {
			for (int a = j; a <= e; a++)
				sorted[cnt++] = arr[a];
		} else {
			for (int a = i; a <= m; a++)
				sorted[cnt++] = arr[a];
		}
		for (int a = s; a <= e; a++)
			array[a] = sorted[a];
	}

	static void mergeSort(int[] array, int s, int e) {
		if (s < e) {
			int m = (s + e) / 2;
			mergeSort(array, s, m);
			mergeSort(array, m + 1, e);
			merge(array, s, m, e);
		}
	}

	public static void main(String[] args) throws IOException   {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		N = Integer.parseInt(br.readLine());
		arr = new int[N];
		sorted = new int[N];
		for (int i = 0; i < N; i++) 
			arr[i] = Integer.parseInt(br.readLine());
		
		mergeSort(arr, 0, N - 1);
		for (int i = 0; i < N; i++)
			sb.append(arr[i] + "\n");
		
		System.out.println(sb);
	}
}
