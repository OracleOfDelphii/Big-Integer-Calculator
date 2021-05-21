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

    void operation::execute() 
    {
        if (flag == ADD) 
        {
            this->res = operation::sum(a, b);
        }
        else if (flag == OP::SUB) 
        {
            this->res = operation::difference(a, b);
        }
        else if (flag == OP::MUL) 
        {
            this->res = product(a, b);
        }
        else if (flag == OP::DIV)
        {
            this->res = quotient(a, b);
        }
        else if (flag == OP::SLL) 
        {
            this->res = shifted_ll(a, std::move(b));
        }
        else if (flag == OP::SLR)
        {
            this->res = shifted_lr(a, std::move(b));
        }
        else if (flag == OP::SAL) 
        {
            this->res = shifted_al(a, std::move(b));
        }
        else if (flag == OP::SAR)
        {
            this->res = shifted_ar(a, std::move(b));
        }
        else if (flag == OP::CMP)
        {
            this->res = cmp(a, b);
        }
        else
        {
            this->res = a;
        }
    }


    operation::operation(string a, OP flag)
    {
        operation(a, "", flag);
    }


    operation::operation(string num)
    {
        operation(num, "", DEFAULT);
    }


    string operation::result() 
    {
        remTrailingZero(this->res);
        return this->res;
    }

    void operation::set(string a, string b, OP flag)
    {
        this->a = a;
        this->b = b;
        this->flag = flag;
    }

    string operation::difference(string& a, string& b)
    {
        string res;
        if(a.length() > b.length())
        {
            b = withLeadingZeros(a.length() - b.length(), '0') + b;
        }
        else if(a.length() < b.length())
        {
            a = withLeadingZeros(b.length() - a.length(), '0') + a;
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

    std::string operation::shifted_lr(string& num, string&& count)
    {
        return num.substr(0, num.length() - atoi(count.c_str()));
    }

    std::string operation::shifted_ll(string& num, string&& count)
    {
        for (int i  = 1 ; i <= atoi(count.c_str()); i++)
        {
            num = num + "0";
        }

        return num;
    }

    std::string operation::shifted_ar(string& num, string&& count)
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

    std::string operation::shifted_al(string& num, string&& count)
    {
        for (int i  = 1 ; i <= atoi(count.c_str()); i++)
        {
            num = num + "0";
        }

        return num;
    }


    string operation::sum(string& num1, string& num2){
      
        int len1, len2;
        
        if(num1.length() < num2.length()) 
        {
            num1 = withLeadingZeros(num2.length() - num1.length(), '0') + num1;

        }

        else if(num1.length() > num2.length())
        {

            num2 = withLeadingZeros(num1.length() - num2.length(), '0') + num2;
        }

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


    void operation::remTrailingZero(string& num){
        int i = 0;
        char* a = &num[0];
        while (*a == '0' && *(a+1) == '0')
        {
            a++;
        }
        num = a;
        if (num == "") num = "0"; // sometimes the whole number is 0
    }

    string operation::product(string& num1, string& num2)
    {   
        return karatsuba(num1, num2);

    }

    // uses karatsuba algorithm
    string operation::karatsuba(string& num1, string& num2){
       
        if(num1.length() < num2.length())
       {
          num1 = withLeadingZeros(num2.length() - num1.length(), num1[0]) + num1;
       }
       else if(num1.length() > num2.length()) 
       {
           num2 = withLeadingZeros(num1.length() - num2.length(), num2[0]) + num2;
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
        string s_XlXr = sum(xl, xr);
        string s_YlYr = sum(yl, yr);
        string P1 = shifted_ll(XlYl, std::to_string(2 * len1));
        
        // s_XlXr S_YlYr product
        string I1 = karatsuba(s_XlXr, s_YlYr);
        // XlYl XrYr sum
        string I2 = sum(XlYl, XrYr);

        // I1 I2 difference
        string I3 = difference(I1, I2);
        
        string P2 = shifted_ll(I3, std::to_string(len1));
        string P3 = XrYr;
        string P1_P2_sum = sum(P1, P2);
        string res = sum(P1_P2_sum, P3);
        return res;
    }

string operation::unsigned_base10(string& base2)
{
    string out = "00";
    string value = "01";
    for(int i = base2.length() - 1; i >= 0; i--)
    {
        char digit = base2[i];
        if(digit == '1')
        {
        out = sum(out, value);
        }
        value = sum(value, value);
    }

    return out;
}

string operation::signed_base2(string& base10)
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

        string p1 = shifted_al(res, "3");
        string p2 = shifted_al(res, "1");
        string p3 = base2_sum(p1, p2);
        string p4 = base2_sum(p3, x1);
  
        res = p4;

    }
    return res;
}


// signed subtraction
string operation::base2_difference(string& num1, string& num2)
{
    // two's complement of num2
    string num2_tc = twos_complemented(num2);
    return base2_sum(num1, num2_tc);
}

string operation::twos_complemented(string& num)
{
    string tmp = "";

    for (int i = 0; i < num.length(); i++)
    {
        num[i] = (num[i] == '0') ? '1' : '0';
        tmp += "0";
    }
    tmp[tmp.length() - 1] = '1';
    return base2_sum(num, tmp);
}


string operation::withLeadingZeros(int count, char fill)
{
    string out = "";
    for(int i = 0; i < count; i++)
    {
        out += fill;
    }

    return out;
}


// signed addition
string operation::base2_sum(string& num1, string& num2)
{
    
    if(num1.length() < num2.length())
    {
       num1 = withLeadingZeros(num2.length() - num1.length(), num1[0]) + num1;
    }
    else if(num1.length() > num2.length()) 
    {
        num2 = withLeadingZeros(num1.length() - num2.length(), num2[0]) + num2;
    } 

    std::string res = "0";
    char flag1 = num1[0];
    char flag2 = num2[0];
    for(int i = 0;  i < num1.length(); i++) {
        res += "0";
    }
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
string operation::cmp(string& num1, string& num2)
{
    
    if(num1 == "" && num2 == "") return "0";
    if(num1.length() < num2.length())
    {
        num1 = withLeadingZeros(num2.length() - num1.length(), '0') + num1;
    }
    else if(num1.length() > num2.length())
    {
        num2 = withLeadingZeros(num1.length() - num2.length(), '0') + num2;
    }

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
string operation::base2_cmp(string& num1, string& num2)
{
    if(num1.length() < num2.length())
    {
        num1 = withLeadingZeros(num2.length() - num1.length(), num1[0]) + num1;
    }
    else if(num1.length() > num2.length())
    {
        num2 = withLeadingZeros(num1.length() - num2.length(), num2[0]) + num2;
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

string operation::quotient(string& num1, string& num2)
{
    string comp = cmp(num1, num2);
    
    if(comp == "0") return "01";

    string guess = (comp == "1") ? "1" : "0";
    string remainder = num2;
    string comp_rem = cmp(num1, num2);

    string divisor = num2;

    std::string result = "00";

    int i = 0;
    while(true)
    {

        string tmp = sum(divisor, divisor);
        
        if(cmp(num1, tmp) == "1") {
            divisor = tmp;
            guess = sum(guess, guess);
        }
        else {
            num1 = difference(num1, divisor);
            divisor = num2;
            result = sum(result, guess);
            guess  = "01";
            if(cmp(num1, divisor) == "-1") break;
        }
    }

   
    return result; 
}

string operation::quotient_base2(string& num1, string& num2)
{

    string num1_base2 = num1;
    string num2_base2 = num2;

    string comp = base2_cmp(num1_base2, num2_base2);
    
    if(comp == "0") return "01";

    string guess = (comp == "1") ? "01" : "00";

    string remainder = num2_base2;
    string comp_rem = base2_cmp(num1_base2, num2_base2);

    string divisor = num2_base2;
    
    std::string result = "00";
    
    while(true)
    {

        string tmp = base2_sum(divisor, divisor);

        if(base2_cmp(num1_base2, tmp) == "1") {
            divisor = tmp;
            guess = shifted_al(guess, "1");
        }
        else {
            
            num1_base2 = base2_difference(num1_base2, divisor);
            divisor = num2_base2;
            result = base2_sum(result, guess);
            guess  = "01";

            if(base2_cmp(num1_base2, divisor) == "-1") break;
        }
    }

   
    return result; 
}


