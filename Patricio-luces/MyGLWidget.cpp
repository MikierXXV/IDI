// MyGLWidget.cpp
#include "MyGLWidget.h"
#include <iostream>
#include <stdio.h>

#define printOpenGLError() printOglError(__FILE__, __LINE__)
#define CHECK() printOglError(__FILE__, __LINE__,__FUNCTION__)
#define DEBUG() std::cout << __FILE__ << " " << __LINE__ << " " << __FUNCTION__ << std::endl;

int MyGLWidget::printOglError(const char file[], int line, const char func[]) 
{
    GLenum glErr;
    int    retCode = 0;

    glErr = glGetError();
    const char * error = 0;
    switch (glErr)
    {
        case 0x0500:
            error = "GL_INVALID_ENUM";
            break;
        case 0x501:
            error = "GL_INVALID_VALUE";
            break;
        case 0x502: 
            error = "GL_INVALID_OPERATION";
            break;
        case 0x503:
            error = "GL_STACK_OVERFLOW";
            break;
        case 0x504:
            error = "GL_STACK_UNDERFLOW";
            break;
        case 0x505:
            error = "GL_OUT_OF_MEMORY";
            break;
        default:
            error = "unknown error!";
    }
    if (glErr != GL_NO_ERROR)
    {
        printf("glError in file %s @ line %d: %s function: %s\n",
                             file, line, error, func);
        retCode = 1;
    }
    return retCode;
}

MyGLWidget::~MyGLWidget() {
}

void MyGLWidget::initializeGL ()
{
  // Cal inicialitzar l'ús de les funcions d'OpenGL
  initializeOpenGLFunctions();  

  glClearColor(0.5, 0.7, 1.0, 1.0); // defineix color de fons (d'esborrat)
  glEnable(GL_DEPTH_TEST);
  carregaShaders();
  creaBuffersPatricio();
  creaBuffersTerraIParet();
  //modelTransformPatricio();


  x = 5.0; 
  x1 = 0;
  z = 2.0;
  z1 = 0;
  anglePatricio = 0.0;

  posFocus1 = glm::vec3(0, 0, 0); //posicio camara
  posFocus2 = glm::vec3(8.0, 3.0, 2.0); //escena
  posFocus3 = glm::vec3(0, 0, 0);  //ma dreta patricio

  colFocus1 = glm::vec3(0.9, 0.2, 0.2);
  colFocus2 = glm::vec3(0.2, 0.9, 0.2);
  colFocus3 = glm::vec3(0.2, 0.2, 0.9);

  activ1 = true;
  activ2 = true;
  activ3 = true;


  glUniform3fv(posFocus1Loc, 1, &posFocus1[0]);
  glUniform3fv(colFocus1Loc, 1, &colFocus1[0]);

  glUniform3fv(posFocus2Loc, 1, &posFocus2[0]);
  glUniform3fv(colFocus2Loc, 1, &colFocus2[0]);

  glUniform3fv(posFocus3Loc, 1, &posFocus3[0]);
  glUniform3fv(colFocus3Loc, 1, &colFocus3[0]);

  calculaFocus();

  iniEscena();
  iniCamera();

}

void MyGLWidget::carregaShaders(){
    LL4GLWidget::carregaShaders();

    TGpatLoc = glGetUniformLocation (program->programId(), "TGpat");

    colFocus1Loc = glGetUniformLocation (program->programId(), "colFocus1");
    posFocus1Loc = glGetUniformLocation (program->programId(), "posFocus1");

    colFocus2Loc = glGetUniformLocation (program->programId(), "colFocus2");
    posFocus2Loc = glGetUniformLocation (program->programId(), "posFocus2");

    colFocus3Loc = glGetUniformLocation (program->programId(), "colFocus3");
    posFocus3Loc = glGetUniformLocation (program->programId(), "posFocus3");

}

glm::mat4 MyGLWidget::calculaPatricioTG()
{
    //LL4GLWidget::calculaPatricioTG();
    glm::mat4 tg = glm::translate(glm::mat4(1.f), glm::vec3(x,0,z));
    tg = glm::rotate(tg, anglePatricio,glm::vec3(0,1,0));
    //tg = glm::translate(tg, glm::vec3(5,0,2));
    tg = glm::scale(tg, glm::vec3(escala, escala, escala));
    tg = glm::translate(tg, -centreBasePatr);
    return tg;
}

void MyGLWidget::modelTransformPatricio()
{
  glm::mat4 TG = MyGLWidget::calculaPatricioTG();  // Matriu de transformació
  glUniformMatrix4fv (transLoc, 1, GL_FALSE, &TG[0][0]);
}

void MyGLWidget::calculaFocus() {
  calculaMaPatricio();
  glUniformMatrix4fv (TGpatLoc,1,GL_FALSE,&TGpat[0][0]);
}

void MyGLWidget::calculaMaPatricio()
{
    TGpat = glm::translate(glm::mat4(1.f), glm::vec3(5+x1 ,0, 2+z1));
    TGpat = glm::rotate(TGpat, anglePatricio,glm::vec3(0,1,0));
    TGpat = glm::translate(TGpat, glm::vec3(-1.5,1.5,0));
}


void MyGLWidget::keyPressEvent(QKeyEvent* event) {
  makeCurrent();
  switch (event->key()) {

  case Qt::Key_Right:
      if (x > 8.0){
        x = 9.0;
        //x1 = 9;
      }else{
       ++x;
       ++x1;
      }
      calculaFocus();
    break;

  case Qt::Key_Left:
      if (x < 2){
        x = 1.0;
        //x1 = 2;
      }else{ 
       --x;
       --x1;
      }
      calculaFocus();
    break;

  case Qt::Key_Up:
      if (z < 2){
       z = 1.0;
       //z1 = 1;
      }else{
       --z;
       --z1;
      }
      calculaFocus();
    break;

  case Qt::Key_Down:
      if (z > 8){
       z = 9.0;
       //z1 = 9;
      }else{
       ++z;
       ++z1;
      }
      calculaFocus();
    break;

  case Qt::Key_R:
      anglePatricio += (float) M_PI/4;
      calculaFocus();
    break;

  case Qt::Key_C:
      activ1 = !activ1;
      if(activ1) colFocus1 = glm::vec3(0.0, 0.0, 0.0);
      else colFocus1 = glm::vec3(0.9, 0.2, 0.2);
      glUniform3fv(colFocus1Loc, 1, &colFocus1[0]);
    break;

  case Qt::Key_E:
      activ2 = !activ2;
      if(activ2) colFocus2 = glm::vec3(0.0, 0.0, 0.0);
      else colFocus2 = glm::vec3(0.2, 0.9, 0.2);
      glUniform3fv(colFocus2Loc, 1, &colFocus2[0]);
    break;

  case Qt::Key_P:
      activ3 = !activ3;
      if(activ3) colFocus3 = glm::vec3(0.0, 0.0, 0.0);
      else colFocus3 = glm::vec3(0.2, 0.2, 0.9);
      glUniform3fv(colFocus3Loc, 1, &colFocus3[0]);
    break;

  default: LL4GLWidget::keyPressEvent(event); break;
  }
  update();
}
