class Solution {
    public int solution(int n) {
        int answer = 0, plus = 1, minus = 1, sum = 0;
        while(minus != n){
            if(sum<=n) sum+=plus++;
            else sum-=minus++;
            if(sum==n) answer++;
        }
        return answer;
    }
}