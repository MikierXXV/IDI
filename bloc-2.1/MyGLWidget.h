// MyGLWidget.h
#include "BL2GLWidget.h"
#include "Model/model.h"

class MyGLWidget : public BL2GLWidget {
  Q_OBJECT

  public:
    MyGLWidget(QWidget *parent=0) : BL2GLWidget(parent) {}
    ~MyGLWidget();

    virtual void initializeGL();
    virtual void paintGL();
    virtual void resizeGL(int width, int height);
    virtual void keyPressEvent (QKeyEvent *event);
    virtual void mouseMoveEvent (QMouseEvent *e);

  private:
    int printOglError(const char file[], int line, const char func[]);
    void projectTransform();
    void viewTransform();
    void ini_camara();
    void creaBuffers();
    void carregaShaders();
    void modelTransform();
    void terraTransfrom();
    void calculaCapsaModel ();
    void calculaCapsaEscena ();
    void calculCentreEscena ();
    //void calculRadiEscena ();
    

    GLuint projLoc, viewLoc;
    GLuint VAO_Patricio, VAO_Terra;

    float scale, rotate, radi, distancia, escala, theta, phi, x_ant, y_ant;
    float FOV, FOVini, raw, znear, zfar, left, right, bottom, top;

    bool camara;

    glm::vec3 centreEscena, escenaMinima, escenaMaxima, centreBasePatricio;
    glm::vec3 OBS, VRP, UP;

    Model m;
};
