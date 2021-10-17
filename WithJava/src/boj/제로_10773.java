package boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class 제로_10773 {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		Stack<Integer> st = new Stack<>();
		int N = Integer.parseInt(br.readLine());
		for(int i = 0 ; i < N ; i++) {
			int num = Integer.parseInt(br.readLine());
			if(num == 0)
				st.pop();
			else
				st.push(num);
		}
		int ans = 0;
		while(!st.isEmpty())
			ans += st.pop();
		System.out.println(ans);
	}
}
