#include <QtGui/QApplication>
#include <QTextCodec>
#include <QFile>
#include <QFont>
#include <QMessageBox>

#include "Utils/Settings.h"
#include "MapWindow.h"
//#include "CoordinatesCatcher/CoordCatcherForm.h"

void SetTextCodec(const QString& codecName);
void SetApplicationStyle(QApplication& app, const QString& styleName);

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	SetTextCodec("UTF-8");

	SetApplicationStyle(a, "chrome");

	Utils::Settings::Instance()->SetUserName("postgres");
	Utils::Settings::Instance()->SetDbPassword("12");
	Utils::Settings::Instance()->SetSchemaName("objects");

	MapWindow* w = new MapWindow();
	w->show();

//	CoordCatcherForm * f = new CoordCatcherForm;
//	f->show();
	
	const int result( a.exec() );
	return result;
}

void SetTextCodec(const QString& codecName)
{
	QTextCodec *codec = QTextCodec::codecForName(codecName.toStdString().c_str());
	QTextCodec::setCodecForTr(codec);
	QTextCodec::setCodecForCStrings(codec);
	QTextCodec::setCodecForLocale(codec);
}

void SetApplicationStyle(QApplication& app, const QString& styleName)
{
	QFile file(QString("../Style/%1.qss").arg(styleName));
	file.open(QFile::ReadOnly);
	QString styleSheet(file.readAll());
	app.setStyleSheet(styleSheet);
}
