// ȫ�ֱ�������¼�ݹ麯���ĵݹ����
#include <iostream>
int count = 0;

// ���� n����ӡ n �� tab ����
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