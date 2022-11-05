#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QFile>
#include <QDate>
#include <QDebug>

/* Директивы имен таблицы, полей таблицы и базы данных */
#define DATABASE_HOSTNAME   "ExampleDataBase"
#define DATABASE_NAME       "raspisanie.db"

#define RASPISANIE              "RaspisanieTable"
#define RASPISANIE_WHATTODO     "WHATTODO"
#define RASPISANIE_DATA1     "DATA1"
#define RASPISANIE_DATA2     "DATA2"
#define RASPISANIE_DATA3     "DATA3"
#define RASPISANIE_DATA4     "DATA4"
#define RASPISANIE_DATA5     "DATA5"
#define RASPISANIE_DATA6     "DATA6"
#define RASPISANIE_DATA7     "DATA7"

class DataBase : public QObject
{
    Q_OBJECT
public:
    explicit DataBase(QObject *parent = 0);
    ~DataBase();
    /* Методы для непосредственной работы с классом
     * Подключение к базе данных и вставка записей в таблицу
     * */
    bool connectToDataBase();
    bool insertIntoTable(const QVariantList &data);

private:
    // Сам объект базы данных, с которым будет производиться работа
    QSqlDatabase    db;

private:
    /* Внутренние методы для работы с базой данных
     * */
    bool openDataBase();
    bool restoreDataBase();
    void closeDataBase();
    bool createTable();
};

#endif // DATABASE_H
