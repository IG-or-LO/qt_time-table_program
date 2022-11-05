#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //стартовая дата для таблицы
    data=QDateTime::currentDateTime();
    /* Первым делом необходимо создать объект для работы с базой данных
     * и инициализировать подключение к базе данных
     * */
    db = new DataBase();

    if(!db->connectToDataBase()){
          adding_data_for_db();
    }



    //вызов заполнения таблицы
    this->setupModel(RASPISANIE, QStringList() << ("id")
                                                   << ("Занятие")
                                                   << data.toString("dd.MM.yyyy")
                                                   << data.addDays(1).toString("dd.MM.yyyy")
                                                   << data.addDays(2).toString("dd.MM.yyyy")
                                                   << data.addDays(3).toString("dd.MM.yyyy")
                                                   << data.addDays(4).toString("dd.MM.yyyy")
                                                   << data.addDays(5).toString("dd.MM.yyyy")
                                                   << data.addDays(6).toString("dd.MM.yyyy")

                   );
    //метод для интерфейса
    setInterfaceStyle();

}

MainWindow::~MainWindow()
{
    delete ui;
}

//переопределение метода resizeEvent для background image
void MainWindow::resizeEvent(QResizeEvent *event){
    QPixmap bkgnd(":/resources/fon_raspisanie.jpg");
    bkgnd=bkgnd.scaled(size(),Qt::IgnoreAspectRatio);
    QPalette p=palette();
    p.setBrush(QPalette::Background, bkgnd);
    setPalette(p);

    QMainWindow::resizeEvent(event);
}

void MainWindow::setInterfaceStyle(){
    this->setWindowTitle("Raspisanie");
    //tableview style
    ui->tableView->horizontalHeader()->setObjectName("gorizHeader");
    ui->tableView->verticalHeader()->setObjectName("vertHeader");
    ui->tableView->horizontalHeader()->setStyleSheet(stylehelper::getGorizHeaderTableStyle());
    ui->tableView->verticalHeader()->setStyleSheet(stylehelper::getVertHeaderTableStyle());
    ui->tableView->setStyleSheet(stylehelper::getTableViewStyle());
    //buttons style
    ui->Button_adding_new->setStyleSheet(stylehelper::getButtonAddStyle());
    ui->Button_adding_new->setToolTip("Добавить строку");
    ui->Button_save->setStyleSheet(stylehelper::getButtonSaveStyle());
    ui->Button_save->setToolTip("Сохранить");
    ui->Button_delete_row->setStyleSheet(stylehelper::getButtonDeleteLineStyle());
    ui->button_deleteAll->setStyleSheet(stylehelper::getButtonDeleteAllStyle());
    ui->Button_Close->setStyleSheet(stylehelper::getButtonCloseStyle());
    //menu style
    ui->menu->setStyleSheet(stylehelper::getMenuStyle());
    ui->menu_2->setStyleSheet(stylehelper::getMenuStyle());
    ui->menubar->setStyleSheet(stylehelper::getMenuBarStyle());

    //tableview params
    ui->tableView->setModel(model);     // Устанавливаем модель на TableView
    ui->tableView->setColumnHidden(0, true);    // Скрываем колонку с id записей
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);// Разрешаем выделение строк
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection); // Устанавливаем режим выделения лишь одно строки в таблице
    ui->tableView->resizeColumnsToContents();// Устанавливаем размер колонок по содержимому
    ui->tableView->setColumnWidth(1,253);

       model->select(); // Делаем выборку данных из таблицы
}


void MainWindow::adding_data_for_db()
{
    /* Наполним базу данных записями */
    for(int i = 0; i < what_to_do_list.size(); i++)
    {
        db->insertIntoTable(QVariantList()
                                                << what_to_do_list.at(i)
                                               << "30MIN"
                                               << "30MIN"
                                               << "30MIN"
                                               << "30MIN"
                                               << "30MIN"
                                               << "30MIN"
                                               << "30MIN"
                               );
    }
}

void MainWindow::setupModel(const QString &tableName, const QStringList &headers)
{
    /* Производим инициализацию модели представления данных
       * с установкой имени таблицы в базе данных, по которому
       * будет производится обращение в таблице
       * */
      model = new QSqlTableModel(this);
      model->setTable(tableName);

      /* Устанавливаем названия колонок в таблице с сортировкой данных
       * */
      for(int i = 0, j = 0; i < model->columnCount(); i++, j++){
          model->setHeaderData(i,Qt::Horizontal,headers[j]);
      }
      // Устанавливаем сортировку по возрастанию данных по нулевой колонке
      model->setSort(0,Qt::AscendingOrder);
      model->setEditStrategy(QSqlTableModel::OnManualSubmit);

}



void MainWindow::on_Button_Close_clicked()
{
    this->close();

}

void MainWindow::on_Button_save_clicked()
{
    if(model->submitAll()){
        qDebug()<<"submit done";
    }
    else
        qDebug()<<model->lastError();
}

void MainWindow::on_Button_adding_new_clicked()
{
   if( model->insertRow(model->rowCount()))
       qDebug()<<"row addit";
   else
       qDebug()<<model->lastError();
}

void MainWindow::on_Button_delete_row_clicked()
    {
        if(model->removeRow(ui->tableView->currentIndex().row())){
            qDebug()<<"row delete";
            model->submitAll();
        }
        else
            qDebug()<<model->lastError();
    }

void MainWindow::on_button_deleteAll_clicked()
{
    Dialog dlg(this);
    dlg.delete_or_not_dialog();
    connect(&dlg,&Dialog::accept, this, &MainWindow::onApllied);
    dlg.exec();




}

void MainWindow::on_button_print_triggered()
{
    //установка ориентации страницы распечатки
 printer.setPageOrientation(QPageLayout::Landscape);
 //диалог распечтки
    QPrintDialog dialog(&printer,this);
    dialog.setWindowTitle(tr("Print Document"));

    if(dialog.exec()==QDialog::Accepted){
        QPainter painter (&printer);
        ui->tableView->render(&painter);
    }
    else
        qDebug()<<"cant open print dialog";

}

void MainWindow::on_button_defaultTable_triggered()
{
    onApllied();
    adding_data_for_db();
    model->submitAll();
}

void MainWindow::onApllied()
{
    if(model->removeRows(0,model->rowCount())){
      qDebug()<<"rows delete";
    }
    else
      qDebug()<<model->lastError();

        model->submitAll();

}

void MainWindow::on_action_about_triggered()
{
    Dialog dlg(this);
    dlg.about_dialog();
    dlg.exec();
}

void MainWindow::on_action_help_triggered()
{
    Dialog dlg(this);
    dlg.help_dialog();
    dlg.exec();
}
