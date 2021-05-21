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



// bad idea - don't use public constants
//
enum OP {ADD, SUB, MUL, DIV, SLL, SLR, SAL, SAR, CMP, TR, DEFAULT};
class operation{
    private:

    string a;
    string b;
    string res;
    OP flag;

    // these are needed in the api to work properly.
    
    // adds leading zeros to make the length equal
    void makeLengthEqual(string &&num1 , string &&num2);
    void remTrailingZero(string &num);
 
    string withLeadingZeros(int count, char fill);
    
    // product methods
    string karatsuba(string& num1, string& num2);



    public:
    operation(string a, string b = "", OP flag = DEFAULT);
    operation(string a, OP flag);
    operation(string num);
    operation();

    // bad design, public methods should override 
    // use interface

    // manipulators return void
    void execute(); 
    void set(string a, string b, OP flag);

    // returns res
    string result();
    
    // shift operations
    // logical
    string shifted_ll(string& num, string&& count); 
    string shifted_lr(string& num, string&& count);
    // arithmetic
    string shifted_ar(string& num, string&& count);
    string shifted_al(string& num, string&& count);

    // base2 math operations
    string base2_sum(string& num1, string& num2); 
    string base2_difference(string& num1, string& num2);
    string twos_complemented(string& num); 
    string quotient_base2(string& num1, string& num2);

    // base2 logical operations
    // comparison, returns:
    // "-1" -> num1 < num2
    // "0"  -> num1 == num2
    // "1"  -> num1 > num2
    string base2_cmp(string& num1, string& num2);
    
    // base10 math operations
    string sum(string& num1, string& num2);
    string quotient(string& num1, string& num2);
    string product(string& num1, string& num2); 
    string difference(string& a, string& b);
    
    // base10 Logical operations
    // comparison, returns:
    // "-1" ->  num1 < num2
    // "0" ->  num1 == num2
    // "1" ->  num1 > num2
    string cmp(string& num1, string& num2);
    

    // base conversion
    // base2 to base10
    string unsigned_base10(string& num);
    // base10 to base2
    string signed_base2(string& num);
};

#endif // OPERATION_H
