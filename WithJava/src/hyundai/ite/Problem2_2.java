package hyundai.ite;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Problem2_2 {

	public static void main(String[] args) throws IOException {
		int start, end, num, sum = 0;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		start = Integer.parseInt(st.nextToken());
		end = Integer.parseInt(st.nextToken());
		num =  Integer.parseInt(st.nextToken());
		for(int i = start ; i <= end ; i++) {
			if((i%num)==0)
				sum+=i;
		}
		System.out.println(sum);
	}
}
