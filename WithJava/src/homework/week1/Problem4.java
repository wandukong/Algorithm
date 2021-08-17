package homework.week1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Problem4 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str = br.readLine().toString();
		for(int i = 0 ; i < str.length() ; i++) {
			int num = (int)str.charAt(i);
			if(119<= num && num <= 122)
				num -= 26;
			System.out.print((char)(num+4));
		}
	}
}
