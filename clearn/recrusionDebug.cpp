// 全局变量，记录递归函数的递归层数
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



// 输入 n，打印 n 个 tab 缩进
void printIndent(int n) {
    for (int i = 0; i < n; i++) {
        std::cout<<"   ";
    }
}

int recrusionFunExample()
{
    static int count = 0;

//在递归函数的开头，调用 printIndent(count++) 并打印关键变量；然后在所有 return 语句之前调用 printIndent(--count) 并打印返回值。
    printIndent(count++);
    recrusionFunExample();
    printIndent(--count);
    return 1;
}


