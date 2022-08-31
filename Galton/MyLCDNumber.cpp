#include "MyLCDNumber.h"

MyLCDNumber::MyLCDNumber(QWidget *parent=0):QLCDNumber(parent)
{
     setDecMode();
     numballs = 0;
     box1 = 0, box2 = 0, box3 = 0, box4 = 0, box5 = 0;
}

void MyLCDNumber::reset()
{
    display(0);
    numballs = 0;
    box1 = 0, box2 = 0, box3 = 0, box4 = 0, box5 = 0;
}

void MyLCDNumber::incrementabox1()
{
    ++box1;
    display(box1);
}

void MyLCDNumber::incrementabox2()
{
    ++box2;
    display(box2);
}

void MyLCDNumber::incrementabox3()
{
    ++box3;
    display(box3);
}

void MyLCDNumber::incrementabox4()
{
    ++box4;
    display(box4);
}

void MyLCDNumber::incrementabox5()
{
    ++box5;
    display(box5);
}

void MyLCDNumber::incrementanumballs()
{
    ++numballs;
    display(numballs);
}