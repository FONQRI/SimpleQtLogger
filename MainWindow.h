#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = nullptr);
	~MainWindow();

	void myMessageHandler(QtMsgType type, const QMessageLogContext &,
			  const QString &msg);

private:
	Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
