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

void MyGLWidget::initializeGL() {
    initializeOpenGLFunctions();
    glClearColor(0.5, 0.7, 1.0, 1.0);

    m.load("./models/Patricio.obj");

    carregaShaders();
    creaBuffers();
    glEnable(GL_DEPTH_TEST);

    scale = 1.0f;
    rotate = 0.0f;

    calculaCapsaModel();
    calculCentreEscena();

    ini_camara();
}

void MyGLWidget::ini_camara(){

    distancia = radi * 2.0;
    FOVini = 2.0 * asin(radi/distancia);
    FOV = FOVini;
    raw = 1.0f ;
    znear =  distancia - radi;
    zfar = distancia + radi;

    VRP = glm::vec3(centreEscena);
    OBS = glm::vec3(0,0,radi*2.0);
    UP = glm::vec3(0,1,0);
    
    theta = 0.0;
    phi = 0.0;

    left = -2.5;
    right = 2.5;
    top = 2.0;
    bottom = -2.0;

    camara = false;

    projectTransform();
    viewTransform();

}

void MyGLWidget::paintGL(){


    // Esborrem el frame-buffer
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Carreguem la transformació de model
    modelTransform ();

    // Activem el VAO per a pintar la caseta
    glBindVertexArray (VAO_Patricio);

    // pintem
    glDrawArrays(GL_TRIANGLES, 0, m.faces().size() *3);

    terraTransfrom();

    glBindVertexArray(VAO_Terra);
    
    glDrawArrays(GL_TRIANGLES, 0, 6);

    glBindVertexArray (0);
}

void MyGLWidget::modelTransform(){
    glm::mat4 transform (1.0f);
    transform = glm::rotate(transform, rotate, glm::vec3(0.0, 1.0, 0.0));
    transform = glm::scale(transform, glm::vec3(scale));
    transform = glm::scale(transform, glm::vec3(escala));
    transform = glm::translate(transform, -centreBasePatricio);
    glUniformMatrix4fv(transLoc, 1, GL_FALSE, &transform[0][0]);
}

void MyGLWidget::terraTransfrom(){
    glm::mat4 transform(1.0f);
    //transform = glm::scale(transform, glm::vec3(scale));
    glUniformMatrix4fv(transLoc, 1, GL_FALSE, &transform[0][0]);
}

void::MyGLWidget::viewTransform(){
   //glm::lookAt(OBS, VRP, UP)
    /*glm::mat4 View = glm::lookAt(OBS, VRP, UP);
    glUniformMatrix4fv (viewLoc, 1, GL_FALSE, &View[0][0]);*/;
    glm::mat4 View(1.0);
    View = glm::translate(View, glm::vec3(0.,0.,-distancia));
    View = glm::rotate(View, theta, glm::vec3(1.,0.,0.));
    View = glm::rotate(View, -phi, glm::vec3(0.,1.,0.));
    glUniformMatrix4fv (viewLoc, 1, GL_FALSE, &View[0][0]);
}

void MyGLWidget::projectTransform(){
    // glm::perspective (FOV en radians, ra window, znear, zfar)
     glm::mat4 Proj;
    if (not camara){
        Proj = glm::perspective(FOV, raw, znear, zfar);
    }
    else{
        Proj = glm::ortho(left, right, bottom, top, znear, zfar);
    }
    glUniformMatrix4fv (projLoc, 1, GL_FALSE, &Proj[0][0]);

}

void MyGLWidget::resizeGL (int w, int h)
{
    float rav = float(w) / float(h);
    raw = rav;
    if (rav < 1.0) FOV = 2.0 * atan(tan(FOVini/2.0)/rav);
    projectTransform();
    glViewport(0, 0, w, h);
    
}


void MyGLWidget::creaBuffers(){
    // Creació del Vertex Array Object per pintar
    glGenVertexArrays(1, &VAO_Patricio);
    glBindVertexArray(VAO_Patricio);

    GLuint VBO_Patricio[2];
    glGenBuffers(2, VBO_Patricio);
    glBindBuffer(GL_ARRAY_BUFFER, VBO_Patricio[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)* m.faces().size() *3 *3, m.VBO_vertices(), GL_STATIC_DRAW);

    // Activem l'atribut vertexLoc
    glVertexAttribPointer(vertexLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(vertexLoc);

    glBindBuffer(GL_ARRAY_BUFFER, VBO_Patricio[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)* m.faces().size() *3 *3, m.VBO_matdiff(), GL_STATIC_DRAW);

    // Activem l'atribut colorLoc
    glVertexAttribPointer(colorLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(colorLoc);

    glBindVertexArray (0);
    // Dades de la caseta
    // Dos VBOs, un amb posició i l'altre amb color
    glm::vec3 posicio[6] = {
      glm::vec3(2.5, 0, 2.5),
      glm::vec3(2.5, 0, -2.5),
      glm::vec3(-2.5, 0, -2.5),

      glm::vec3(2.5, 0, 2.5),
      glm::vec3(-2.5, 0, -2.5),
      glm::vec3(-2.5, 0, 2.5)
    };
    
     glm::vec3 color[6] = {
      glm::vec3(1,0,0),
      glm::vec3(0,0,1),
      glm::vec3(0,1,0),

      glm::vec3(1,0,0),
      glm::vec3(0,1,0),
      glm::vec3(0,0,1),
    };

    // Creació del Vertex Array Object per pintar
    glGenVertexArrays(1, &VAO_Terra);
    glBindVertexArray(VAO_Terra);

    GLuint VBO_Terra[2];
    glGenBuffers(2, VBO_Terra);
    glBindBuffer(GL_ARRAY_BUFFER, VBO_Terra[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(posicio), posicio, GL_STATIC_DRAW);

    // Activem l'atribut vertexLoc
    glVertexAttribPointer(vertexLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(vertexLoc);

    glBindBuffer(GL_ARRAY_BUFFER, VBO_Terra[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(color), color, GL_STATIC_DRAW);

    // Activem l'atribut colorLoc
    glVertexAttribPointer(colorLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(colorLoc);

    glBindVertexArray (0);
}

void MyGLWidget::carregaShaders(){
    BL2GLWidget::carregaShaders();
    projLoc = glGetUniformLocation(program->programId(), "proj");
    viewLoc = glGetUniformLocation(program->programId(), "view");
}

void MyGLWidget::keyPressEvent(QKeyEvent* event)
{
  makeCurrent();
  switch (event->key()) {
    case Qt::Key_S: { // escalar a més gran
      scale += 0.05;
      break;
    }
    case Qt::Key_D: { // escalar a més petit
      scale -= 0.05;
      break;
    }
    case Qt::Key_O: { // escalar a més petit
      camara = !camara;
      break;
    }
    case Qt::Key_R: {
        rotate += float(M_PI)/4.0f;
        break;
    }
    default: event->ignore(); break;
  }
  update();
}

void MyGLWidget::calculaCapsaModel(){
    float minx, miny, minz, maxx, maxy, maxz;
    minx = maxx = m.vertices()[0];
    miny = maxy = m.vertices()[1];
    minz = maxz = m.vertices()[2];
    for (unsigned int i = 3; i < m.vertices().size(); i+=3)
    {
      if (m.vertices()[i] < minx) minx = m.vertices()[i];
      if (m.vertices()[i] > maxx) maxx = m.vertices()[i];
      if (m.vertices()[i+1] < miny) miny = m.vertices()[i+1];
      if (m.vertices()[i+1] > maxy) maxy = m.vertices()[i+1];
      if (m.vertices()[i+2] < minz) minz = m.vertices()[i+2];
      if (m.vertices()[i+2] > maxz) maxz = m.vertices()[i+2];
    }
    escala = 4.0/(maxy-miny);
    centreBasePatricio = glm::vec3((minx+maxx)/2, miny, (minz+maxz)/2);
    escenaMaxima.y = 4.0;
    //radi escena
    radi =  sqrt(((maxx - minx)*(maxx - minx)) + ((maxy - miny)*(maxy - miny))
                                      + ((maxz - minz)*(maxz - minz)))/2.0;
    //VRP = glm::vec3((maxx + minx)/2.0, (maxy + miny)/2.0, (maxz + minz)/2.0);
}

void MyGLWidget::calculaCapsaEscena(){
    escenaMaxima.x = 2.5;
    escenaMaxima.z = 2.5;
    escenaMinima = glm::vec3(-2.5, 0.0, -2.5);
}

void MyGLWidget::calculCentreEscena(){
    centreEscena = (escenaMaxima + escenaMinima);
    centreEscena = centreEscena / glm::vec3(2.0);

}

void MyGLWidget::mouseMoveEvent(QMouseEvent *e) {
	makeCurrent();
	
	if(e->x() > x_ant) phi -= 0.03;
	else if(e->x() < x_ant) phi += 0.03;
	
	if(e->y() > y_ant) theta -= 0.03;
	else if(e->y() < y_ant) theta += 0.03;
	
	x_ant = e->x();
	y_ant = e->y();
	viewTransform();
	update();
}

MyGLWidget::~MyGLWidget() {

}


