package boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class 단어뒤집기2_17413 {
	public static void main(String[] args) throws IOException {
		StringBuffer sbf = new StringBuffer();
		StringBuilder sbd = new StringBuilder();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str = br.readLine();
		int i = 0;
		while (i < str.length()) {
			char cur = str.charAt(i);
			if (cur == ' ') {
				sbd.append(sbf.reverse().toString() + " ");
				sbf = new StringBuffer();
			} else if (cur == '<') {
				if (sbf.length() != 0) {
					sbd.append(sbf.reverse().toString());
					sbf = new StringBuffer();
				}
				while (true) {
					cur = str.charAt(i);
					sbd.append(cur);
					if (cur == '>')
						break;
					i++;
				}
			} else
				sbf.append(cur);
			i++;
		}
		if (sbf.length() != 0)
			sbd.append(sbf.reverse().toString());
		System.out.println(sbd);
	}
}