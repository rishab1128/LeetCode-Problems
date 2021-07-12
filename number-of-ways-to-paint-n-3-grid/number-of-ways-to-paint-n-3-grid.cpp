class Solution {
public:
    int numOfWays(int n) 
    {
        int MOD = (int) (1e9 + 7);
        /*
        init: for the single row, there are C(3, 3) * 3! = 6 3-color combinations, and C(3, 2) * 2 = 6 2-color combinations.
        C(3, 3) * 3! means: choose 3 colors out of 3, and, first cell: 3 possibilities, second cell: 2 possibilities, third cell: only 1    possibility.
        C(3, 2) * 2 means: choose 2 colors out of 3, and, there are only two ways: ABA or BAB.
        */
        long color3 = 6;
        long color2 = 6;

        for (int i = 2; i <= n; ++i) {
            long tempColor3 = color3;
            color3 = (2 * color3 + 2 * color2) % MOD;
            color2 = (2 * tempColor3 + 3 * color2) % MOD;
        }

        return (int) (color3 + color2) % MOD;
        
    }
};