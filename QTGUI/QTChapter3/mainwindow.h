#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QAction;
class QLabel;
class FindDialog;
class Spreadsheet;


//! ���ǽ�MainWindow�ඨ��ΪQMainWindow������ࡣ
//! ����MianWindow�ṩ���Լ����źźͲۣ�������������Q_OBJECT��
class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow();

protected:
	//! closeEvent��QWidget���е�һ���麯�������û��رմ���ʱ����������ᱻ�Զ����á�
	//! ��MMainWindow������ʵ�������������Ϳ������û�ѯ��һ����׼���⣬���ҿ��԰��û���һЩƫ�����ñ��浽�����С�
	void closeEvent(QCloseEvent *event);

private slots:
	//! ������Ϊһ���źŵ���Ӧ��������ִ��ʱ���ͻ�����������ֵ��
	//! ���ǵ��Ѳ���Ϊ����������ʱ���䷵��ֵ�����ǵ����þͺ͵����κ�һ����ͨ��C++����ʱ����������ͬ�ġ�
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
