package boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Member;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class 걸그룹마스터준석이_16165 {

	static Map<String, String> team = new HashMap<String,String>();
	static HashMap<String, ArrayList<String>> member = new HashMap<String,ArrayList<String>>();
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		
		for(int i = 0 ; i < N ; i++) {
			String teamName = br.readLine();
			int cnt = Integer.parseInt(br.readLine());
			ArrayList<String> al = new ArrayList<String>();
			while(cnt-- > 0) {
				String name = br.readLine();
				al.add(name);
				team.put(name, teamName);
			}
			Collections.sort(al);
			member.put(teamName, al);
		}
		
		
		for(int i = 0 ; i < M ; i++) {
			
			String input = br.readLine();
			int t = Integer.parseInt(br.readLine());
			if(t==1) {
				sb.append(team.get(input)+"\n");
			}else if(t==0) {
				ArrayList<String> al = member.get(input);
				for(String name : al) {
					sb.append(name+"\n");
				}
			}
		}
		System.out.println(sb);
	}

}
