package 백준;
import java.util.Scanner;
import java.util.StringTokenizer;

public class 단어의개수_1152 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		String str = new Scanner(System.in).nextLine();
		str = str.trim();

		String[] strArr = str.split(" ");
		if (str.isEmpty())
			System.out.println("0");
		else
			System.out.println(strArr.length);
		
		StringTokenizer st = new StringTokenizer(str, " ");
		System.out.println(st.countTokens());
		
		/*
		 * 
		 * String.split() 과 StringTokenizer() 의 차이
		 * 
		 * 1. 구분자 사이에 데이터가 없는 경우 split만 공백 데이터를 반환한다.
		 * String str = "apple,banana,,kiwi";
		 * str.split(",") => "apple" "bababa" "" "kiwi" : 4개
		 * st = StringTokenizer(str, ","); st.countTokens() => "apple" "bababa" "kiwi" : 3개
		 * 
		 */
	}
}
