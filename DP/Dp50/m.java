class Solution {
    public int minCost(int n, int[] cuts) {
        List<Integer>ct=new ArrayList<>();
        for(int i=0;i<cuts.length;i++)ct.add(cuts[i]);
        int c=ct.size();
        return cost(n,c,ct);
    }
    public int f(int i, int j, List<Integer>cuts, int dp[][])
    {
        if(i>j) return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int mini = Integer.MAX_VALUE;
        for(int ind=i; ind<=j; ind++)
        {
            int ans = cuts.get(j+1) - cuts.get(i-1) + f(i,ind-1,cuts,dp) + f(ind+1,j,cuts,dp);
            mini = (int)Math.min(mini, ans);
        }
        return dp[i][j] = mini;
    }
    public int cost(int n, int c, List<Integer>cuts)
    {
        cuts.add(n);
        cuts.add(0,0);
        Collections.sort(cuts);
        int dp[][]=new int[c+1][c+1];
        for(int r[]:dp)Arrays.fill(r,-1);
        return f(1,c,cuts,dp);
    }
}
