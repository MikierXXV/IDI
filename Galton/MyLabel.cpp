#include "MyLabel.h"

MyLabel::MyLabel(QWidget *parent=0):QLabel(parent)
{

}

void MyLabel::reset()
{
    setText("-");
    emit borrar();
}

void MyLabel::changebola()
{
    QString t = text();
    if(t == "-"){
        setText("o");
        emit siguiente();
    }
}

void MyLabel::jugar()
{
    emit borrar();
    probabilidad();
}

void MyLabel::probabilidad()
{
    bool b = rand()%2 == 0;
    if (b){
        emit esquerra();
        changebola();
    } 
    else{
        emit dreta();
        changebola();
    } 
}

