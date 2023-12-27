#include <iostream>
#include "algor.h"
#include <cctype>

int main() {
    init:
    BiTree test;
    char choice;
    string name;
    cout<<"请为二叉树输入数值，以#表示树的截断:";
    CreateBiTree(test);
    cout<<endl;

    while(true){
        cout<<"请输入要执行的操作：1表示任意成员的查找，2表示某一成员的祖先的查找，3表示其子孙的查找，4表示其兄弟的查找，5表示其堂兄弟的查找，7表示重新输入，0表示退出"<<endl;
        cin>>choice;
        while(!isdigit(choice)){
            cout<<"输入无效，请输入数字"<<endl;
            cin>>choice;
        }
        switch (choice) {
            case '1':
                cout << "请输入要查找的名字:";
                cin >> name;
                OutputHelper(InOrderTraverse_search(test,name));
                break;
            case '2':
                cout << "请输入要查找的名字:";
                cin >> name;
                OutputHelper(FindAncestors(test,name));
                break;
            case '3':
                cout << "请输入要查找的名字:";
                cin >> name;
                OutputHelper(FindDescendants(test,name));
                break;
            case '4':
                cout << "请输入要查找的名字:";
                cin >> name;
                OutputHelper(FindSiblings(test,name));
                break;
            case '5':
                cout << "请输入要查找的名字:";
                cin >> name;
                OutputHelper(PrintCousins(test,name));
                break;
            case '6':
                cout<<"Display!"<<endl;
                printTree(test);
                break;
            case '7':
                free(test);
                goto init;
            case '0':
                cout<<"退出！";
                return 0;
            default:
                cout<<"输入无效，请重新输入！"<<endl;
                break;
        }
    }
}
