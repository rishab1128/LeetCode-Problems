class Solution {
public:
    int minSwaps(string s1 , string s2)
    {
        int size = s1.length();
        int i = 0, j = 0;
        int result = 0;
  
        while (i < size) {
            j = i;
  
            while (s1[j] != s2[i]) j++;
  
            while (i < j) {
                swap(s1[j], s1[j-1]);
                j--;
                result++;
            }
            i++;
        }
        return result;
    }
    
    int getMinSwaps(string num, int k) 
    {
        string ori=num;
        while(k--)
            next_permutation(num.begin() , num.end());
        return minSwaps(num,ori);
    }
};