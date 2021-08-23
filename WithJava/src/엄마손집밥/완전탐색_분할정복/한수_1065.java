package 엄마손집밥.완전탐색_분할정복;

import java.util.Scanner;

public class 한수_1065 {
	public static void main(String[] args) {
		int N = new Scanner(System.in).nextInt();
		int ans = 0;
		if(N<100)
			System.out.println(N);
		else {
			ans+=99;
			for(int i = 100 ; i <=N ; i++ ) {
				int temp = i;
				int a = temp/100;
				temp %=100;
				int b = temp/10;
				temp%=10;
				int c= temp;
				if(a - b == b-c)
					ans++;
			}
			System.out.println(ans);
		}
	}
}
