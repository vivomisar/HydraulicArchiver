#ifndef ADDTODIALOG_H
#define ADDTODIALOG_H

#include <QDialog>
#include <QModelIndex>

namespace Ui
{
class AddToDialog;
}

class AddToDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddToDialog(QWidget *parent = nullptr);
    AddToDialog(QModelIndexList& list, QWidget *parent = nullptr);
    ~AddToDialog();

private:
    Ui::AddToDialog *ui;
};

#endif // ADDTODIALOG_H
