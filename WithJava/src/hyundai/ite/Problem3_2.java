package hyundai.ite;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Problem3_2 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str = br.readLine();
		Stack<Integer> st = new Stack<Integer>();
		int sum = 0;
		boolean dynamic = false;
		for (int i = 0; i < str.length(); i++) {
			if (str.charAt(i) == '#')
				dynamic = !dynamic;
			else if (str.charAt(i) == '(')
				st.add(st.size() + 1);
			else if (str.charAt(i) == ')')
				if (dynamic)
					sum += st.pop() * 4;
				else
					sum += st.pop() * 2;
		}
		System.out.println(sum);
	}
}

/*
((#(())#(())))
48

(())((#((()))#))
60

((#(())#(((#()#)))))
82
*/