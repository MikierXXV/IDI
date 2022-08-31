#include "MyLCDNumber.h"

MyLCDNumber::MyLCDNumber(QWidget *parent=0):QLCDNumber(parent)
{
     setOctMode();
     result = 0;
}

void MyLCDNumber::reset()
{
    display(0);
}

void MyLCDNumber::representacio()
{
    ++result;
    if (result >= 64) result = 0;
    display(result);
}

//result = (label[3]*1 + label[4]*2 + label[5]*4)*10 + (label[0]*1 + label[1]*2 + label[2]*4);
