#include "LL2GLWidget.h"

#include "model.h"

class MyGLWidget : public LL2GLWidget {
  Q_OBJECT

  public:
    MyGLWidget(QWidget *parent=0) : LL2GLWidget(parent) {}
    ~MyGLWidget();
    virtual void keyPressEvent (QKeyEvent *event);
    virtual void mousePressEvent (QMouseEvent *event);
    virtual void mouseReleaseEvent (QMouseEvent *event);
    virtual void mouseMoveEvent (QMouseEvent *event);

  protected:
    virtual void iniCamera ();
    virtual void iniEscena ();
    virtual void viewTransform ();
    virtual void projectTransform ();
    virtual void homerTransform();
    virtual void terraTransform();
    virtual void paintGL ();
    

  private:
    int printOglError(const char file[], int line, const char func[]);

    float num_Homers;
    float radi_rollana;
    float angle_rollana;
    float angle;
    float psi, theta;
    float escalaH; 
    bool camara;
    float factorAngleX, factorAngleY;
    int ini;

    glm::vec3 posHomer;
    glm::vec3 distancia;


};
