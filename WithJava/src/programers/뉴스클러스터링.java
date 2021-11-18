import java.util.*;
class Solution {
    public int solution(String str1, String str2) {
        int answer = 0;
        List<String> list1 = new ArrayList<>();
        List<String> list2 = new ArrayList<>();
        Set<String> set1 = new HashSet<>();
        Set<String> set2 = new HashSet<>();
        for(int i = 0 ; i < str1.length() - 1 ; i++){
            char c1 = str1.charAt(i);
            char c2 = str1.charAt(i+1);
            String str = "";
            if('A'<= c1 && c1 <= 'Z')
                str += (char)(c1+32);
            else if('a'<= c1 && c1 <= 'z')
                str += c1;
            if('A'<= c2 && c2 <= 'Z')
                str += (char)(c2+32);
            else if('a'<= c2 && c2 <= 'z')
                str += c2;
            list1.add(str);
        }
        
        for(int i = 0 ; i < str2.length() - 1 ; i++){
            char c1 = str2.charAt(i);
            char c2 = str2.charAt(i+1);
            String str = "";
            if('A'<= c1 && c1 <= 'Z')
                str += (char)(c1+32);
            else if('a'<= c1 && c1 <= 'z')
                str += c1;
            if('A'<= c2 && c2 <= 'Z')
                str += (char)(c2+32);
            else if('a'<= c2 && c2 <= 'z')
                str += c2;
            list2.add(str);
        }
        Collections.sort(list1);
        
        for(String s : list1){
            if(s.length() != 2) continue;
            if(set1.contains(s)){
                int n = 2;
                while(true){
                    if(!set1.contains(s+n)){
                        set1.add(s+n);
                        break;
                    }
                    else n++;
                }
            }else set1.add(s);
        }
        
        for(String s : list2){
            if(s.length() != 2) continue;
            if(set2.contains(s)){
                int n = 2;
                while(true){
                    if(!set2.contains(s+n)){
                        set2.add(s+n);
                        break;
                    }
                    else n++;
                }
            }else set2.add(s);
        }
        Iterator<String> it = set2.iterator();
        int n = 0;
        while(it.hasNext()){
            if(set1.contains(it.next()))
                n++;
        }
        it = set2.iterator();
        while(it.hasNext()){
            set1.add(it.next());
        }   
        int m = set1.size();
        
        if(set2.size() == 0)
            answer = 65536;
        else
           answer =  65536 * n / m;
        
        return answer;
    }
}