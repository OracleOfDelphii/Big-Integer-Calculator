/*
 * Copyright (c) <2018> <copyright Ali Hossein Bayest>
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.
*/
#ifndef BIGINTEGER_H
#define BIGINTEGER_H

#include "operation.h"


// TO-DO
// make two seperate classes(Binary, Decimal)
// they are both inherited from class number
// the behaviour of operators is based on their type

class big_integer{

private:
    // good design, only two objects for the state of the class.
    string num;
    operation curr_op;
public:
    // to-do
    // add precision
    
    string value();
    string operator+(big_integer obj);
    string operator-(big_integer obj);
    string operator*(big_integer obj);
    string operator/(big_integer obj);
    string operator%(big_integer obj);
    string operator==(big_integer obj);
    string operator<(big_integer obj);
    string operator>(big_integer obj);
    string operator>=(big_integer obj);
    string operator <=(big_integer obj);
    string operator<<(int x);
    string operator>>(int x);


    // manipulators
    void operator+=(big_integer obj);
    void operator-=(big_integer obj);
    void operator/=(big_integer obj);
    void operator*=(big_integer obj);
    void operator%=(big_integer obj);
    void operator<<=(int x);
    void operator>>=(int x);
    big_integer(string num);
    big_integer(operation op);
};

#endif // BIGINTEGER_H
