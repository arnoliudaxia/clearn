// ȫ�ֱ�������¼�ݹ麯���ĵݹ����
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



// ���� n����ӡ n �� tab ����
void printIndent(int n) {
    for (int i = 0; i < n; i++) {
        std::cout<<"   ";
    }
}

int recrusionFunExample()
{
    static int count = 0;

//�ڵݹ麯���Ŀ�ͷ������ printIndent(count++) ����ӡ�ؼ�������Ȼ�������� return ���֮ǰ���� printIndent(--count) ����ӡ����ֵ��
    printIndent(count++);
    recrusionFunExample();
    printIndent(--count);
    return 1;
}


