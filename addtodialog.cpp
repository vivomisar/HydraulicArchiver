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
{
    ui->setupUi(this);
}

AddToDialog::~AddToDialog()
{
    delete ui;
}
