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
#include<string>
#include<vector>
using namespace std;
class big_integer{
private:
    string num;
public:
    // to-do
    // add precision
    static void makeLengthEqual(string &num1 , string &num2);
    void setVal(string val);
    string getVal();
    string operator+(big_integer obj);
    string operator-(big_integer obj);
    string operator*(big_integer obj);
    string operator/(big_integer obj);
    big_integer(string num);
    string sub(string a, string b);
    std::string shift(string num , int count);
    string add(string num1 , string num2);
    static void remTrailingZero(string &num);
    string karatsuba(string num1 , string num2);
    string divison(string num1 , string num2);
    static int cmp(string num1 , string num2);

};

#endif // BIGINTEGER_H
