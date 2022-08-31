#include "ExamGLWidget.h"

class MyGLWidget:public ExamGLWidget
{
  Q_OBJECT

  public:
    MyGLWidget(QWidget *parent=0) : ExamGLWidget(parent) {}
    ~MyGLWidget();

  protected:
    virtual void paintGL ();
    virtual void keyPressEvent(QKeyEvent* event);
    virtual void modelTransformCub (float escala, float angle);
    virtual void modelTransformPatricio ();
    virtual void projectTransform ();
    virtual void viewTransform ();

  private:
    int printOglError(const char file[], int line, const char func[]);

    float angleP;
    bool pintaP;

    float cub1 = 0.0;
    float cub2 = float(2*M_PI/3);
    float cub3 = float(4*M_PI/3);

    int pos_patricio = 1;

    bool llum_blanca;
    public slots:
      void canviarOrto();
      void canviarPersp();
      void selecCub1();
      void selecCub2();
      void selecCub3();

    signals:
      void setOrto();
      void setPersp();
      void setCub1();
      void setCub2();
      void setCub3();

};
