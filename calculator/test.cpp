#include "operation.h"
#include "biginteger.h"
#include<iostream>
int main(int argc, char *argv[])
{
   // operation op("3", "5", OP::MUL);
    big_integer a("1322");
    big_integer b("232");
  
    std::cout<<a.getVal()<<std::endl;
    std::cout<<b.getVal()<<std::endl; 
    std::cout<<(a == b)<<std::endl;
    std::cout<<(a < b)<<std::endl;
    std::cout<<(a > b)<<std::endl;
    std::cout<<(a - b)<<std::endl;
    std::cout<<(a + b)<<std::endl;
    std::cout<<(a * b)<<std::endl;
    
    std::cout<<a.getVal()<<std::endl;
}
