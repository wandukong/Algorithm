package boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;

public class 다이얼_5622 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		HashMap<Character, Integer> hm = new HashMap();
		for(int i = 0 ; i < 26 ; i++) {
			if(i < 15) 
				hm.put((char)(i+'A'), (i/3)+3);
			else if( 15<= i && i <= 18) 
				hm.put((char)(i+'A'), 8);
			else if(19<= i && i <= 21) 
				hm.put((char)(i+'A'), 9);
			else 
				hm.put((char)(i+'A'), 10);
		}
		String input = br.readLine();
		int sum = 0;
		for(int i = 0 ; i < input.length() ; i++)
			sum += hm.get(input.charAt(i));
		System.out.println(sum);
	}
}
