#include "algor.h"

void CreateBiTree(BiTree &T, BiTree parent) {//二叉树的建立
    string ch;
    cin >> ch;
    if (ch == "#")
        T = nullptr;
    else {
        T = new BiTNode;
        T->data = ch;
        T->parent = parent;
        CreateBiTree(T->lchild, T);
        CreateBiTree(T->rchild, T);
    }
}

Status InOrderTraverse_search(BiTree T, const string &target) { //中序遍历
    int i=0;
    if (T) {
        InOrderTraverse_search(T->lchild, target);
        if (T->data == target) {
            cout << "已找到元素" << T->data << endl;
            i+=1;
        }
        InOrderTraverse_search(T->rchild, target);
    }
    if(i==0)
        return 0;
    else
        return 1;
}   //worked

Status FindAncestors(BiTree T, const string &target) {    //查找祖先
    if (T == nullptr) {
        return 0;
    }
    if (T->data == target) {
        T = T->parent;
        if (T == nullptr) { // 如果找到的节点是根节点
            return 0; // 返回0，表示没有祖先
        }
        while (T != nullptr) {
            cout << T->data << " ";
            T = T->parent;
        }
        cout<<endl;
        return 1;
    }
    return FindAncestors(T->lchild,target)|| FindAncestors(T->rchild,target);
}   //worked

Status PrintDescendants(BiTree T) {
    if (T == nullptr) {
        return 0;
    }
    cout << T->data << " ";
    PrintDescendants(T->lchild);
    PrintDescendants(T->rchild);
    return 1;  // 只要打印了节点，就返回1
}   //worked

Status FindDescendants(BiTree T, const string &target) {
    if (T == nullptr) {
        return 0;
    }
    if (T->data == target) {
        Status left = PrintDescendants(T->lchild);
        Status right = PrintDescendants(T->rchild);
        cout << endl;
        return (left > 0 || right > 0) ? 1 : 0;  // 如果至少一个子树有子孙节点，就返回1
    }
    Status leftSearch = FindDescendants(T->lchild, target);
    Status rightSearch = FindDescendants(T->rchild, target);
    return (leftSearch > 0 || rightSearch > 0) ? 1 : 0;  // 如果至少在一个子树中找到目标节点，就返回1
}   //worked

Status FindSiblings(BiTree T, const string &target) { //查找兄弟
    if (T == nullptr) {
        return 0;
    }
    if ((T->lchild != nullptr && T->lchild->data == target) ||
        (T->rchild != nullptr && T->rchild->data == target)) {
        if (T->lchild != nullptr && T->lchild->data != target) {
            cout << "兄弟是：" << T->lchild->data << endl;
            return 1;
        }
        if (T->rchild != nullptr && T->rchild->data != target) {
            cout << "兄弟是：" << T->rchild->data << endl;
            return 1;
        }
    }
    return FindSiblings(T->lchild, target) || FindSiblings(T->rchild, target);
}   //worked

int GetDepth(BiTree T,const string &target,int depth,BiTree &parent){
    if (T == nullptr) {
        return 0;
    }
    if (T->data == target) {
        return depth;
    }
    parent = T;
    int left = GetDepth(T->lchild, target, depth + 1, parent);
    if (left != 0) {
        return left;
    }
    parent = T;
    return GetDepth(T->rchild, target, depth + 1, parent);
}   //worked

Status FindCousins(BiTree T, const string &target, int target_depth, BiTree parent_of_target, int current_depth) {
    if (T == nullptr) {
        return 0;
    }
    if (current_depth == target_depth && T->parent != parent_of_target && T->parent->parent == parent_of_target->parent) {
        cout << "堂兄弟是：" << T->data << endl;
        return 1;
    }
    return FindCousins(T->lchild, target, target_depth, parent_of_target, current_depth + 1) || FindCousins(T->rchild, target, target_depth, parent_of_target, current_depth + 1);
}   //Unknown

Status PrintCousins(BiTree T, const string &target) {
    BiTree parent_of_target = nullptr;
    int target_depth = GetDepth(T, target, 1, parent_of_target);
    return FindCousins(T, target, target_depth, parent_of_target, 1);
}   //Unknown

void printTree(BiTree T, string indent, bool last) {
    cout << indent;
    if (last) {
        cout << "└─";
        indent += "  ";
    } else {
        cout << "├─";
        indent += "| ";
    }
    if (T == nullptr) {
        cout << endl;
        return;
    }
    cout << T->data << endl;
    if (T->lchild != nullptr || T->rchild != nullptr) {
        printTree(T->lchild, indent, false);
        printTree(T->rchild, indent, true);
    }
}   //worked

void OutputHelper(Status stat) {
    if (stat == 0) {
        cout << "未找到！" << endl;
    }
}   //worked
