#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include <QDialog>

class QCheckBox;
class QLabel;
class QLineEdit;
class QPushButton;

class FindDialog : public QDialog
{
	//! 对于所有定义了信号和槽的类，在类定义开始出的Q_OBJECT宏都是必需的
	Q_OBJECT

public:
	FindDialog(QWidget *parent = 0);

};
#endif

