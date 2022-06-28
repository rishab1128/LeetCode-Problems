/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* dfs(int root, unordered_map<int, pair<int, int>> &adj){
        if(root == -1)return NULL;
        if(adj.find(root) == adj.end()){
            TreeNode* x = new TreeNode(root);
            return x;
        }
        TreeNode* node = new TreeNode(root, dfs(adj[root].second, adj), dfs(adj[root].first, adj));
        return node;
    }
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, int> m;
        unordered_map<int, pair<int, int>> adj;
        for(auto x: descriptions){
            if(adj.find(x[0]) == adj.end()){
                adj[x[0]] = {-1, -1};   
            }
            if(x[2] == 1){
                adj[x[0]].second = x[1];
            }else{
                adj[x[0]].first = x[1];
            }
            m[x[1]]++;
            if(m.find(x[0]) == m.end()){
                m[x[0]] = 0;
            }
        }
        int root;
        for(auto x: m){
            if(x.second == 0){
                root = x.first;
                break;
            }
        }
        return dfs(root, adj);
    }
};