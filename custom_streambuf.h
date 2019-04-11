#ifndef CUSTOM_STREAMBUF_H
#define CUSTOM_STREAMBUF_H

#include <fstream>
#include <iostream>
#include <streambuf>
#include <string>

#include <QTextBrowser>

class custom_streambuf : public std::streambuf
{
private:
	QTextBrowser *tbOut;
	QString color;

protected:
	virtual int_type overflow(int_type c)
	{
	if (c != traits_type::eof() && tbOut)
		{
		tbOut->moveCursor(QTextCursor::End);
		tbOut->insertHtml(QString("<font color='%0'>").arg(color) +
				  QChar(c) + QString("</font><br>"));
		return c;
		}
	return traits_type::eof();
	}

	// By default, superclass::xsputn call overflow method,
	// but for performance reason, here we override xsputn
	virtual std::streamsize xsputn(const char *str, std::streamsize n);

public:
	custom_streambuf(QTextBrowser *tb, QString icolor);
};

#endif // CUSTOM_STREAMBUF_H
