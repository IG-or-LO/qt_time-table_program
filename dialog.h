#ifndef DIALOG_H
#define DIALOG_H
#include <QDialog>
#include <QLabel>
#include <QBoxLayout>
#include <QObject>
#include <QPushButton>
#include <stylehelper.h>

class Dialog:public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget* parent = 0);
    ~Dialog();

    void delete_or_not_dialog();
    void help_dialog();
    void about_dialog();
signals:
    void accept();

private:
    QLabel* answer;

    const QSize btnSize=QSize(120,40);
    QBoxLayout* layout_main;
    QBoxLayout* layout_h;
    QBoxLayout* layout_v;

    QPushButton* applyBtn;
    QPushButton* cancelBtn;


};

#endif // DIALOG_H
