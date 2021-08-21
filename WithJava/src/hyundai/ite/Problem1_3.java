package hyundai.ite;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Problem1_3 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] arr = br.readLine().split(",");
	
		int A = Integer.parseInt(arr[0]);
		int B = Integer.parseInt(arr[1]);
		int C= Integer.parseInt(arr[2]);
		int result = A*B*C;
		int[] cnt = new int[10];
		
		String str = Integer.toString(result);
		
		for(int i = 0 ; i < str.length(); i++) 
			cnt[str.charAt(i)-'0']++;
		
		for(int i = 0 ; i < 10 ; i++)
			System.out.println(cnt[i]);
	}

}
