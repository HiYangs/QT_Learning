#include <QtGui>
#include <QAction>
#include "finddialog.h"
#include "gotocelldialog.h"
#include "mainwindow.h"
#include "sortdialog.h"
#include "spreadsheet.h"

MainWindow::MainWindow()
{
	//! 先创建一个Spreadsheet窗口部件
	//! 并且把它设置为这个主窗口的中央窗口部件
	spreadsheet = new spreadsheet;
	setCentralWidget(spreadsheet);

	//! 创建主窗口中的其余部分
	createActions();
	createMenus();
	createToolBars();
	createContextMenu();
	createStatusBar();

	//! 读取这个应用程序存储的一些设置
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
	//! 由于槽selectAll()是由QTableWidget的父类之一的QAbstractItemView提供的，所以就没有必要再去亲自实现它。

	showGridAction = new QAction(tr("&Show Grid"), this);
	showGridAction->setCheckable(true);
	showGridAction->setChecked(spreadsheet->showGrid());
	s
}

void MainWindow::


