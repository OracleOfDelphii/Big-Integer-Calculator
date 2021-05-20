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
#ifndef OPERATION_H
#define OPERATION_H
#include<string>
#include<vector>
using namespace std;
enum OP {ADD, SUB, MUL, DIV, SLL, SLR, CMP, TR, DEFAULT};
class operation{
    private:
    string a, b;
    string result;

    string bit_a;
    string bit_b;

    OP flag;
    void makeLengthEqual(string &&num1 , string &&num2);
    string trail_zero(int count);
    void remTrailingZero(string &num);
    string karatsuba(string num1, string num2);
    string fast_karatsuba(string num1, string num2); 
    public:
    operation(string a, string b = "", OP flag = DEFAULT);
    operation(string a, OP flag);
    operation(string num);
    operation();

    string execute();

    string get();

    string sub(string a, string b);
    string sll(string num, string count);
    string slr(string num, string count);
    string sar(string num, string count);
    string sal(string num, string count);
    string add(string num1, string num2);
    string div(string num1, string num2);
    string cmp(string num1, string num2);

    string twos_comp(string num);
    string bit_add(string num1, string num2); 
    string bit_sub(string num1, string num2);
    string bit_cmp(string num1, string num2);

    string to_bit(string num);
    void set(string a, string b, OP flag);
};

#endif // OPERATION_H
