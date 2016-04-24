#include "finddialog.h"
#include <QtGui>
#include <QLabel>
#include <QlineEdit>
#include <QCheckBox>
#include <QPushButton>

FindDialog::FindDialog(QWidget *parent)
	: QDialog(parent) //! 把parent参数传递给了基类的构造函数
{
	//! 在这些字符串中，使用了“&”来表示快捷键
	//! 符号“&”可以用来控制焦点
	label = new QLabel(tr("Find &what:"));
	lineEdit = new QLineEdit;
	label->setBuddy(lineEdit);

	caseCheckBox = new QCheckBox("Match &case");
	backwardCheckBox = new QCheckBox(tr("Search &backward"));

	findButton = new QPushButton(tr("&Find"));
	findButton->setDefault(true);
	findButton->setEnabled(false);

	closeButton = new QPushButton(tr("Close"));
}

void FindDialog::enableFindButton(const QString &text)
{

}

void FindDialog::findClicked()
{

}

