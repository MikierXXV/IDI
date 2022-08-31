// MyGLWidget.h
#include "LL4GLWidget.h"

class MyGLWidget : public LL4GLWidget {
  Q_OBJECT

  public:
    MyGLWidget(QWidget *parent=0) : LL4GLWidget(parent) {}
    ~MyGLWidget();

  protected:
    virtual void keyPressEvent(QKeyEvent* event);
    virtual void carregaShaders();
    virtual glm::mat4 calculaPatricioTG();
    virtual void initializeGL();
    virtual void calculaMaPatricio();
    virtual void calculaFocus();
    virtual void modelTransformPatricio();
    GLuint colFocus1Loc, posFocus1Loc;
    GLuint colFocus2Loc, posFocus2Loc;
    GLuint colFocus3Loc, posFocus3Loc;
    GLuint TGpatLoc;

  private:
    int printOglError(const char file[], int line, const char func[]);
    float anglePatricio;
    float x, z;
    int x1, z1;
    bool activ1, activ2, activ3;

    glm::vec3 colFocus1, posFocus1;
    glm::vec3 colFocus2, posFocus2;
    glm::vec3 posFocus3, colFocus3;

    glm::mat4 TGpat;

    


};
