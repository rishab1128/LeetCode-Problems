#include<bits/stdc++.h>
using namespace std;
#define all(a)  (a).begin(), (a).end()

class Solution {
public:
    Solution()
    {
        std::ios::sync_with_stdio(false);
    }
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) 
    {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>>diag;
        int num_of_diag=m+n-1;
        for(int i=0; i<num_of_diag; i++)
        {
            if(i<m)
            {
                int x=i,y=0;
                vector<int>v1; 
                while(x<m&&y<n)
                {
                    v1.push_back(mat[x][y]);
                    x++;
                    y++;
                }
                diag.push_back(v1);
                sort(all(diag[i]));
                // for(auto x: diag[i])
                // 	cout<<x<<" ";
                // cout<<endl;
            }
            else
            {
                int x=0,y=i-m+1;
                vector<int>v1; 
                while(x<m&&y<n)
                {
                    v1.push_back(mat[x][y]);
                    x++;
                    y++;
                }
                diag.push_back(v1);
                sort(all(diag[i]));
                // for(auto x: diag[i])
                // 	cout<<x<<" ";
                // cout<<endl;

            }
        }

        for(int i=0; i<num_of_diag; i++)
        {
            if(i<m)
            {
                int x=i,y=0,j=0;
                while(x<m&&y<n)
                {
                    mat[x][y]=diag[i][j];
                    x++;
                    y++;
                    j++;
                }
            }
            else
            {
                int x=0,y=i-m+1,j=0;
                while(x<m&&y<n)
                {
                    mat[x][y]=diag[i][j];
                    x++;
                    y++;
                    j++;
                }
            }
        }
        // f(i,0,m)
        // {
        // 	f(j,0,n)
        // 		cout<<mat[i][j]<<" ";
        // 	cout<<endl;
        // }
        return mat;
        
    }
};


