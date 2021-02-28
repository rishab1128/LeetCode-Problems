class Solution:
    #See note on side bar
    def minOperations(self, nums1: List[int], nums2: List[int]) -> int:
        sum1=sum(nums1)
        sum2=sum(nums2)
        
        if(sum1==sum2):
            return 0
        elif(sum1>sum2):
            larger_nums=nums1
            smaller_nums=nums2
        else:
            larger_nums=nums2
            smaller_nums=nums1
            
        gain_in_larger_nums=[num-1 for num in larger_nums]
        gain_in_smaller_nums=[6-num for num in smaller_nums]
        
        gains=gain_in_larger_nums+gain_in_smaller_nums
        gains.sort(reverse=True)
        
        target=abs(sum1-sum2)
        ct=0
        for gain in gains:
            target-=gain
            ct+=1
            if(target<=0):
                return ct
        
        return -1
        
        