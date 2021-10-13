// 全局变量，记录递归函数的递归层数
#include <iostream>
int count = 0;

// 输入 n，打印 n 个 tab 缩进
void printIndent(int n) {
    for (int i = 0; i < n; i++) {
        std::cout<<("   ");
    }
}

void recrusionFunctionExample(void* args)
{
     printIndent(count++);
     //print some useful information here

     //****
     recrusionFunctionExample((void *)10);
     //*****

     printIndent(--count);
     std::cout << "returned : " << 10 << std::endl;
     return;
}