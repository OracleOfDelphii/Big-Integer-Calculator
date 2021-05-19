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
    operation op;
    std::cout<<op.to_bit("133")<<std::endl;
    std::cout<<op.twos_comp("01")<<std::endl;
    std::cout<<op.bit_add("01", "10")<<std::endl;
    std::cout<<op.bit_sub("100", "110")<<std::endl;
    std::string x  = op.sar("11000", "2");
    std::cout<<op.twos_comp(x)<<std::endl;

    std::cout<<a.getVal()<<std::endl;
}
