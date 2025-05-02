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
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> ans;
        vector<int> currLevel;
        queue<TreeNode*> currQ;
        int levelCount=0, maxElt=1, currQSize=0;
        
        
        if (root!=NULL) currQ.push(root);
        
        while(!currQ.empty()){
            currQSize=currQ.size();
            currLevel.clear();
            while(currQSize){
                TreeNode* temp=currQ.front();

                if(temp->left!=NULL)
                    currQ.push(temp->left);

                if(temp->right!=NULL)
                    currQ.push(temp->right);
                    

                currLevel.push_back(temp->val);
                currQ.pop();
                currQSize--;
                
            }
            if(!currLevel.empty()) ans.push_back(currLevel);
        
        }
        
        

        return ans;
    }
};