package boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Iterator;
import java.util.Map;
import java.util.TreeMap;

public class 생태학_4358 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		TreeMap<String, Integer> tm = new TreeMap<>();
		int total=0;
		while(true) {
			String temp = br.readLine();
			if(temp == null || temp.length() == 0) break;
			tm.put(temp,  tm.getOrDefault(temp, 0) + 1);
			total++;
		}
		StringBuilder sb = new StringBuilder();
		Iterator it = tm.entrySet().iterator();
		while(it.hasNext()) {
			Map.Entry<String, Integer> e =(Map.Entry) it.next();
			double temp = (double)e.getValue()*100/total;
			String per = String.format("%.4f", temp);
			sb.append(e.getKey() + " " + per +"\n");
		}
		System.out.println(sb);
	}
}
