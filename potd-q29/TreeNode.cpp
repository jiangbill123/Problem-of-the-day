#include "TreeNode.h"
#include <iostream>

TreeNode * deleteNode(TreeNode* root, int key) {
    // your code here
    
    if (root == NULL) return NULL;
    if (root->val_ == key) {
        
        TreeNode*& node = root;
        std::cout<< node->val_<<std::endl;
        if (node->left_ == NULL && node->right_ == NULL) {
            std::cout<< "Zero child remove" <<std::endl;
            delete(node);
            node = nullptr;
        }
        else if (node->left_ != NULL && node->right_ == NULL) {
            std::cout<< "One-child (left) remove" <<std::endl;
            TreeNode *temp = node;
            node = node->left_;
            delete(temp);
        }
        else if (node->left_ == NULL && node->right_ != NULL) {
            std::cout<< "One-child (right) remove" <<std::endl;
            TreeNode *temp = node;
            node = node->right_;
            delete(temp);
        }
        else{
            std::cout<< "Two-child remove" <<std::endl;
            //Find IOP
            TreeNode *ios = node->right_;
            while (ios->left_!=NULL){
                ios = ios->left_;
            }
            node->val_ = ios->val_; 
            node->right_ = deleteNode(node->right_, ios->val_);
        }
        return node;
    }
    else {
        root->left_= deleteNode(root->left_, key);
        root->right_= deleteNode(root->right_, key);
    }
    return root;
}

void inorderPrint(TreeNode* node)
{
    if (!node)  return;
    inorderPrint(node->left_);
    std::cout << node->val_ << " ";
    inorderPrint(node->right_);
}

void deleteTree(TreeNode* root)
{
  if (root == NULL) return;
  deleteTree(root->left_);
  deleteTree(root->right_);
  delete root;
  root = NULL;
}
