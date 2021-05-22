#include "operation.h"
#include "biginteger.h"
#include<iostream>
int main(int argc, char *argv[])
{
    big_integer a("12");
    big_integer b("2");
    std::cout<<a + b<<std::endl; 
    std::cout<<a * b<<std::endl;
    std::cout<<a % b<<std::endl;
}
