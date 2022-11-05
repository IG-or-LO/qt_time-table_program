#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlTableModel>
#include <QPrinter>
#include <QPrintDialog>
#include <QPainter>
#include <QFileDialog>
/* My includes */
#include <database.h>
#include <dialog.h>
#include <stylehelper.h>
#include <QPixmap>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_Button_Close_clicked();

    void on_Button_save_clicked();

    void on_Button_adding_new_clicked();

    void on_button_deleteAll_clicked();

    void onApllied();

    void on_button_print_triggered();

    void on_button_defaultTable_triggered();

    void on_Button_delete_row_clicked();

    void on_action_about_triggered();

    void on_action_help_triggered();

private:
    Ui::MainWindow  *ui;
    DataBase        *db;
    QSqlTableModel  *model;

    QStringList     what_to_do_list={"Утренняя зарядка",
                                     "Колледж",
                                     "Самообучение",
                                     "Cпорт",
                                     "Английский язык",
                                     "Чтение",
                                     "Свободное время"
                                    };
    QDateTime data;


 QPrinter printer;


 void adding_data_for_db();
 void setupModel(const QString &tableName, const QStringList &headers);

 void setInterfaceStyle();
//метод перегрузки для правильного scales background
void resizeEvent(QResizeEvent *event);

};

#endif // MAINWINDOW_H
