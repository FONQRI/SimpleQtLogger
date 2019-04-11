#include "MainWindow.h"

#include <QApplication>

#include <iostream>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow w;
	w.show();

	//	char Buffer[50]{"hello"};
	//    std::clog << Buffer << std::endl;

	return a.exec();
}
