#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include <QDialog>

class QCheckBox;
class QLabel;
class QLineEdit;
class QPushButton;

class FindDialog : public QDialog
{
	//! �������ж������źźͲ۵��࣬���ඨ�忪ʼ����Q_OBJECT�궼�Ǳ����
	Q_OBJECT

public:
	FindDialog(QWidget *parent = 0);

};
#endif

