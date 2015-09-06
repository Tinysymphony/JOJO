#include <iostream>
using namespace std;

typedef struct AvlNode* AvlTree;

struct AvlNode{
    int val;
    int height;
    AvlTree Left;
    AvlTree Right;
};

int Max(int a, int b){
    return a > b? a : b;
}

int Height(AvlTree T){
    if(T == NULL)
        return -1;
    return T->height;
}

AvlTree SingleLeft(AvlTree T){
    AvlTree Top = T->Left;
    T->Left = Top->Right;
    Top->Right = T;
    T->height = Max(Height(T->Left), Height(T->Right)) + 1;
    Top->height = Max(Height(Top->Left), Height(Top->Right)) + 1;
    return Top;
}

AvlTree DoubleLeft(AvlTree T){
    AvlTree Top = T->Left->Right;
    T->Left->Right = Top->Left;
    Top->Left = T->Left;
    T->Left = Top->Right;
    Top->Right = T;
    T->height = Max(Height(T->Left), Height(T->Right)) + 1;
    Top->Left->height = Max(Height(T->Left->Left), Height(T->Left->Right)) + 1;
    Top->height = Max(Height(Top->Left), Height(Top->Right)) + 1;
    return Top;
}

AvlTree SingleRight(AvlTree T){
    AvlTree Top = T->Right;
    T->Right = Top->Left;
    Top->Left = T;
    T->height = Max(Height(T->Left), Height(T->Right)) + 1;
    Top->height = Max(Height(Top->Left), Height(Top->Right)) + 1;
    return Top;
}

AvlTree DoubleRight(AvlTree T){
    AvlTree Top = T->Right->Left;
    T->Right->Left = Top->Right;
    Top->Right = T->Right;
    T->Right = Top->Left;
    Top->Left = T;
    T->height = Max(Height(T->Left), Height(T->Right)) + 1;
    Top->Right->height = Max(Height(T->Right->Left), Height(T->Right->Right)) + 1;
    Top->height = Max(Height(Top->Left), Height(Top->Right)) + 1;
    return Top;
}

AvlTree Insert(int x, AvlTree T){
    if(T == NULL){
        T = (AvlTree)malloc(sizeof(AvlNode));
        T->val = x;
        T->height = 0;
        T->Left = T->Right = NULL;
    } else if(x < T->val) {
        T->Left = Insert(x, T->Left);
        if(Height(T->Left) - Height(T->Right) == 2){
            if(x < T->Left->val)
                T = SingleLeft(T);
            else
                T = DoubleLeft(T);
        }
    } else if(x > T->val) {
        T->Right = Insert(x, T->Right);
        if(Height(T->Right) - Height(T->Left) == 2){
            if(x > T->Right->val)
                T = SingleRight(T);
            else
                T = DoubleRight(T);
        }
    }
    T->height = Max(Height(T->Left), Height(T->Right)) + 1;
    return T;
}

int main(){
    int times;
    AvlTree tree = NULL;
    cin >> times;
    for(int i = 0; i < times; i++){
        int num;
        cin >> num;
        tree = Insert(num, tree);
    }
    if(tree && tree->val)
        cout << tree->val << endl;
}