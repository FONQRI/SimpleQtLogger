#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <fstream>
#include <iostream>
#include <string>

#include "custom_streambuf.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent), ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	custom_streambuf *out_buffer =
	new custom_streambuf(ui->textBrowser, "black");
	custom_streambuf *log_buffer =
	new custom_streambuf(ui->textBrowser, "green");
	custom_streambuf *error_buffer =
	new custom_streambuf(ui->textBrowser, "red");

	//	std::streambuf *oldBuf = std::cout.rdbuf();
	std::cout.rdbuf(out_buffer);
	std::clog.rdbuf(log_buffer);
	std::cerr.rdbuf(error_buffer);

	std::cout << "working output" << std::endl;
	std::clog << "working log" << std::endl;
	std::cerr << "working error" << std::endl;
}

MainWindow::~MainWindow() { delete ui; }
