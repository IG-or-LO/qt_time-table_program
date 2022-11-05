#include "database.h"

DataBase::DataBase(QObject *parent) : QObject(parent)
{

}

DataBase::~DataBase()
{

}

/* Методы для подключения к базе данных
 * */
bool DataBase::connectToDataBase()
{
    /* Перед подключением к базе данных производим проверку на её существование.
     * В зависимости от результата производим открытие базы данных или её восстановление
     * */
    if(!QFile("./" DATABASE_NAME).exists()){
        this->restoreDataBase();
        return false;
    } else {
        this->openDataBase();
        return true;
    }
}

/* Методы восстановления базы данных
 * */
bool DataBase::restoreDataBase()
{
    if(this->openDataBase()){
        if(!this->createTable()){
            return false;
        } else {
            return true;
        }
    } else {
        qDebug() << "Не удалось восстановить базу данных";
        return false;
    }
    return false;
}

/* Метод для открытия базы данных
 * */
bool DataBase::openDataBase()
{
    /* База данных открывается по заданному пути
     * и имени базы данных, если она существует
     * */
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName(DATABASE_HOSTNAME);
    db.setDatabaseName("./" DATABASE_NAME);
    if(db.open()){
        return true;
    } else {
        return false;
    }
}

/* Методы закрытия базы данных
 * */
void DataBase::closeDataBase()
{
    db.close();
}

/* Метод для создания таблицы устройств в базе данных
 * */
bool DataBase::createTable()
{
    /* В данном случае используется формирование сырого SQL-запроса
     * с последующим его выполнением.
     * */
    QSqlQuery query;
    if(!query.exec( "CREATE TABLE " RASPISANIE  " ("
                            "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                            RASPISANIE_WHATTODO         " VARCHAR(255)  NOT NULL,"
                            RASPISANIE_DATA1            " VARCHAR(10)  NOT NULL,"
                            RASPISANIE_DATA2            " VARCHAR(10)  NOT NULL,"
                            RASPISANIE_DATA3            " VARCHAR(10)  NOT NULL,"
                            RASPISANIE_DATA4            " VARCHAR(10)  NOT NULL,"
                            RASPISANIE_DATA5            " VARCHAR(10)  NOT NULL,"
                            RASPISANIE_DATA6            " VARCHAR(10)  NOT NULL,"
                            RASPISANIE_DATA7            " VARCHAR(10)  NOT NULL "
                    " )"
                    )){
        qDebug() << "DataBase: error of create " <<RASPISANIE;
        qDebug() << query.lastError().text();
        return false;
    } else {
        return true;
    }
    return false;
}


/* Метод для вставки записи в таблицу устройств
 * */
bool DataBase::insertIntoTable(const QVariantList &data)
{
    /* Запрос SQL формируется из QVariantList,
     * в который передаются данные для вставки в таблицу.
     * */
    QSqlQuery query;
    /* В начале SQL запрос формируется с ключами,
     * которые потом связываются методом bindValue
     * для подстановки данных из QVariantList
     * */
    query.prepare("INSERT INTO " RASPISANIE " ( " RASPISANIE_WHATTODO", "
                                              RASPISANIE_DATA1", "
                                               RASPISANIE_DATA2", "
                                               RASPISANIE_DATA3", "
                                               RASPISANIE_DATA4", "
                                               RASPISANIE_DATA5", "
                                               RASPISANIE_DATA6", "
                                               RASPISANIE_DATA7 ") "
                  "VALUES (:WHATTODO, :DATA1, :DATA2, :DATA3 ,:DATA4 ,:DATA5 ,:DATA6 ,:DATA7 )");

    query.bindValue(":WHATTODO",       data[0].toString());
    query.bindValue(":DATA1",          data[1].toString());
    query.bindValue(":DATA2",          data[2].toString());
    query.bindValue(":DATA3",          data[3].toString());
    query.bindValue(":DATA4",          data[4].toString());
    query.bindValue(":DATA5",          data[5].toString());
    query.bindValue(":DATA6",          data[6].toString());
    query.bindValue(":DATA7",          data[7].toString());
    // После чего выполняется запросом методом exec()
    if(!query.exec()){
        qDebug() << "error insert into " << RASPISANIE;
        qDebug() << query.lastError().text();
        return false;
    } else {
        return true;
    }
    return false;
}
