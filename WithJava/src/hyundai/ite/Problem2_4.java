package hyundai.ite;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.Vector;

public class Problem2_4 {

	public static void main(String[] args) throws IOException {
		int N, W;
		String[] strArr;
		Vector<String> v = new Vector<String>();

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		W = Integer.parseInt(st.nextToken());

		strArr = new String[W];

		st = new StringTokenizer(br.readLine(), " ");
		for (int i = 0; i < W; i++)
			strArr[i] = st.nextToken();

		int time = 0;
		double avgLength = 0.0;

		for (int i = 0; i < W; i++) { // 머리 꽉차지 않음
			if (v.contains(strArr[i])) { // 이미 외운 경우
				v.remove(v.indexOf(strArr[i]));
				v.add(strArr[i]);
				time += 1;
			} else { // 새로 외워야 하는 경우
				if (v.size() >= N) { // 머리 꽉참
					for (int j = 0; j < N; j++) {
						if (v.get(j).length() <= avgLength) {
							v.remove(j);
							break;
						}
					}
				}
				v.add(strArr[i]);
				time += 3;

				int sum = 0;
				for (int j = 0; j < v.size(); j++)
					sum += v.get(j).length();
				avgLength = sum / (double) N;
			}
		}
		System.out.println(time);
	}
}
