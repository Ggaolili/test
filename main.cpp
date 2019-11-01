#include <iostream>
#include<string.h>

using namespace std;

/*int main()
{
    char c1='a';
    const char *p;
    p=&c1;
    c1='b';
    cout<<*p<<endl;
}*/

class Test
{
private:

public:
    void dosomething1(const Test *p1);
    void dosomething2(const Test p2[],int n);
    void printxy();
};

void Test::dosomething1(const Test *p1)
{
    p1->printxy();
    cout<<p1<<endl;
}
void Test::dosomething2(const Test p2[],int n)
{
    p2->printxy();
    cout<<p2<<endl;
}
int main()
{
    Test t1(3,5);
    Test t2[N];
    dosomething1(&t1);
    dosomething2(t2,N);
    return 0;
}
