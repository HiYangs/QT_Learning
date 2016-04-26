#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QAction;
class QLabel;
class FindDialog;
class Spreadsheet;


//! 我们将MainWindow类定义为QMainWindow类的子类。
//! 由于MianWindow提供了自己的信号和槽，所以它包含了Q_OBJECT宏
class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow();

protected:
	//! closeEvent是QWidget类中的一个虚函数，当用户关闭窗口时，这个函数会被自动调用。
	//! 类MMainWindow中重新实现了它，这样就可以向用户询问一个标准问题，并且可以把用户的一些偏好设置保存到磁盘中。
	void closeEvent(QCloseEvent *event);

private slots:
	//! 当槽作为一个信号的响应函数而被执行时，就会忽略这个返回值；
	//! 但是当把槽作为函数来调用时，其返回值对我们的作用就和调用任何一个普通的C++函数时的作用是相同的。
	void newFile();
	void open();
	bool save();
	bool saveAs();
	void find();
	void goToCell();
	void sort();
	void about();
	void openRecentFile();
	void updateStatusBar();
	void spreadsheetModified();

private:
	void createActions();
	void createMenus();
	void createContextMenu();
	void createToolBars();
	void createStatusBar();
	void readSettings();
	void writeSettings();
	bool okToContinue();
	bool loadFile(const QString &fileName);
	bool saveFile(const QString &fileName);
	void setCurrentFile(const QString &fileName);
	void updateRecentFileActions();
	QString strippedName(const QString &fullFileName);


	Spreadsheet *spreadsheet;
	FindDialog *findDialog;
	QLabel *locationLabel;
	QLabel *formulaLabel;
	QStringList recentFiles;
	QString curFile;

	enum { MaxRecentFiles = 5};
	QAction *recentFileActions[MaxRecentFiles];
	QAction *separatorAction;

	QMenu *fileMenu;
	QMenu *editMenu;

	QToolBar *fileToolBar;
	QToolBar *editToolBar;
	QAction *newAction;
	QAction *openAction;

	QAction *aboutQtAction;
};
#endif // !MAINWINDOW_H
