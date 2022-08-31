#include <QLCDNumber>
class MyLCDNumber:public QLCDNumber
{
	Q_OBJECT
	public:
        MyLCDNumber(QWidget *parent);
        int box1, box2, box3, box4, box5;
        int numballs;

	public slots:
        void reset();
        void incrementabox1();
        void incrementabox2();
        void incrementabox3();
        void incrementabox4();
        void incrementabox5();
        void incrementanumballs();

    signals:
        void resetpath();
};
