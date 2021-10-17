package programers;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;

public class 순위검색_72412 {

	public static void main(String[] args) {
		HashMap<String, ArrayList<Integer>> hm  = new HashMap<>();
		ArrayList<Integer> al = new ArrayList<>();
		al.add(155);
		al.add(230);
		al.add(250);
		al.add(66);
		al.add(77);
		
		hm.put("aaa", al);
		hm.put("bbb", al);
		hm.put("ccc", al);
		
		ArrayList<String> al5= new ArrayList<>(hm.keySet());
		for(int i = 0 ; i < al5.size() ; i++)
			System.out.println(hm.get(al5.get(i)));
	
		
		ArrayList<ArrayList<Integer>> al6= new ArrayList<>(hm.values());
		
		for(int i = 0 ; i < al6.size() ; i++) {
			for(int j = 0 ; j < al6.get(i).size() ; j++)
			System.out.println(al6.get(i).get(j));
		}
	}

}
