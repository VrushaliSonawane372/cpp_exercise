#include<iostream>
using namespace std;

bool CheckFirstBit(int iNo)
{
    int iMask = 0x10;
    int iResult = 0;
    iResult = iNo & iMask;

    if(iResult == iMask)
    {   return true;   }
    else
    {   return false;    }
}

int main()
{
    int iValue = 0;
    bool bRet = false;

    cout<<"Enter number : \n";
    cin>>iValue;

    bRet = CheckFirstBit(iValue);

    if(bRet == true)
    {
        cout<<"First Bit is ON\n";
    }
    else
    {
        cout<<"First Bit is OFF\n";
    }
    
    return 0;
}


//              0001    0000
//              1       0
//                  0x10