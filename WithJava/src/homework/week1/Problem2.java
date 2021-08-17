package homework.week1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Problem2 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] arr = br.readLine().split(",");
		
		int sum = 0, minValue = Integer.MAX_VALUE;

		for(int i = 0 ; i < arr.length ; i++) {
			int temp = Integer.parseInt(arr[i]);
			if((temp%2) == 1) {
				sum+=temp;
				minValue = Math.min(minValue, temp);
			}
		}
		
		if(minValue == Integer.MAX_VALUE)
			System.out.println(-1);
		else {
			System.out.println(sum);
			System.out.println(minValue);
		}
			
	}

}
