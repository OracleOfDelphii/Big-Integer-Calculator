#include "biginteger.h"
#include<iostream>
string big_integer::getVal()
{
    return this->num;
}


string big_integer::operator+(big_integer obj)
{
    curr_op.set(obj.num, num, ADD);
    curr_op.execute();
    return curr_op.get();
}


string big_integer::operator-(big_integer obj)
{
    curr_op.set(obj.num, num, SUB);
    curr_op.execute();
    return curr_op.get();
}


string big_integer::operator*(big_integer obj)
{
    curr_op.set(obj.num, num, MUL);
    curr_op.execute();
    return curr_op.get();
}


big_integer::big_integer(operation op)
{
    this->curr_op = op;
    this->num = op.get();
}


string big_integer::operator/(big_integer obj)
{
    curr_op.set(obj.num, num, DIV);
    curr_op.execute();
    return curr_op.get();
}


string big_integer::operator==(big_integer obj)
{
    curr_op.set(num, obj.num, CMP);
    curr_op.execute();
    return curr_op.get() == "0" ? "0" : "1";
  
}

string big_integer::operator>(big_integer obj)
{
    curr_op.set(num, obj.num, CMP);
    curr_op.execute();
    return curr_op.get() == "1" ? "0" : "1";
}

string big_integer::operator<(big_integer obj)
{
    curr_op.set(num, obj.num, CMP);
    curr_op.execute();
    return curr_op.get() == "-1" ? "0" : "1";
}




string big_integer::operator<<(int x)
{
    curr_op.set(num, to_string(x), SH);
    curr_op.execute();
    return curr_op.get();
}


big_integer::big_integer(string num)
{
    this->num = num;
}
