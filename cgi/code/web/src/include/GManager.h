//===============================================
#ifndef _GManager_
#define _GManager_
//===============================================
#include "GInclude.h"
#include "GWidget.h"
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
    QString getPost(QString key);
    bool isPost();
    // redirect
    void redirect(QString newUrl);
    void redirectPost(QString newUrl);
    // page
    void selectPage();
    // cookie
    void setCookie(QString key, QString value);
    QString getCookie(QString key);
    // file
    QString getUploadFile(QString key, QString dir);
    void uploadFile(QString key, QString dir);
    QString getFilePath(QString dir);
    QString getFilePath(QString dir, QString filename);
    QStringList getFileList(QString dir);
    QStringList getFileFilters(QString dir);
    // dir
    void createDir(QString path);
    // user
    QString getUsername();
    // log
    void log(const char* format, ...);
    // date
    void Date(char* buffer);

private:
    static GManager* m_instance;
    sGManager* mgr;
    rude::CGI cgi;
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
    GWidget* page_map;
    QString page_id;
    QString page_last;
    // query
    QString query_string;
    QMap<QString, QString> query_map;
    // cookie
    QString cookie_string;
    QMap<QString, QString> cookie_map;
    // image
    QString image_file;
    QString image_path;
    QString image_run;
    // title
    QMap<QString, QString> title_map;
    // req
    QString req;
    // user
    QString user_name;
    // action
    QString action;
    // log
    QString log_path;
    // cgi
    rude::CGI* cgi;
    // opencv
    QString opencv_state;
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
