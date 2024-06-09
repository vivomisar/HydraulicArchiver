#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addtodialog.h"
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("Hydraulic Archiver"));
    createActions();
    createMenus();
    createToolBars();
    createFileModel();
}

void MainWindow::createFileModel()
{
    fileModel = new QFileSystemModel(this);
    fileModel->setFilter(QDir::AllEntries);
    fileModel->setRootPath(QDir::homePath());
    ui->lvFiles->setModel(fileModel);
    ui->lvFiles->setSelectionRectVisible(true);
    ui->lvFiles->setSelectionMode(QAbstractItemView::ExtendedSelection);
    connect(ui->lvFiles, SIGNAL(doubleClicked(QModelIndex)),this, SLOT(onLvFilesDoubleClicked(QModelIndex)));
}

void MainWindow::createActions()
{
    aboutAct = new QAction(tr("&About"), this);
    connect(aboutAct, SIGNAL(triggered()), SLOT(about()));

    aboutQtAct = new QAction(tr("About &Qt..."), this);
    connect(aboutQtAct, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
}

void MainWindow::createToolBars()
{
    QPixmap addPix(":/AddButton.png");
    QPixmap extractPix(":/ExtractButton.png");
    fileToolBar = addToolBar("Toolbar");
    addToAct = fileToolBar->addAction(QIcon(addPix), "Add to...");
    extractAct = fileToolBar->addAction(QIcon(extractPix), "Extract...");

    connect(addToAct, SIGNAL(triggered()), SLOT(addTo()));
    connect(extractAct, SIGNAL(triggered()), SLOT(extract()));
}

void MainWindow::createMenus()
{
    helpMenu = new QMenu(tr("&Help"), this);
    helpMenu->addAction(aboutAct);
    helpMenu->addAction(aboutQtAct);
    menuBar()->addMenu(helpMenu);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::about()
{
    QMessageBox::about(this, tr("About Hydraulic Archiver"), tr("OK"));
}

void MainWindow::addTo()
{
    auto selectedFiles = ui->lvFiles->selectionModel()->selectedIndexes();
    AddToDialog dialog(selectedFiles, this);
    dialog.exec();
}

void MainWindow::extract()
{

}
void MainWindow::onLvFilesDoubleClicked(const QModelIndex &index)
{
    QListView* listView = (QListView*)sender();
    QFileInfo fileInfo = fileModel->fileInfo(index);
    if(fileInfo.fileName() == "..") {
        QDir dir = fileInfo.dir();
        dir.cdUp();
        listView->setRootIndex(fileModel->index(dir.absolutePath()));
    } else if(fileInfo.fileName() == ".") {
        listView->setRootIndex(fileModel->index(""));
    } else if(fileInfo.isDir()) {
        listView->setRootIndex(index);
    }
}

