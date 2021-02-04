//===============================================
#ifndef _GManager_
#define _GManager_
//===============================================
#include "GInclude.h"
//===============================================
typedef struct _sGManager sGManager;
typedef struct _sGApp sGApp;
typedef struct _sGStyle sGStyle;
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
    void showEnv();
    // string
    QMap<QString, QString> splitMap(QString str, QString sepRow, QString sepCol);
    QString removeLast(QString str, char remove) ;
    // post
    QString getPost();
    // redirect
    void redirect(QString newUrl);

private:
    static GManager* m_instance;
    sGManager* mgr;
};
//===============================================
// struct
//===============================================
struct _sGManager {
    sGApp* app;
    sGStyle* style;
};
//===============================================
struct _sGApp {
    // app
    QString app_name;
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
    // req
    QString req_string;
    QMap<QString, QString> req_map;
    // mime
    QString mime_type;
    // image
    QString image_id;
    // address
    QMap<QString, QString> address_map;
    // title
    QMap<QString, QString> title_map;
    // req
    QString req;
};
//===============================================
struct _sGStyle {
    // app
    const char* app_fg_color;
    const char* app_bg_color;
    const char* app_light_color;
    const char* app_font_size;
    const char* app_font_family;
};
//===============================================
#endif
//===============================================
