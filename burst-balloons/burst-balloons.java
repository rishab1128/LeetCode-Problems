class Solution {
    public int maxCoins(int[] nums) {
			dp=new Integer[nums.length][nums.length];
	 		return burstBaloon(nums, 0, nums.length-1);
		}
		
	 	Integer[][] dp;
		int burstBaloon(int[] a,int l,int r) {
			if(l>r) return 0;
			if(dp[l][r]!=null) return dp[l][r];
			
			int maxP=Integer.MIN_VALUE;
			for(int last=l;last<=r;last++) {
				int c1=((l-1<0)? 1 : a[l-1])*a[last]*(r+1>=a.length? 1 : a[r+1]);
				
				int c2=burstBaloon(a, l, last-1);
				int c3=burstBaloon(a, last+1, r);
				int profit=c1+c2+c3;
				maxP=Math.max(maxP, profit);
			}
			return dp[l][r]=maxP;
		}
}