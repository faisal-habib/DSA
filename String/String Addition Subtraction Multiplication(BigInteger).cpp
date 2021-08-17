#include<bits/stdc++.h>
using namespace std;

#define MX_LEN 10004
#define positive 0
#define negative 1
typedef struct
{
    int digit[MX_LEN], len, sign;
}BigInt;

BigInt _toBigInt(char *s)
{
    BigInt b;
    b.len = 0;
    int sLen = 0;
    while(s[sLen]) sLen++;
    for(int i=sLen-1; i>0; i--)
    {
        b.digit[b.len++] = s[i]-'0';    // storing digits of the number in reverse order
    }
    if(s[0]=='-') b.sign = negative;
    else b.sign = positive, b.digit[b.len++] = s[0]-'0';

    return b;
}
int _compare(BigInt a, BigInt b)    // returns -1 if a<b, 1 if a>b, 0 if a=b
{
    if(a.len<b.len) return -1;
    if(a.len>b.len) return 1;
    for(int i=a.len-1; i>=0; i--)
    {
        if(a.digit[i]>b.digit[i]) return 1;

        if(a.digit[i]<b.digit[i]) return -1;
    }
    return 0;
}
BigInt _addition(BigInt a, BigInt b)
{
    BigInt result;
    int i, len = 0, carry = 0;
    for(i=0; i<a.len || i<b.len; i++)
    {
        int sum = 0;
        if(i<a.len) sum = a.digit[i];
        if(i<b.len) sum += b.digit[i];
        sum += carry;
        result.digit[len++] = (sum%10);
        carry = (sum/10);
    }
    if(carry) result.digit[len++] = carry;
    result.len = len;

    return result;
}
BigInt _subtraction(BigInt a, BigInt b) // here a>=b
{
    BigInt result;
    int i, len = 0, carry = 0;
    for(i=0; i<a.len; i++)
    {
        int d1 = 0, d2 = 0, diff = 0;
        d1 = a.digit[i];
        if(i<b.len) d2 = b.digit[i];
        d2 += carry;
        diff = d1-d2+10;
        result.digit[len++] = (diff%10);
        if(d2>d1) carry = 1;
		else carry = 0;
    }

    while(len>1 && result.digit[len-1]==0) len--;
    result.len = len;

    return result;
}
BigInt _getMultiplication(BigInt a, BigInt b)
{
    BigInt result;
    result.len = a.len+b.len;
    result.sign = positive;

    if(a.sign!=b.sign) result.sign = negative;

    for(int i=0; i<result.len; i++) result.digit[i] = 0;

    for(int i=0; i<a.len; i++)
    {
        for(int j=0; j<b.len; j++)
        {
            result.digit[i+j] += (a.digit[i]*b.digit[j]);
        }
    }

    int carry = 0, s;
    for(int i=0; i<result.len; i++)
    {
        s = result.digit[i] + carry;
        result.digit[i] = (s%10);
        carry = (s/10);
    }
    while(result.len>1 && result.digit[result.len-1]==0) result.len--;

    return result;
}
BigInt _getAddition(BigInt a, BigInt b)
{
    BigInt result;
    if(a.sign==b.sign)
    {
        result = _addition(a, b);
        result.sign = a.sign;
    }
    else
    {
        int cmp = _compare(a, b);
        if(cmp==1)  // a>b
        {
            result = _subtraction(a, b);
            result.sign = a.sign;
        }
        else if(cmp==-1)    // a<b
        {
            result = _subtraction(b, a);
            result.sign = b.sign;
        }
        else    // a=b, so result will be 0
        {
            result.digit[0] = 0;
            result.len = 1;
            result.sign = positive;
        }
    }

    return result;
}
BigInt _getSubtraction(BigInt a, BigInt b)
{
    BigInt result;
    /* we'll perform a-b
       if b is negative, then it'll be a-(-b)=a+b
       if b is positive, then a-b=a+(-b) */
    b.sign = 1-b.sign;
    result = _getAddition(a, b);
    b.sign = 1-b.sign;

    return result;
}

void _print(BigInt b)
{
    if(b.sign==negative) cout<<"-";
    for(int i=b.len-1; i>=0; i--) cout<<b.digit[i];
}
void _printSummation(BigInt n1, BigInt n2, BigInt result)
{
    _print(n1);
    cout<<" + ";
    _print(n2);
    cout<<" = ";
    _print(result);
    cout<<endl;
}
void _printSubtraction(BigInt n1, BigInt n2, BigInt result)
{
    _print(n1);
    cout<<" - ";
    _print(n2);
    cout<<" = ";
    _print(result);
    cout<<endl;
}
void _printMultiplication(BigInt n1, BigInt n2, BigInt result)
{
    _print(n1);
    cout<<" * ";
    _print(n2);
    cout<<" = ";
    _print(result);
    cout<<endl;
}
int main()
{
    char num1[MX_LEN], num2[MX_LEN];
    while(1)
    {
        cout<<"Number 1: ";
        cin>>num1;
        cout<<"Number 2: ";
        cin>>num2;

        BigInt n1 = _toBigInt(num1), n2 = _toBigInt(num2);

        BigInt result;
        result = _getAddition(n1, n2);
        _printSummation(n1, n2, result);

        result = _getSubtraction(n1, n2);
        _printSubtraction(n1, n2, result);

        result = _getMultiplication(n1, n2);
        _printMultiplication(n1, n2, result);
    }
    return 0;
}
