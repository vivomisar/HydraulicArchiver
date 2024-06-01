#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    createActions();
    createMenus();
    createFileModel();
}

void MainWindow::createFileModel(){
    fileModel = new QFileSystemModel(this);
    fileModel->setFilter(QDir::AllEntries);
    fileModel->setRootPath(QDir::homePath());
    ui->lvFiles->setModel(fileModel);
    connect(ui->lvFiles, SIGNAL(doubleClicked(QModelIndex)),this, SLOT(on_lvFiles_doubleClicked(QModelIndex)));
}

void MainWindow::createActions(){

}

void MainWindow::createToolBars(){

}

void MainWindow::createMenus(){

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_lvFiles_doubleClicked(const QModelIndex &index)
{
    QListView* listView = (QListView*)sender();
    QFileInfo fileInfo = fileModel->fileInfo(index);
    if(fileInfo.fileName() == ".."){
        QDir dir = fileInfo.dir();
        dir.cdUp();
        listView->setRootIndex(fileModel->index(dir.absolutePath()));
    }
    else if(fileInfo.fileName() == "."){
        listView->setRootIndex(fileModel->index(""));
    }
    else if(fileInfo.isDir()){
        listView->setRootIndex(index);
    }
}

