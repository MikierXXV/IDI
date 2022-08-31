#include "MyLabel.h"

MyLabel::MyLabel(QWidget *parent=0):QLabel(parent)
{

}

void MyLabel::reset()
{
    setStyleSheet("background-color: green;");
    setText("0");
    emit borrar();
}

void MyLabel::incrementar()
{
    QString num = text();
    if(num == "1"){
        setText("0");
        setStyleSheet("background-color: green;");
        emit siguiente();
    }
    else{
        setText("1");
        setStyleSheet("background-color: yellow;");

    }
}

/*++label[0];
if (label[0] > 1){
    label[0] = 0;
    ++label[1];
    if (label[1] > 1){
        label[1] = 0;
        ++label[2];
        if (label[2] > 1){
            label[2] = 0;
            ++label[3];
            if (label[3] > 1){
                label[3] = 0;
                ++label[4];
                if (label[4] > 1){
                    label[4] = 0;
                    ++label[5];
                    if (label[5] > 1){
                        label[5] = 0;
                    }
                }
            }
        }
     }
  }*/
