#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileSystemModel>

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void about();
    void onLvFilesDoubleClicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    QFileSystemModel *fileModel;
    QMenu *helpMenu;
    QToolBar *fileToolBar;
    QAction *addToAct;
    QAction *extractAct;
    QAction *aboutAct;
    QAction *aboutQtAct;
private:
    void createFileModel();
    void createMenus();
    void createToolBars();
    void createActions();
};
#endif // MAINWINDOW_H
