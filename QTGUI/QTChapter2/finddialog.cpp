#include "finddialog.h"
#include <QtGui>
#include <QtWidgets>
// #include <QLabel>
// #include <QlineEdit>
// #include <QCheckBox>
// #include <QPushButton>
// #include <QHBoxLayout>
// #include <QVBoxLayout>

FindDialog::FindDialog(QWidget *parent)
	: QDialog(parent) //! 把parent参数传递给了基类的构造函数
{
	//! 在这些字符串中，使用了“&”来表示快捷键
	//! 符号“&”可以用来控制焦点
	label = new QLabel(tr("Find &what:"));
	lineEdit = new QLineEdit;

	//! 所谓“伙伴”(buddy),就是一个窗口部件，它可以在按下标签的快捷键时接收焦点(focus)
	label->setBuddy(lineEdit);

	caseCheckBox = new QCheckBox("Match &case");
	backwardCheckBox = new QCheckBox(tr("Search &backward"));

	//! 通过调用setDefault(true)让Find按钮成为对话框的默认按钮。
	//! 默认按钮就是当用户按下Enter键时能够按下对应的按钮
	findButton = new QPushButton(tr("&Find"));
	findButton->setDefault(true);
	//! 禁用了Find按钮。当禁用一个窗口部件时，它通常会显示为灰色
	findButton->setEnabled(false);

	closeButton = new QPushButton(tr("Close"));


	//! 只要行编辑器中的文本发生变化，就会调用私有槽enableFindButton(const QString&)
	connect(lineEdit, SIGNAL(textChanged(const QString&)), this, SLOT(enableFindButton(const QString&)));
	//! 当用户单击Find按钮时，会调用findClicked()私有槽。
	connect(findButton, SIGNAL(clicked()), this, SLOT(findClicked()));
	//! 而当用户单击close时，对话框会关闭。
	//! close()槽是从QWidget中继承而来的，并且它的默认行为就是把窗口部件从用户的事业中隐藏起来(而无需将其删除)。
	connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));

	QHBoxLayout *topLeftLayout = new QHBoxLayout;
	topLeftLayout->addWidget(label);
	topLeftLayout->addWidget(lineEdit);

	QVBoxLayout *leftLayout = new QVBoxLayout;
	leftLayout->addLayout(topLeftLayout);
	leftLayout->addWidget(caseCheckBox);
	leftLayout->addWidget(backwardCheckBox);

	QVBoxLayout *rightLayout = new QVBoxLayout;
	rightLayout->addWidget(findButton);
	rightLayout->addWidget(closeButton);
	rightLayout->addStretch();

	QHBoxLayout *mainLayout = new QHBoxLayout;
	mainLayout->addLayout(leftLayout);
	mainLayout->addLayout(rightLayout);
	setLayout(mainLayout);

	setWindowTitle(tr("Find"));
	setFixedHeight(sizeHint().height());
}

void FindDialog::enableFindButton(const QString &text)
{
	findButton->setEnabled(!text.isEmpty());
}

void FindDialog::findClicked()
{
	QString text = lineEdit->text();
	Qt::CaseSensitivity cs = caseCheckBox->isChecked() ? Qt::CaseSensitive : Qt::CaseInsensitive;

	if (backwardCheckBox->isChecked())
		emit findPrevious(text, cs);
	else
		emit findNext(text, cs);
}

