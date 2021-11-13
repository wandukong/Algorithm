import java.util.*;
class Solution {
    static Map<String,Integer> map = new HashMap<>();
    static char[] arr = {'A','E','I', 'O','U'};
    static int idx = 1;
    public int solution(String word) {
        go(0, "");
        int answer = map.get(word);
        return answer;
    }
    static void go(int cnt, String str){
        if(cnt == 5){
            return;
        }
        for(int i = 0 ; i < 5 ; i++){
            map.put(str+arr[i], idx++);
            go(cnt+1, str+arr[i]);
        }   
    }
}