//===============================================
#ifndef _GManager_
#define _GManager_
//===============================================
#include "GInclude.h"
//===============================================
typedef struct _sGManager sGManager;
typedef struct _sGApp sGApp;
//===============================================
// manager
//===============================================
class GManager {
private:
    GManager();
    
public:
    virtual ~GManager();
    static GManager* Instance();
    // data
    sGManager* getData();
    // env
    QString getEnv(QString key);
    void loadEnv();
    // string
    QMap<QString, QString> splitMap(QString str, QString sepRow, QString sepCol);
    QString removeLast(QString str, char remove) ;
    // query
    QString getQuery(QString key, QString defaultValue);
    // cookie
    QString getCookie(QString key, QString defaultValue);
    
private:
    static GManager* m_instance;
    sGManager* mgr;
};
//===============================================
// struct
//===============================================
struct _sGManager {
    sGApp* app;
};
//===============================================
struct _sGApp {
    // app
    QString app_name;
    QString app_title;
    // logo
    QString logo_path;
    // style
    QString style_path;
    // font
    QString font_path;
    // icon
    QString icon_path;
    // page
    QString page_id;
    QString page_last;
    // query
    QString query_string;
    QMap<QString, QString> query_map;
    // cookie
    QString cookie_string;
    QMap<QString, QString> cookie_map;
    // mime
    QString mime_type;
};
//===============================================
#endif
//===============================================
