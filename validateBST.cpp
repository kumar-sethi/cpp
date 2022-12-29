#include<bits/stdc++.h>
using namespace std;
  
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 

class Solution{
    public:
        bool isValidBST(TreeNode* root){
            TreeNode* prev = nullptr;
            return isBST(root, prev);
        }

        bool isBST(TreeNode* root, TreeNode* &prev){

            if(root==nullptr) return true;
            if(!isBST(root->left, prev)) return false;
            if(prev!=nullptr && prev->val>=root->val) return false;
            prev = root;
            return isBST(root->right, prev);
        }

        void topViewBST(TreeNode* root){
        
            map<int, int> mymap; // key will be height and Node will be value
            queue<pair<TreeNode*, int>> q; //Node and height of tree
            if(!root) return;
            q.push({root, 0});
            while(!q.empty()){
                TreeNode* t = q.front().first;
                int h = q.front().second;
                q.pop();
                if(!mymap[h]) mymap[h] = t->val;
                if(t->left) q.push({t->left, h-1});
                if(t->right) q.push({t->right, h+1});
            }
        
        }

}












/* class Solution {
public:
    bool isBST(TreeNode* root){
        
        static TreeNode* prev = NULL;
        if(root){
            
            if(!isBST(root->left))
                return false;
            
            if(prev!= NULL && root->val <= prev->val)
                return false;
            prev = root;
                        
            if(!isBST(root->right))
                return false;
        }
        return true;
    }
    bool isValidBST(TreeNode* root) {
        if(isBST(root))
            return true;
        return false;
    }
};

int main(){


} */