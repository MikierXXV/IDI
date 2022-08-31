#include <QApplication>
#include "Abacus.h"
int main(int argc, char **argv)
{
	QApplication app(argc, argv);
    Abacus form;
	form.show();
	return app.exec();
}
