#include <QtGui>
#include "gotoceldialog.h"

GoToCellDialog::GoToCellDialog(QWidget *parent) : QDialog(parent)
{
	//! 调用setupUi()函数来初始化窗体。
	//! 创建了用户接口后，
	//! setupUi()函数还会将哪些符合on_objectname_signalName()命名管理的任意槽与相应的objectName的signalName()信号连接接到一起
	//! 在这个例子中，这就意味着setupUi()函数将建立如下所示的信号-槽连接关系：
	//! connect(lineEdit, SIGNAL(textchanged(const QString&)), this, SLOT(on_lineEdit_textChanged()));
	setupUi(this);

	//! 检验器来限制输入的范围
	QRegExp regExp("[A-Za-z][1-9][0-9]{0,2}");
	lineEdit->setValidator(new QRegExpValidator(regExp, this));
	//! 通过把this传递给QRegExpValidator的构造函数，使它成为GoToCellDialog对象的一个子对象。

	

}