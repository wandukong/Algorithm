package boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class 점화식_13699 {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		long t[] = new long[36];
		t[0] = 1;
		for(int i = 1 ; i <= n ; i++) 
			for(int j = 0 ; j < i ; j++)
				t[i] += t[j]*t[i-j-1];
			
		System.out.println(t[n]);
	}
}
