#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct node {
    int val;
    node* left;
    node* right;
    int ht;
};
/* Node is defined as :
typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
    int ht;
} node; */
int getHeight(node* y) {
    if(y==nullptr) {
        return -1;
    }
    return y->ht;
}
int max(int a, int b) {
    if(a>b) return a;
    else return b;
}
int balanceFactor(node* x) {
    if(x==nullptr) return -1;
    return getHeight(x->left) - getHeight(x->right);
}
node* newNode(int val) {
    node* res = new node();
    res->val = val;
    res->left = nullptr;
    res->right = nullptr;
    res->ht = 0;
    return res;
}
node* leftRotate(node* root) {
    node* x = root->right;
    node* xl = x->left;
    x->left = root;
    root->right = xl;
    x->ht = max(getHeight(x->left),getHeight(x->right))+1;
    root->ht = max(getHeight(root->left),getHeight(root->right))+1;
    return x;
}
node* rightRotate(node* root) {
    node* x = root->left;
    node* xr = x->right;
    x->right = root;
    root->left = xr;
    x->ht = max(getHeight(x->left),getHeight(x->right))+1;
    root->ht = max(getHeight(root->left),getHeight(root->right))+1;
    return x;
}
node * insert(node * root,int val)
{
    if(root == nullptr) {
        return  (newNode(val));
    }
    if(val>root->val) {
        root->right = (insert(root->right,val));
    }
    else if(val<root->val) {
        root->left = (insert(root->left,val));
    }
    else {
        return root;
    }
    root->ht = max(getHeight(root->left),getHeight(root->right))+1;
    int temp = balanceFactor(root);
    //right right
    if(temp < -1 && val > root->right->val) {
        return leftRotate(root);
    }
    //right left
    if(temp < -1 && val < root->right->val) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    //left left
    if(temp > 1 && val < root->left->val) {
        return rightRotate(root);
    }
    //left right
    if(temp > 1 && val > root->left->val) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    
    return root;
}