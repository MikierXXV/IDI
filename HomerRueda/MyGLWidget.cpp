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

void MyGLWidget::iniEscena()
{
  midaTerra = 10.0;
  radi_rollana = 4.0;
  radiEscena = 7;
  distancia = glm::vec3(0,0,20);
  num_Homers = 1.0;
  //posHomer = glm::vec3(5, 0 ,5);
  angle = float(2*(M_PI)/10);
  factorAngleX = 0.03;
  factorAngleY = 0.03;
  ini = 10;

}

void MyGLWidget::iniCamera(){

  fov = float(M_PI)/4.0f;
  ra  = 1.0;
  znear =  0.001;
  zfar  = 40;
  camara = true;
  psi = float(M_PI)/2.0f;
  theta = float(M_PI)/4.0f;

  viewTransform();
  projectTransform();
}

void MyGLWidget::paintGL ()
{
  // descomentar per canviar paràmetres
  // glViewport (0, 0, ample, alt);

  // Esborrem el frame-buffer
  glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // Homer
    glBindVertexArray (VAO_Homer);
    for(int i = 0; i < ini; ++i){
      homerTransform();
      glDrawArrays(GL_TRIANGLES, 0, modelHomer.faces().size()*3);
      num_Homers += 1.0;
    }
    glBindVertexArray (0);


  // Terra
  terraTransform();
  glBindVertexArray (VAO_Terra);
  glDrawArrays(GL_TRIANGLES, 0, 6);
  glBindVertexArray (0);
}


void MyGLWidget::homerTransform ()
{
  // Matriu de transformació de Homer
  escalaH = 1.83/midaModelHomer;
  glm::mat4 TG(1.0f);
  TG = glm::rotate(TG, angle_rollana, glm::vec3(0,1,0));
  TG = glm::rotate(TG, (angle*num_Homers), glm::vec3(0,1,0));
  TG = glm::translate(TG, glm::vec3(-radi_rollana,0,0));
  TG = glm::scale(TG, glm::vec3(1 ,escalaH, 1));
  TG = glm::rotate(TG, float(M_PI/2), glm::vec3(0,1,0));
  TG = glm::translate(TG, -baseHomer);
  glUniformMatrix4fv(transLoc, 1, GL_FALSE, &TG[0][0]);
}

void MyGLWidget::terraTransform ()
{
  // Matriu de transformació de l'escac
  glm::mat4 TG(1.0f);
  TG = glm::translate(TG, glm::vec3(-5,0,-5));
  TG = glm::scale(TG, glm::vec3(midaTerra, 1.0, midaTerra));
  glUniformMatrix4fv (transLoc, 1, GL_FALSE, &TG[0][0]);
}

void MyGLWidget::viewTransform ()
{
  // Matriu de posició i orientació de l'observador
  glm::mat4 View(1.0f);
  if (camara){
    View = glm::translate(View,-distancia);
    View = glm::rotate(View, theta ,glm::vec3(1,0,0));
    View = glm::rotate(View, -psi ,glm::vec3(0,1,0));
    View = glm::translate(View,-vrp);
  }
  else{
    obs = glm::vec3(0,10,0);
    vrp = glm::vec3(0,1,0);
    up = glm::vec3(-1,0,0);
    View = glm::lookAt (obs, vrp, up);
  }
  glUniformMatrix4fv (viewLoc, 1, GL_FALSE, &View[0][0]);
}

void MyGLWidget::projectTransform ()
{
  glm::mat4 Proj(1.0f);
  if (camara){
    Proj = glm::perspective (fov, ra, znear, zfar);
  }
  else{
    Proj = glm::ortho(-radiEscena, radiEscena, -radiEscena, radiEscena, znear, zfar);
  }
  glUniformMatrix4fv (projLoc, 1, GL_FALSE, &Proj[0][0]);
}


void MyGLWidget::keyPressEvent (QKeyEvent *event) {
  makeCurrent();
  switch (event->key()) {
    case Qt::Key_Plus:{
        //incrementar numero homers min-1, max-15
        ini += 1;
        if (ini > 15) ini = 15;
        angle = float(2*M_PI/(10+float(ini-10)));
        paintGL();
        break;
    }
    case Qt::Key_Minus:{
        //decrementar numero homers min-1, max 15
        ini -= 1;
        if (ini < 1) ini = 1;
        angle = float(2*M_PI/(10-float(10-ini)));
        paintGL();
        break;
    }
    case Qt::Key_Up:{
        //aumentar radio rollana 0.5, limitado a (1.5, 5)m
        radi_rollana += 0.5;
        if (radi_rollana > 5.0) radi_rollana = 5.0;
        break;
    }
    case Qt::Key_Down:{
        //disminuir radio rollana 0.5, limitado a (1.5, 5)m
        radi_rollana -= 0.5;
        if (radi_rollana < 1.5) radi_rollana = 1.5;
        break;
    }
    case Qt::Key_Right:{
        //rotar 5 grados sentido horario rollana
        angle_rollana += ((float)M_PI)/36;
        break;
    }
    case Qt::Key_Left:{
        //rotar 5 grados sentido antihorario rollana
        angle_rollana -= ((float)M_PI)/36;
        break;
    }
    case Qt::Key_C:{
        //reset
        camara = !camara;
        viewTransform();
        projectTransform();
        break;
    }
    case Qt::Key_R:{
        //reset
        num_Homers = 1.0;
        ini = 10;
        radi_rollana = 4.0;
        angle_rollana = 0.0;
        angle = float(2*(M_PI)/10);
	camara = true;
        paintGL();
        viewTransform();
        projectTransform();

        break;
    }

    default: event->ignore(); break;
  }
  update();

}

void MyGLWidget::mousePressEvent (QMouseEvent *e){
  xClick = e->x();
  yClick = e->y();

  if (e->button() & Qt::LeftButton &&
      ! (e->modifiers() & (Qt::ShiftModifier|Qt::AltModifier|Qt::ControlModifier)))
  {
    DoingInteractive = ROTATE;
  }

}

void MyGLWidget::mouseReleaseEvent (QMouseEvent *){
    DoingInteractive = NONE;
}

void MyGLWidget::mouseMoveEvent (QMouseEvent *e){
    makeCurrent();
    if(e->x() < xClick) psi -= factorAngleX;
    else if(e->x() > xClick) psi += factorAngleX;
    
    if(e->y() < yClick) theta -= factorAngleY;
    else if(e->y() > yClick) theta += factorAngleY;

  xClick = e->x();
  yClick = e->y();

  update ();
  viewTransform();
}

MyGLWidget::~MyGLWidget()
{

}
