#include "addtodialog.h"
#include "ui_addtodialog.h"

AddToDialog::AddToDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddToDialog)
{
    ui->setupUi(this);
}

AddToDialog::AddToDialog(QModelIndexList& list, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddToDialog)
    , list(list)
{
    ui->setupUi(this);
    connect(ui->pbAdd, &QPushButton::clicked, this, add);
    connect(ui->pbCancel, &QPushButton::clicked, this, &QDialog::close);
}

void AddToDialog::add()
{

}

AddToDialog::~AddToDialog()
{
    delete ui;
}
