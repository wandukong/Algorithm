package boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Stack;
import java.util.StringTokenizer;

public class 외계인의기타연주_2841 {
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int P = Integer.parseInt(st.nextToken());
		ArrayList<Stack<Integer>> stackList = new ArrayList<Stack<Integer>>();
		for(int i = 0 ; i <= 6 ; i++)
			stackList.add(new Stack<Integer>());
		int cnt = 0;
		for(int i = 0 ; i < N ; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			if(stackList.get(a).isEmpty()) {
				cnt++;
				stackList.get(a).add(b);
			}else { 
				while(!stackList.get(a).isEmpty() && stackList.get(a).peek() > b) {
					stackList.get(a).pop();
					cnt++;
				}
				if(stackList.get(a).isEmpty() || stackList.get(a).peek() < b)
				{
					stackList.get(a).add(b);
					cnt++;
				}
			}
		}
		System.out.println(cnt);
	}
}