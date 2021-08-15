package น้มุ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class ฐ๖ผภ_1629 {
	
	static long A,B,C;

	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		A = Long.parseLong(st.nextToken());
		B = Long.parseLong(st.nextToken());
		C = Long.parseLong(st.nextToken());
		
		System.out.println(mlp(A,B,C));
	}
	
	static private long mlp(long a, long b ,long c) {
		if(b==1)
			return a%c;
		long temp = mlp(a,b/2,c);
		
		long result = (temp%c * temp%c) % c;
		if((b%2)==1)
			result = result * A % c;
		return result;
	}
}
