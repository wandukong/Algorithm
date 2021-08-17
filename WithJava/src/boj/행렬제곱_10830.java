package boj;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 행렬제곱_10830 {
	static int A;
	static long B;
	static int[][] matrix;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		A = Integer.parseInt(st.nextToken());
		B = Long.parseLong(st.nextToken());
		
		matrix = new int[A][A];
		
		for(int i = 0 ; i < A ; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j = 0 ; j < A ; j++)
				matrix[i][j] = Integer.parseInt(st.nextToken()) % 1000;
		}

		int ret[][] = pow(matrix, B);
		for(int i = 0 ; i < A ; i++) {
			for(int j = 0 ; j < A ; j++)
				System.out.print(ret[i][j] + " ");
			System.out.println();	
		}
	}
	
	static int[][] pow(int[][] mat, long B) {
		if(B==1)
			return mat;
		int[][] ret = pow(mat, B/2);
		ret = mlpMtx(ret,ret);
		if((B%2)==1)
			ret = mlpMtx(ret,matrix);
		return ret;
	}
	
	static int[][] mlpMtx(int[][] a,int[][] b){
		int[][] temp = new int[A][A];
		for(int i = 0 ; i < A ; i++) 
			for(int j = 0 ; j < A ; j++) 
				for(int k = 0 ; k < A ; k++) {
					temp[i][j] += a[i][k] * b[k][j];
					temp[i][j] %= 1000;
				}
		return temp;
	}
}