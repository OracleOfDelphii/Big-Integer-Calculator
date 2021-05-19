#include<string>
#include "operation.h"
#include<iostream>
using namespace std;






void operation::makeLengthEqual(string &num1, string &num2)
{
    int len2 = num2.length();
    int len1 = num1.length();

    std::string tr0 = "";
    std::string tr1 = "";

    for (int i = 1 ; i <= (len2 - len1) ; i++)
    {
        tr0 = tr0 + "0";

    }

    for (int i = 1; i <= (len1 - len2); i++)
    {
     
        tr1 = tr1 + "0";
    }

    num1 = tr0 + num1;
    num2 = tr1 + num2;
}

operation::operation()
{
    this->flag = DEFAULT;
    this->a = "";
    this->b = "";
}

operation::operation(string a, string b, OP flag)
{
    this->flag = flag;
    this->a = a;
    this->b = b;
}

string operation::execute() 
{
    if (flag == ADD) 
    {
        this->result = operation::add(a, b);
    }
    else if (flag == OP::SUB) 
    {
        this->result = operation::sub(a, b);
    }
    else if (flag == OP::MUL) 
    {
        this->result = karatsuba(a, b);
    }
    else if (flag == OP::DIV)
    {
        this->result = div(a, b);
    }
    else if (flag == OP::SH) 
    {
        this->result = shift(a, b);
    }
    else if (flag == OP::CMP)
    {
        this->result = cmp(a, b);
    }
    else
    {
        this->result = a;
    }

    return this->result;
}


operation::operation(string a, OP flag)
{
    operation(a, "", flag);
}


operation::operation(string num)
{
    operation(num, "", DEFAULT);
}


string operation::get() 
{
    remTrailingZero(result);
    return result;
}

void operation::set(string a, string b, OP flag)
{
    this->a = a;
    this->b = b;
    this->flag = flag;
}

string operation::sub(string a, string b)
{
    string res;
    makeLengthEqual(a, b);
    string comp = cmp(a, b);
    if (comp == "-1"){
        string tmp = a;
        a = b;
        b = tmp;
    }

    int lena = a.length();
    int lenb = b.length();
    int toSub = 0;
    res.resize(static_cast<int>(lena));
    
    for (int inda = lena - 1, indb = lenb - 1; inda >= 0; --inda, --indb)
    {
        int x = a[inda] - '0';
        int y = indb >= 0 ? b[indb] - '0' : 0;
        if (toSub == 1)
        {
            x--;
        }
        int cur = 0;

        if (x < y)
        {
            cur = x + 10 - y;
            toSub = 1;
        }
        else
        {
            cur = x - y;
            toSub = 0;
        }

        res[inda] = cur + '0';
    }
    return res;
}

// returns a * 10^n


std::string operation::shift(string num, string count)
{
    for (int i  = 1 ; i <= atoi(count.c_str()); i++)
    {
        num = num + "0";
    }

    return num;
}


string operation::add(string num1, string num2){
    int len1, len2;
    
    if (num2.length() == 0)
    {
        num2 = '0';
    }
    if (num1.length() == 0)
    {
        num1 = '0';
    }
    makeLengthEqual(num1, num2);
    len1 = num1.length();
    len2 = num2.length();
    string result;
    int res = 0, res2 = 0, cnum1y = 0; // what is cnum1y?
    
    for (int j = len1 - 1; j >= 0; j--)
    {
        res  = static_cast<int>(num1[j] - '0');
        res2 = static_cast<int>(num2[j] - '0');
        int r = 0;
        r = (res + res2 + cnum1y) % 10;
        result = to_string(r) + result;
        cnum1y = (res + res2 + cnum1y) / 10;
    }

    if (cnum1y)  result = '1' + result;

    return  result;
}


void operation::remTrailingZero(string &num){
    int i = 0;
    char* a = &num[0];
    while (*a == '0')
    {
        a++;
    }
    num = a;
    if (num == "") num = "0"; // sometimes the whole number is 0
}


string operation::karatsuba(string num1, string num2){
    int len1, len2;
    makeLengthEqual(num1, num2);
    len1 = num1.length() / 2;
    len2 = num1.length() - len1;
    string xl, yl, xr, yr;

    xl = num1.substr(0, len2);
    xr = num1.substr(len2, len2);
    yl = num2.substr(0, len2);
    yr = num2.substr(len2,len2);
    
    if (num1.length() == 0){
        return "0";
    }
    if (num1.length() == 1){
        return (to_string((num1[0] - '0') * (num2[0] - '0')));
    }
    string XrYr = karatsuba(xr, yr);
    string XlYl = karatsuba(xl, yl);
    string s_XlXr = add(xl, xr);
    string s_YlYr = add(yl, yr);
    string P1 = shift(XlYl, std::to_string(2 * len1));
    string P2 = shift(sub(karatsuba(s_XlXr, s_YlYr),add(XlYl, XrYr)), std::to_string(len1));
    string P3 = XrYr;
    string res = add(add(P1, P2), P3);
    return res;
}


string operation::cmp(string num1, string num2)
{
    makeLengthEqual(num1, num2);
    if(num1 == "" && num2 == "") return "0";

    for (int i = 0; i < num2.length(); i++)
    {
        if (num1[i] < num2[i])
        {
            return "-1" ;
        }
        else if (num1[i] > num2[i])
        {
            return "1";
        }
    }
    return "0";
}

// buggy
string operation::div(string num1, string num2)
{
    return "0"; // to compile
}


