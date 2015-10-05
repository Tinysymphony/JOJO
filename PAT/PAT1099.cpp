#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

typedef struct Node* TreeNode;

int pos = 0;

struct Node{
    TreeNode Left;
    TreeNode Right;
    int val;
};

void dfs(TreeNode root, int number[]){
    if(root == NULL) return;
    dfs(root->Left, number);
    root->val = number[pos++];
    dfs(root->Right, number);
}

int main(){
    int total;
    cin >> total;
    TreeNode* tree = (TreeNode*)malloc(sizeof(TreeNode) * total);
    int number[total];
    queue<TreeNode> result;
    for(int i = 0; i < total; i++) {
        tree[i] = (TreeNode)malloc(sizeof(Node));
    }

    for(int i = 0; i < total; i++){
        int left, right;
        cin >> left >> right;
        tree[i]->Left = left == -1 ? NULL : tree[left];
        tree[i]->Right = right == -1 ? NULL : tree[right];
    }

    for(int i = 0; i < total; i++){
        scanf("%d", &number[i]);
    }
    sort(number, number + total);
    dfs(tree[0], number);
    result.push(tree[0]);
    int count = 0;
    while(!result.empty()){
        TreeNode tmp = result.front();
        if(++count == total)
            cout << tmp->val << endl;
        else
            cout << tmp->val << " ";
        result.pop();
        if(tmp->Left != NULL){
            result.push(tmp->Left);
        }
        if(tmp->Right != NULL){
            result.push(tmp->Right);
        }
    }
}