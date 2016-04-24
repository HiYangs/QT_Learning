#include "finddialog.h"
#include <QtGui>
#include <QLabel>
#include <QlineEdit>
#include <QCheckBox>
#include <QPushButton>

FindDialog::FindDialog(QWidget *parent)
	: QDialog(parent) //! ��parent�������ݸ��˻���Ĺ��캯��
{
	//! ����Щ�ַ����У�ʹ���ˡ�&������ʾ��ݼ�
	//! ���š�&�������������ƽ���
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

