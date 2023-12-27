#include "iostream"
#include "cstring"

using namespace std;

#ifndef TREE_DATA_ALGOR_H
#define TREE_DATA_ALGOR_H
typedef int Status;
typedef struct BiTNode {
    string data;
    struct BiTNode *lchild, *rchild, *parent;
} BiTNode, *BiTree;

void CreateBiTree(BiTree &T, BiTree parent = nullptr);  //建立二叉树
Status InOrderTraverse_search(BiTree T, const string &target);  //中序遍历二叉树
Status FindAncestors(BiTree T, const string &target);   //查找祖先
Status FindDescendants(BiTree T, const string &target); //查找子孙
Status PrintDescendants(BiTree T);  //查找子孙
Status FindSiblings(BiTree T, const string &target);    //查找兄弟
int GetDepth(BiTree T,const string &target,int depth,BiTree &parent);   //获取深度，找到同深度的元素
Status FindCousins(BiTree T, const string &target, int target_depth, BiTree parent_of_target, int current_depth);   //查找堂兄弟
Status PrintCousins(BiTree T, const string &target);    //查找堂兄弟
void printTree(BiTree T, string indent = "", bool last = true); //Test purpose
void OutputHelper(Status stat); //检测输出
#endif //TREE_DATA_ALGOR_H
