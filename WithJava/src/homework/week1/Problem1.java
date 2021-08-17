package homework.week1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Problem1 {

	public static void main(String[] args) throws IOException {
		int N;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		for(int i = 0 ; i < N ; i++) 
			System.out.println("Hello MyCompany!");
	}
}
