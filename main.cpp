#include <iostream>
#include <mystack.h>

using namespace std;

int main()
{
    cout << "Hello World!" << endl;

    conversion2(123456, 10);

    int re = match("fff{{{fff}}}");

    cout << re << endl;

    lh::stackTest2();

    return 0;
}
