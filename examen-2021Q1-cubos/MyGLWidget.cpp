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
    pintaP = 1;
    llum_blanca = 1;
}

void MyGLWidget::paintGL ()   // Mètode que has de modificar
{
    // Esborrem el frame-buffer i el depth-buffer
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Pintem el terra
    glBindVertexArray (VAO_Terra);
    modelTransformTerra ();
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

    if (pintaP){
        // Pintem el Patricio
        glBindVertexArray (VAO_Patr);
        modelTransformPatricio ();
        glDrawArrays(GL_TRIANGLES, 0, patr.faces().size()*3);
    }
    else{
        // Pintem el cub
        glBindVertexArray(VAO_Cub);
        modelTransformCub (4.0, cub1);
        glDrawArrays(GL_TRIANGLES, 0, 36);

        // Pintem el cub2
        glBindVertexArray(VAO_Cub);
        modelTransformCub (5.0, cub2);
        glDrawArrays(GL_TRIANGLES, 0, 36);

        // Pintem el cub3
        glBindVertexArray(VAO_Cub);
        modelTransformCub (6.0, cub3);
        glDrawArrays(GL_TRIANGLES, 0, 36);
     }


    glBindVertexArray(0);
}

void MyGLWidget::modelTransformCub (float escala, float angle) 
{

    TG = glm::mat4(1.f);
    TG = glm::rotate(TG, angle, glm::vec3(0,1,0));
    TG = glm::translate(TG, glm::vec3(5,0,0));
    TG = glm::scale(TG, glm::vec3(escala, escala, escala));
    glUniformMatrix4fv (transLoc, 1, GL_FALSE, &TG[0][0]);

  /*ExamGLWidget::modelTransformCub (1.0, 0.0);
  // En aquest mètode has de substituir aquest codi per construir la 
  // transformació geomètrica (TG) del cub usant els paràmetres adientment*/
}

void MyGLWidget::modelTransformPatricio ()    // Mètode que has de modificar
{
    TG = glm::mat4(1.f);
    TG = glm::rotate(TG, angleP, glm::vec3(0,1,0));
    TG = glm::translate(TG, glm::vec3(5,0,0));
    TG = glm::scale(TG, glm::vec3 (2*escala, 2*escala, 2*escala));
    TG = glm::rotate(TG, float(3*M_PI/2), glm::vec3(0,1,0));
    TG = glm::translate(TG, -centreBasePat);

    glUniformMatrix4fv (transLoc, 1, GL_FALSE, &TG[0][0]);
}

void MyGLWidget::viewTransform ()    // Mètode que has de modificar
{
  if (!camPlanta)
    ExamGLWidget::viewTransform();
  else
  {
    // Codi per a la viewMatrix de la Càmera-2
    glm::mat4 View;
    View = glm::translate(glm::mat4(1.f), glm::vec3(0, 0, -2*radiEsc));
    View = glm::rotate(View,float(M_PI_2), glm::vec3(1, 0, 0));
    View = glm::rotate(View,float(M_PI_2), glm::vec3(0, 1, 0));
    View = glm::translate(View, -centreEsc);
    glUniformMatrix4fv (viewLoc, 1, GL_FALSE, &View[0][0]);

  }
}

void MyGLWidget::projectTransform ()
{
  if (!camPlanta)
    ExamGLWidget::projectTransform();
  else
  {
    // Codi per a la projectMatrix de la Càmera-2
     glm::mat4 Proj;
     if(ra<1) {
         Proj = glm::ortho (-radiEsc, radiEsc, -radiEsc/ra, radiEsc/ra, zn, zf);
     }
     else {
         Proj = glm::ortho (-radiEsc*ra, radiEsc*ra, -radiEsc, radiEsc, zn, zf);
     }
     glUniformMatrix4fv (projLoc, 1, GL_FALSE, &Proj[0][0]);
  }
}

void MyGLWidget::keyPressEvent(QKeyEvent* event) {
  makeCurrent();
  switch (event->key()) {
  case Qt::Key_V: {
      pintaP = !(pintaP);
    break;
	}
  case Qt::Key_1: {

      angleP = 0.0;
      pos_patricio = 1;
      setCub1();

    break;
	}
  case Qt::Key_2: {
      angleP = float(2*M_PI/3);
      pos_patricio = 2;
      setCub2();
    break;
	}
  case Qt::Key_3: {
      angleP = float(4*M_PI/3);
      pos_patricio = 3;
      setCub3();
      // ...
    break;
	}
  case Qt::Key_F: {
      // ...
      if(!llum_blanca) {
          colFoc = glm::vec3(1,1,1); //blanc
          enviaColFocus();
          llum_blanca=1;
      }
      else {
          colFoc = glm::vec3(1,1,0); //groc
          enviaColFocus();
          llum_blanca=0;
      }
    break;
	}
  case Qt::Key_C: {

     camPlanta = !(camPlanta);
     viewTransform();
     projectTransform();
     if(camPlanta) emit setOrto();
     else emit setPersp();
    break;
	}
  case Qt::Key_Right: {
      // ...
      if (cub1 == 0){
          cub1 = float(4*M_PI/3);
          cub2 = 0.0;
          cub3 = float(2*M_PI/3);
          if (pos_patricio == 1) angleP = float(4*M_PI/3);
          else if (pos_patricio == 2) angleP = 0.0 ;
          else angleP = float(2*M_PI/3);

      }
      else if (cub1 == float(2*M_PI/3)){
          cub1 = 0.0;
          cub2 = float(2*M_PI/3);
          cub3 = float(4*M_PI/3);
          if (pos_patricio == 1) angleP = 0.0;
          else if (pos_patricio == 2) angleP = float(2*M_PI/3);
          else angleP = float(4*M_PI/3);
      }
      else if (cub1 == float(4*M_PI/3)) {
          cub1 = float(2*M_PI/3);
          cub2 = float(4*M_PI/3);
          cub3 = 0.0;
          if (pos_patricio == 1) angleP = float(2*M_PI/3);
          else if (pos_patricio == 2) angleP = float(4*M_PI/3);
          else angleP = 0.0;
      }
     paintGL();
    break;
	}
  case Qt::Key_Left: {
      // ...
      if (cub1 == float(2*M_PI/3)){
          cub1 = float(4*M_PI/3);
          cub2 = 0.0;
          cub3 = float(2*M_PI/3);
          if (pos_patricio == 1) angleP = float(4*M_PI/3);
          else if (pos_patricio == 2) angleP = 0.0;
          else angleP = float(2*M_PI/3);

      }
      else if (cub1 == float(4*M_PI/3)){
          cub1 = 0.0;
          cub2 = float(2*M_PI/3);
          cub3 = float(4*M_PI/3);
          if (pos_patricio == 1) angleP = 0.0;
          else if (pos_patricio == 2) angleP = float(2*M_PI/3);
          else angleP = float(4*M_PI/3);
      }
      else if (cub1 == 0.0) {
          cub1 = float(2*M_PI/3);
          cub2 = float(4*M_PI/3);
          cub3 = 0.0;
          if (pos_patricio == 1) angleP = float(2*M_PI/3);
          else if (pos_patricio == 2) angleP = float(4*M_PI/3);
          else angleP = 0.0;
      }
     paintGL();
    break;
	}
  case Qt::Key_R: {
      // ...
      angleP = 0.0;
      pintaP = false;

      cub1 = 0.0;
      cub2 = float(2*M_PI/3);
      cub3 = float(4*M_PI/3);

      pos_patricio = 1;
      camPlanta = false;
      paintGL();
    break;
	}
  default: ExamGLWidget::keyPressEvent(event); break;
  }
  update();
}

void MyGLWidget::canviarOrto () {
    makeCurrent();
    camPlanta=1;
    viewTransform();
    projectTransform();
    update();

}
void MyGLWidget::canviarPersp () {
    makeCurrent();
    camPlanta=0;
    viewTransform();
    projectTransform();
    update();

}
void MyGLWidget::selecCub1 () {
    makeCurrent();
    angleP = 0.0;
    update();
}
void MyGLWidget::selecCub2 () {
    makeCurrent();
    angleP = float(2.*M_PI/3);
    update();
}
void MyGLWidget::selecCub3 () {
    makeCurrent();
    angleP = float((4*M_PI/3));
    update();
}
