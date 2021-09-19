package programers;

class 합승택시요금_72413 {
    
    public int solution(int n, int s, int a, int b, int[][] fares) {
        
        int[][] dp = new int[n+1][n+1];
        for(int i = 1 ; i <= n ; i++)
             for(int j = 1; j <= n ; j++)
                 if(i==j) dp[i][j] = 0;
                 else dp[i][j] = 1000000;
        for(int i = 0 ; i < fares.length ; i++){
            dp[fares[i][0]][fares[i][1]] = fares[i][2];
            dp[fares[i][1]][fares[i][0]] = fares[i][2];
        }
        for(int k = 1; k <= n ; k++)
            for(int i = 1; i <= n ; i++)
                for(int j = 1; j <= n ; j++)
                    if(dp[i][j] > dp[i][k] + dp[k][j])
                        dp[i][j] = dp[i][k] + dp[k][j];
        
        int answer = dp[s][a] + dp[s][b];
        for(int i = 1 ; i<= n ; i++)
            answer = Math.min(answer, dp[s][i] + dp[i][a] + dp[i][b]);
        return answer;
    }
}