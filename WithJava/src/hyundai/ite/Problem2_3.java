package hyundai.ite;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Problem2_3 {

	public static void main(String[] args) throws IOException {
		int N, sum = 0;
		int[] arr;
		boolean[] chk, chk2;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());

		st = new StringTokenizer(br.readLine());
		arr = new int[N];
		chk = new boolean[N];
		chk2 = new boolean[N];
		for (int i = 0; i < N; i++)
			arr[i] = Integer.parseInt(st.nextToken());

		String str = br.readLine();
		for (int i = 0; i < N; i++) 
			if (str.charAt(i) == 'O')
				chk[i] = true;
			else
				chk[i] = false;
		
		str = br.readLine();
		for (int i = 0; i < N; i++)
			if (str.charAt(i) == 'O')
				chk2[i] = true;
			else
				chk2[i] = false;
		
		for (int i = 0; i < N; i++) 
			if(chk[i]&&chk2[i])
				sum += arr[i];
		
		System.out.println(sum);
	}
}
