#include "inc/SString.h"
#include <iostream>

int main()
{
    SString str = "hello";
    SString str1 = "WORLD!";
    str.append("a");
    str.append("b");
    str.append("c");
    str.append("d");
    str.append("d123jdoqdhqohodq");
    str.append(str1);

    std::cout<<str.mid(11,3)<<std::endl;
    return 0;
}