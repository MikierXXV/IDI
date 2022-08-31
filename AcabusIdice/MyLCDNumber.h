#include <QLCDNumber>
class MyLCDNumber:public QLCDNumber
{
	Q_OBJECT
	public:
        MyLCDNumber(QWidget *parent);
        int result;

	public slots:
        void reset();
        void representacio();

};
