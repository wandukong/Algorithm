package boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class 회사에있는사람_7785 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		StringBuilder sb = new StringBuilder();
		StringTokenizer st = null;
		
		Map<String, String> map = new HashMap<>();
		
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			String name = st.nextToken();
			String status = st.nextToken();
			map.put(name, status);
		}
		
		Object[] mapKey = map.keySet().toArray();
		Arrays.sort(mapKey, Collections.reverseOrder());		
		for(Object key : mapKey)
			if(map.get(key).equals("enter"))
				sb.append(key+"\n");
		System.out.println(sb);
	}
}
