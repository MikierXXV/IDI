#include <QLabel>
class MyLabel:public QLabel 
{
	Q_OBJECT
	public:
		MyLabel(QWidget *parent);


	public slots:
        void reset();
        void incrementar();

     signals:
        void borrar();
        void siguiente();
		
};
