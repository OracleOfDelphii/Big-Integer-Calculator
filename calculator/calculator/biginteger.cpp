#include<string>
#include "biginteger.h"
using namespace std;

void big_integer::makeLengthEqual(string &num1 , string &num2){
    auto len2  = static_cast<int>(num2.length());
    auto len1 = static_cast<int>(num1.length());
    for(int i = 1 ; i <= (len2 - len1) ; i++){
        num1 = "0" + num1;

    }
    for(int i = 1 ; i <= (len1 - len2)  ; i++){
        num2 = "0" + num2;
    }
}
void big_integer::setVal(string val){
    this->num = val;
}
string big_integer::getVal(){
    return this->num;
}
string big_integer::operator+(big_integer obj){
    return add(obj.num , num);
}
string big_integer::operator-(big_integer obj){
    return sub(obj.num , num);
}
string big_integer::operator*(big_integer obj){
    return karatsuba(obj.num , num);
}
big_integer::big_integer(string num){
    this->num = num;
}
string big_integer::operator/(big_integer obj){
    return divison(obj.num , num);
}
string big_integer::sub(string a, string b)
{
    string res ;
    makeLengthEqual(a,b);
    if(cmp(a , b)==-1){
        string tmp = a;
        a = b;
        b = tmp;
    }
    int lena = static_cast<int>(a.length());
    int lenb = static_cast<int>(b.length());
    int toSub = 0;
    res.resize(static_cast<size_t>(lena));
    for (int inda = lena - 1, indb = lenb - 1; inda >= 0; --inda, --indb)
    {
        int x = a[static_cast<size_t>(inda)] - '0';
        int y = indb >= 0 ? b[static_cast<size_t>(indb)] - '0' : 0;
        if (toSub == 1)
        {
            x--;
        }
        int cur;
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
        res[static_cast<int>(inda)] = cur + '0';
    }
    remTrailingZero(res);
    return res;
}

// returns a * 10^n


std::string big_integer::shift(string num , int count){
    for(int i  = 1 ; i<= count ; i++){
        num= num + "0";
    }


    return num;
}
string big_integer::add(string num1 , string num2){
    int len1 , len2 ;
    if(num2.length()==0){
        num2='0';
    }
    if(num1.length()==0){
        num1 = '0';
    }
    makeLengthEqual(num1  , num2);
    len1 = static_cast<int>(num1.length());
    len2 = static_cast<int>(num2.length());
    string result;
    int res = 0 , res2 = 0 , cnum1y = 0;
    for(int j = len1 - 1 ; j>=0 ; j--){
        res  = num1[j]-'0';
        res2  = static_cast<int>(num2[j]-'0');
        int r = 0;
        r = (res + res2 + cnum1y) % 10;
        result = to_string(r) + result;
        cnum1y = (res + res2 + cnum1y) / 10;
    }
    if (cnum1y)  result='1'+result;
    remTrailingZero(result);
    return  result ;
}
void big_integer::remTrailingZero(string &num){
    int i = 0;
    char* a = &num[0];
    while(*a == '0'){
        a++;
    }
    num = a;
    if(num=="") num="0"; // sometimes the whole number is 0
}
string big_integer::karatsuba(string num1 , string num2){
    int len1 , len2 ;
    makeLengthEqual(num1, num2);
    len1 = num1.length()/2;
    len2 = num1.length() - len1;

    string xl , yl , xr , yr ;

    xl = num1.substr(0,len2);
    xr = num1.substr(len2 , len2);
    yl = num2.substr(0,len2);
    yr = num2.substr(len2,len2);
    if(num1.length()==0){
        return "0";
    }
    if(num1.length()==1){
        return (to_string((num1[0]-'0')*(num2[0]-'0')));
    }
    string XrYr = karatsuba(xr,yr);
    string XlYl = karatsuba(xl , yl);
    string s_XlXr = add(xl , xr);
    string s_YlYr = add(yl , yr);
    string P1 = shift(XlYl , 2*len1);
    string P2 = shift(sub(karatsuba(s_XlXr , s_YlYr),add(XlYl,XrYr)),len1);
    string P3 = XrYr;
    string res = add(add(P1 , P2),P3);
    remTrailingZero(res);
    return res;
}
int big_integer::cmp(string num1 , string num2){
    makeLengthEqual(num1 , num2);

    for(int i = 0 ; i < num2.length() ; i++){
        if(num1[i]<num2[i]){
            return -1 ;
            break;
        }
        else if(num1[i]>num2[i]){
            return 1;
            break;
        }
    }
    return 0;
}
string big_integer::divison(string num1 , string num2){
    // basic school division (similar to Knuth method)
    string res;
    remTrailingZero(num1);
    remTrailingZero(num2);
    string quotient = "0";
    string remaining = "0";
    if(cmp(num2 , "0") == 0) return "0";
    if(cmp(num1 , "00") == 0) return "undef";
    if(cmp(num1 , num2)< 0){
        string tmp = num1 ; num1 = num2 ; num2 = tmp;
    }


    size_t len1 = num1.length();
    string substr = "" , remainder="";
    for(int i = 0 ; i < len1 ;){
        string tmp = remainder + num1[i++];
        while(cmp(tmp,num2)<0 && i < len1){
            res += "0";
            tmp+= num1[i];
            i++;
        }
        substr = tmp;
        if(remainder == "0"){
            remainder = "";
        }
        for(int j = 1 ; j <= 9 ; j++){
            string temp =  karatsuba(to_string(j),num2);
            string subt = sub(substr , temp);
            if(cmp(subt , num2) < 0 && cmp(substr , temp)>=0){
                res+= to_string(j);
                remainder = sub(substr , temp);
                break;
            }
            else if(j==9){
                res+="0";
            }
        }
    }
    remTrailingZero(res);
    return res;
}

