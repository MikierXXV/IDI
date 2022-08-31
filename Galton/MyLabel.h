#include <QLabel>
class MyLabel:public QLabel 
{
	Q_OBJECT
	public:
		MyLabel(QWidget *parent);


	public slots:
        void reset();
        void changebola();
        void probabilidad();
        void jugar();

     signals:
        void borrar();
        void siguiente();
        void esquerra();
        void dreta();
		
};
