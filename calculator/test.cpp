#include "operation.h"
#include "biginteger.h"
#include<iostream>
int main(int argc, char *argv[])
{
   // operation op("3", "5", OP::MUL);
    big_integer a("1322");
    big_integer b("232");
    operation op = operation();
    std::cout<<op.twos_comp("01")<<std::endl;
    std::cout<<op.bit_add("010", op.twos_comp("01"))<<std::endl;
    std::cout<<op.bit_add("010", "100")<<std::endl;
    std::cout<<op.bit_add("010", "011")<<std::endl;
    std::cout<<op.bit_add("111", "111")<<std::endl;
    std::cout<<op.bit_add("111", "01")<<std::endl;
    std::cout<<op.cmp("11111111", "111")<<std::endl;
}
