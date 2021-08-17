package boj;
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
		 * String.split() �� StringTokenizer() �� ����
		 * 
		 * 1. ������ ���̿� �����Ͱ� ���� ��� split�� ���� �����͸� ��ȯ�Ѵ�.
		 * String str = "apple,banana,,kiwi";
		 * str.split(",") => "apple" "bababa" "" "kiwi" : 4��
		 * st = StringTokenizer(str, ","); st.countTokens() => "apple" "bababa" "kiwi" : 3��
		 * 
		 */
	}
}
