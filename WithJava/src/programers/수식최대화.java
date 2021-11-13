import java.util.*;
class Solution {
    static List<Long> number = new ArrayList<>();
    static List<Long> tempNumber = new ArrayList<>();
    static List<Character> op = new ArrayList<>();
    static List<Character> tempOp = new ArrayList<>();
    static HashMap<Character, Integer> map = new HashMap<>();
    
    static String[] order = {"*+-","*-+","+*-","+-*","-*+","-+*"};
    static int[] cnt = new int[3]; // *,+,-
    
    public long solution(String expression) {
        long answer = 0;
        
        map.put('*', 0);
        map.put('+', 1);
        map.put('-', 2);
        
        String temp = "";
        for(int i = 0 ; i < expression.length() ; i++){
            if(expression.charAt(i) == '*' || expression.charAt(i) == '+' || expression.charAt(i) == '-'){
                number.add(Long.parseLong(temp));
                op.add(expression.charAt(i));
                temp = "";
                cnt[map.get(expression.charAt(i))]++;
            }else{
                temp += expression.charAt(i);
            }
        }
        number.add(Long.parseLong(temp));
        
        
        int[] tempCnt = new int[3];
        for(int i = 0 ; i < 6 ; i++){
            System.arraycopy(cnt,0,tempCnt,0, 3);
            tempNumber.clear();
            tempNumber.addAll(number);
            tempOp.clear();
            tempOp.addAll(op);
            for(int j = 0 ; j < 3 ; j++){
                int k = 0;
                while(k < tempOp.size()){
                    if(order[i].charAt(j) == tempOp.get(k) && tempCnt[map.get(tempOp.get(k))] > 0){
                        tempCnt[map.get(tempOp.get(k))]--;
                        long num1 = tempNumber.get(k);
                        long num2 = tempNumber.get(k+1);
                        if(tempOp.get(k) == '*')
                            tempNumber.set(k,num1*num2);
                        else if(tempOp.get(k) == '+')
                            tempNumber.set(k,num1+num2);
                        else if(tempOp.get(k) == '-')
                            tempNumber.set(k,num1-num2);
                        tempOp.remove(k);
                        tempNumber.remove(k+1);
                    }else
                        k++;
                }
            } 
            answer = Math.max(Math.abs(tempNumber.get(0)), answer);
        }
        return answer;
    }
}