#include <QtGui>
#include <QAction>
#include "finddialog.h"
#include "gotocelldialog.h"
#include "mainwindow.h"
#include "sortdialog.h"
#include "spreadsheet.h"

MainWindow::MainWindow()
{
	//! �ȴ���һ��Spreadsheet���ڲ���
	//! ���Ұ�������Ϊ��������ڵ����봰�ڲ���
	spreadsheet = new spreadsheet;
	setCentralWidget(spreadsheet);

	//! �����������е����ಿ��
	createActions();
	createMenus();
	createToolBars();
	createContextMenu();
	createStatusBar();

	//! ��ȡ���Ӧ�ó���洢��һЩ����
	readSettings();

	findDialog = 0;
	//setWindowIcon()

	setCurrentFile("");
}

void MainWindow::createActions()
{
	newAction = new QAction(tr("&New"), this);
	newAction->setIcon(QIcon(":/images/new.png"));
	newAction->setShortcut(QKeySequence::New);
	newAction->setStatusTip(tr("Create a new spreadsheet file"));
	connect(newAction, SIGNAL(triggered()), this, SLOT(newFile()));

	for (int i = 0; i < MaxRecentFiles; ++i)
	{
		recentFileActions[i] = new QAction(this);
		recentFileActions[i]->setVisible(false);
		connect(recentFileActions[i], SIGNAL(triggered()), this, SLOT(openRecentFile()));
	}

	exitAction = new QAction(("E&xit"), this);
	exitAction->setShortcut(tr("Ctrl+Q"));
	exitAction->setStatusTip(tr("Exit the application"));
	connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));

	selectAllAction = new QAction(tr("&All"), this);
	selectAllAction->setShortcut(QKeySequence::SelectAll);
	selectAllAction->setStatusTip(tr("Select all the cells in the spreadsheet"));
	connect(selectAllAction, SIGNAL(triggered()), spreadsheet, SLOT(selectAll()));
	//! ���ڲ�selectAll()����QTableWidget�ĸ���֮һ��QAbstractItemView�ṩ�ģ����Ծ�û�б�Ҫ��ȥ����ʵ������

	showGridAction = new QAction(tr("&Show Grid"), this);
	showGridAction->setCheckable(true);
	showGridAction->setChecked(spreadsheet->showGrid());
	s
}

void MainWindow::


