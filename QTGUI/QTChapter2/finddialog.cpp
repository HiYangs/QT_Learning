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
	: QDialog(parent) //! ��parent�������ݸ��˻���Ĺ��캯��
{
	//! ����Щ�ַ����У�ʹ���ˡ�&������ʾ��ݼ�
	//! ���š�&�������������ƽ���
	label = new QLabel(tr("Find &what:"));
	lineEdit = new QLineEdit;

	//! ��ν����顱(buddy),����һ�����ڲ������������ڰ��±�ǩ�Ŀ�ݼ�ʱ���ս���(focus)
	label->setBuddy(lineEdit);

	caseCheckBox = new QCheckBox("Match &case");
	backwardCheckBox = new QCheckBox(tr("Search &backward"));

	//! ͨ������setDefault(true)��Find��ť��Ϊ�Ի����Ĭ�ϰ�ť��
	//! Ĭ�ϰ�ť���ǵ��û�����Enter��ʱ�ܹ����¶�Ӧ�İ�ť
	findButton = new QPushButton(tr("&Find"));
	findButton->setDefault(true);
	//! ������Find��ť��������һ�����ڲ���ʱ����ͨ������ʾΪ��ɫ
	findButton->setEnabled(false);

	closeButton = new QPushButton(tr("Close"));


	//! ֻҪ�б༭���е��ı������仯���ͻ����˽�в�enableFindButton(const QString&)
	connect(lineEdit, SIGNAL(textChanged(const QString&)), this, SLOT(enableFindButton(const QString&)));
	//! ���û�����Find��ťʱ�������findClicked()˽�вۡ�
	connect(findButton, SIGNAL(clicked()), this, SLOT(findClicked()));
	//! �����û�����closeʱ���Ի����رա�
	//! close()���Ǵ�QWidget�м̳ж����ģ���������Ĭ����Ϊ���ǰѴ��ڲ������û�����ҵ����������(�����轫��ɾ��)��
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

