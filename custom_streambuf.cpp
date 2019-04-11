#include "custom_streambuf.h"

std::streamsize custom_streambuf::xsputn(const char *str, std::streamsize n)
{
	if (tbOut && n > 0)
	{
		tbOut->moveCursor(QTextCursor::End);
		tbOut->insertHtml(QString("<font color='%0'>").arg(color) +
				  QString::fromLatin1(str, static_cast<int>(n)) +
				  QString("</font><br>"));
	}

	return n;
}

custom_streambuf::custom_streambuf(QTextBrowser *tb, QString icolor)
	: tbOut(tb), color(icolor)
{
}
