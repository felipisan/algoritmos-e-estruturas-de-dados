//Bst = Binary Search Tree
//ABB para números inteiros

#include <iostream>

using namespace std;

struct BstNode {
    int data;
    BstNode* left;
    BstNode* right;
};

BstNode* GetNewNode(int data){
    BstNode *newNode = new BstNode();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

bool Search(BstNode *root, int data){
    if(root == NULL) return false;
    if(root->data == data) return true;   
    if (data <= root->data) return Search(root->left, data);
    else return Search(root->right, data);
}

BstNode* Insert(BstNode **rootPtr, int data){
    if (*rootPtr == NULL)
        *rootPtr = GetNewNode(data);
    
    else if(data <= (*rootPtr)->data)
        (*rootPtr)->left = Insert(&(*rootPtr)->left, data);

    else
        (*rootPtr)->right = Insert(&(*rootPtr)->right, data);
    
    return *rootPtr;
}

int main(){
    BstNode *root = NULL;
    Insert(&root, 15);
    Insert(&root, 10);
    Insert(&root, 20);

    int number;
    cout << "Type the number to be searched in the BST \n";
    cin >> number;
    if(Search(root, number) == true) cout << "Found\n";
    else cout << "Could'nt find it\n";
}