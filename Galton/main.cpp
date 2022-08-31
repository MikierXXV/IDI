#include <QApplication>
#include "Galton.h"
int main(int argc, char **argv)
{
	QApplication app(argc, argv);
    Galton form;
	form.show();
	return app.exec();
}
