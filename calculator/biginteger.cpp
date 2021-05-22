#include "biginteger.h"
#include<iostream>
string big_integer::value()
{
    return this->num;
}


string big_integer::operator+(big_integer obj)
{
    curr_op.set(obj.num, num, ADD);
    curr_op.execute();
    return curr_op.result();
}


string big_integer::operator-(big_integer obj)
{
    curr_op.set(obj.num, num, SUB);
    curr_op.execute();
    return curr_op.result();
}


string big_integer::operator*(big_integer obj)
{
    curr_op.set(obj.num, num, MUL);
    curr_op.execute();
    return curr_op.result();
}


big_integer::big_integer(operation op)
{
    this->curr_op = op;
    this->num = op.result();
}

string big_integer::operator%(big_integer obj)
{
    curr_op.set(num, obj.num, MOD);
    curr_op.execute();
    return curr_op.result();
}


string big_integer::operator/(big_integer obj)
{
    curr_op.set(num, obj.num, DIV);
    curr_op.execute();
    return curr_op.result();
}


string big_integer::operator==(big_integer obj)
{
    curr_op.set(num, obj.num, CMP);
    curr_op.execute();
    return curr_op.result() == "0" ? "0" : "1";
  
}

string big_integer::operator>(big_integer obj)
{
    curr_op.set(num, obj.num, CMP);
    curr_op.execute();
    return curr_op.result() == "1" ? "0" : "1";
}

string big_integer::operator<(big_integer obj)
{
    curr_op.set(num, obj.num, CMP);
    curr_op.execute();
    return curr_op.result() == "-1" ? "0" : "1";
}

string big_integer::operator<=(big_integer obj)
{
    curr_op.set(num, obj.num, CMP);
    curr_op.execute();
    auto res = curr_op.result();
    if(res == "-1" || res == "0") return "1";
    return "0"; 
}

string big_integer::operator>=(big_integer obj)
{
    curr_op.set(num, obj.num, CMP);
    curr_op.execute();
    auto res = curr_op.result();
    if(res == "1" || res == "0") return "1";
    return "0"; 
}


string big_integer::operator<<(int x)
{
    curr_op.set(num, to_string(x), SAL);
    curr_op.execute();
    return curr_op.result();
}

string big_integer::operator>>(int x)
{
    curr_op.set(num, to_string(x), SAR);
    curr_op.execute();
    return curr_op.result();
}

// manipulators


void big_integer::operator+=(big_integer obj)
{
    curr_op.set(num, obj.num, ADD);
    curr_op.execute();
    this->num = curr_op.result();
}

void big_integer::operator-=(big_integer obj)
{
    curr_op.set(num, obj.num, SUB);
    curr_op.execute();
    this->num = curr_op.result();
}

void big_integer::operator/=(big_integer obj)
{
    curr_op.set(num, obj.num, DIV);
    curr_op.execute();
    this->num = curr_op.result();
}

void big_integer::operator*=(big_integer obj)
{
    curr_op.set(num, obj.num, MUL);
    curr_op.execute();
    this->num = curr_op.result();
}

void big_integer::operator%=(big_integer obj)
{
    curr_op.set(num, obj.num, MOD);
    curr_op.execute();
    this->num = curr_op.result();
}

void big_integer::operator>>=(int x)
{
    curr_op.set(num, to_string(x), SAR);
    curr_op.execute();
    this->num = curr_op.result();
}

void big_integer::operator<<=(int x)
{
    curr_op.set(num, to_string(x), SAL);
    curr_op.execute();
    this->num = curr_op.result();
}


big_integer::big_integer(string num)
{
    this->num = num;
}
