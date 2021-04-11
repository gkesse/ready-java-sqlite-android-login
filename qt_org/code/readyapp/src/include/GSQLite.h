//===============================================
#ifndef _GSQLite_
#define _GSQLite_
//===============================================
#include "GInclude.h"
//===============================================
class GSQLite {
private:
    GSQLite();
    
public:
    ~GSQLite();
    static GSQLite* Instance();
    void open();
    void createTables();
    void queryShow(QString sqlQuery, QString widthMap = "", int defaultWidth = 20);
    void queryWrite(QString sqlQuery);
    QString queryValue(QString sqlQuery);
    QVector<QString> queryCol(QString sqlQuery);
    QVector<QString> queryRow(QString sqlQuery);
    QVector<QVector<QString>> queryMap(QString sqlQuery);

private:
    static GSQLite* m_instance;
};
//===============================================
#endif
//===============================================