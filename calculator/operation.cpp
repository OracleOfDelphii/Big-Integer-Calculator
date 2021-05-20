#include<string>
#include "operation.h"
#include<iostream>
using namespace std;
#include<cstdarg>

template<typename ...Args>

void debug(Args && ...args)
{

        (std::cout << ... << args);

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
        else if (flag == OP::SLL) 
        {
            this->result = sll(a, b);
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
        if(a.length() > b.length())
        {
            b = trail(a.length() - b.length(), b[0]) + b;
        }
        else if(a.length() < b.length())
        {
            a = trail(b.length() - a.length(), a[0]) + a;
        }

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

    std::string operation::slr(string num, string count)
    {
        return num.substr(0, num.length() - atoi(count.c_str()));
    }

    std::string operation::sll(string num, string count)
    {
        for (int i  = 1 ; i <= atoi(count.c_str()); i++)
        {
            num = num + "0";
        }

        return num;
    }

    std::string operation::sar(string num, string count)
    {
        int cnt = atoi(count.c_str());
        num[cnt] = num[0];
        for(int i = 0; i < num.length() - cnt; i++) 
        {
           
           num[i + cnt] = num[i];
           if(i > cnt)
               num[i] = '0';
           else
               num[i] = num[0];
        }
        for(int i = num.length() - cnt + 1; i < num.length(); i++) 
        {
            num[i] = '0';
        }

        return num;
    }

    std::string operation::sal(string num, string count)
    {
        for (int i  = 1 ; i <= atoi(count.c_str()); i++)
        {
            num = num + "0";
        }

        return num;
    }


    string operation::add(string num1, string num2){
       
            
        if(num1.length() < num2.length())
       {
          num1 = trail(num2.length() - num1.length(), num1[0]) + num1;
       }
       else if(num1.length() > num2.length()) 
       {
           num2 = trail(num1.length() - num2.length(), num2[0]) + num2;
       }

        int len1, len2;
        
        if (num2.length() == 0)
        {
            num2 = '0';
        }
        if (num1.length() == 0)
        {
            num1 = '0';
        }
        
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
        while (*a == '0' && *(a+1) == '0')
        {
            a++;
        }
        num = a;
        if (num == "") num = "0"; // sometimes the whole number is 0
    }

    string operation::fast_karatsuba(string num1, string num2)
    {
        return "0"; // for compile
    }

    string operation::karatsuba(string num1, string num2){
       
        if(num1.length() < num2.length())
       {
          num1 = trail(num2.length() - num1.length(), num1[0]) + num1;
       }
       else if(num1.length() > num2.length()) 
       {
           num2 = trail(num1.length() - num2.length(), num2[0]) + num2;
       }
        int len1, len2;
        
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
        string P1 = sll(XlYl, std::to_string(2 * len1));
        string P2 = sll(sub(karatsuba(s_XlXr, s_YlYr),add(XlYl, XrYr)), std::to_string(len1));
        string P3 = XrYr;
        string res = add(add(P1, P2), P3);
        return res;
    }


    // buggy
string operation::to_bit(string base10)
{

    //remTrailingZero(base10);
    constexpr const char* zero("00");
    constexpr const char* one("01");
    constexpr const char* two("010");
    constexpr const char* three("011");
    constexpr const char* four("0100");
    constexpr const char* five("0101");
    constexpr const char* six("0110");
    constexpr const char* seven("0111");
    constexpr const char* eight("01000");
    constexpr const char* nine("01001");
    string res = "0";
    for(char ch : base10) {
        string x1 = "";
        switch (ch - '0') {
            case 0: x1 = zero;
                    break;
            case 1: x1 = one;
                    break;
            case 2: x1 = two;
                    break;
            case 3: x1 = three;
                    break;
            case 4: x1 = four;
                    break;
            case 5: x1 = five;
                    break;
            case 6: x1 = six;
                    break;
            case 7: x1 = seven;
                    break;
            case 8: x1 = eight;
                    break;
            case 9: x1 = nine;
                    break;
        }

        string p1 = sal(res, "3");
        string p2 = sal(res, "1");
        string p3 = bit_add(p1, p2);
        string p4 = bit_add(p3, x1);
        
        //debug("p1: ", p1," p2: ", p2, " p3: ", p3, " p4: ", p4, " x1: ", x1, "\n");
  
        res = p4;

    }
    return res;
}


// signed subtraction
string operation::bit_sub(string num1, string num2)
{
    // two's complement of num2
    string num2_tc = twos_comp(num2);
    return bit_add(num1, num2_tc);
}

string operation::twos_comp(string num)
{
    string tmp = "";

    for (int i = 0; i < num.length(); i++)
    {
        num[i] = (num[i] == '0') ? '1' : '0';
        tmp += "0";
    }
    tmp[tmp.length() - 1] = '1';
    return bit_add(num, tmp);
}


string operation::trail(int count, char fill)
{
    string out = "";
    for(int i = 0; i < count; i++)
    {
        out += fill;
    }

    return out;
}


// signed addition
string operation::bit_add(string num1, string num2)
{
    
    if(num1.length() < num2.length())
    {
       num1 = trail(num2.length() - num1.length(), num1[0]) + num1;
    }
    else if(num1.length() > num2.length()) 
    {
        num2 = trail(num1.length() - num2.length(), num2[0]) + num2;
    } 

    std::string res = "0";
    char flag1 = num1[0];
    char flag2 = num2[0];
    for(int i = 0;  i < num1.length(); i++) {
        res += "0";
    }

    //debug("res: ", res, " num1: ", num1, " num2: ", num2, "\n"); 
    int carry = 0;

    for(int i = res.length() - 1; i >= 1; i--)
    {
        int ch1 = num1[i - 1] - '0';
        int ch2 = num2[i - 1] - '0';

        int sum = ch1 xor ch2 xor carry;
        res[i] = char((sum) + '0');
        carry = (ch1 & ch2) | (carry & (ch1 | ch2));



    }
    if(flag1 == '1' || flag2 == '1') {
    res[0] = res[1];
    }
    
    return res;
}

// integer comparison
string operation::cmp(string num1, string num2)
{
    
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

// base2 signed comparison
string operation::bit_cmp(string num1, string num2)
{
    if(num1.length() < num2.length())
    {
        num1 = trail(num2.length() - num1.length(), num1[0]) + num1;
    }
    else if(num1.length() > num2.length())
    {
        num2 = trail(num1.length() - num2.length(), num2[0]) + num2;
    }

    if(num1 == "" && num2 == "") return "0";
    if(num1[0] == '1' && num2[0] == '0') return "-1";
    if(num1[0] == '0' && num2[0] == '1') return "1";
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
//
#include<queue>
string operation::div(string num1, string num2)
{

    string num1_bit = to_bit(num1);
    string num2_bit = to_bit(num2);
    num1_bit = num1_bit;
    num2_bit = num2_bit;
    
    string comp = bit_cmp(num1_bit, num2_bit);
    // assume num1 is bigger than num2
    string guess = "01";
    string remainder = num2_bit;
    debug("num1_bit ", num1_bit, " num2_bit ", num2_bit, "\n");

    string comp_rem = bit_cmp(num1_bit, num2_bit);

    string divisor = num2_bit;
    
    std::queue<string> parts;
    int i = 0;
    while(true)
    {
        i++;
        if(i > 10) break;
        
        remainder = bit_sub(num1_bit, divisor);
        string tmp = bit_add(divisor, divisor);


        if(bit_cmp(num1_bit, tmp) == "1") {
            divisor = tmp;
            guess = sal(guess, "1");
        }
        else {
            num1_bit = bit_sub(num1_bit, divisor);
            divisor = num2_bit;
            parts.push(guess);
            guess  = "01";
            if(bit_cmp(num1_bit, divisor) == "-1") break;
        }
    }

    guess = "00";
    while(!parts.empty())
    {
        guess = bit_add(guess, parts.front());
        parts.pop();
    }

    // currently base 2
    return guess; // to supress compiler warning
}


