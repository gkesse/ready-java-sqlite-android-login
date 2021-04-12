//===============================================
#ifndef _GManager_
#define _GManager_
//===============================================
#include "GInclude.h"
#include "GWidget.h"
//===============================================
// struct
//===============================================
typedef struct _sGManager sGManager;
typedef struct _sGApp sGApp;
//===============================================
// manager
//===============================================
class GManager : public QObject {
    Q_OBJECT
    
private:
    GManager(QObject* parent = 0);
    
public:
    ~GManager();
    static GManager* Instance(QObject* parent = 0);
    // data
    sGManager* getData();
    void initData();
    // env
    QString getEnv(QString key);
    // style
    void loadStyle();
    // string
    int getWidth(QString widthMap, int index, int defaultWidth);
    // file
    QString getFilename(QString fullpath);
    QString getDirname(QString fullpath);
    QString openFile(QString title, QString filters);
    QString saveFile(QString title, QString filters);
    QString nextFile(QString filename, QStringList filters, QString message);
    QString previousFile(QString filename, QStringList filters, QString message);
    // property
    void setProperty(QWidget* widget, QString key, QVariant data);
    // picto
    QIcon loadPicto(int picto, QColor color = "white");
    // font
    void loadFont();
    // img
    void loadImg();
    // page
    void setPage(QString address);
    // layout
    void clearLayout(QLayout *layout);
    // crypto
    QString getCrypto(QString text);
    // message
    int showQuestion(QString text);
    int showInfo(QString text);
    // image
    void convertImage(const QPixmap& pixmap, QImage& img, cv::Mat& mat);
    void convertImage(const cv::Mat& mat, QImage& img, QPixmap& pixmap);
    // login
    int isLogin();
    // table
    QVector<QString> getTables();
    int countTable(QString table);
    void deleteTable(QString table);
    // config_data
    void saveData(QString key, QString value);
    QString loadData(QString key);
    int countData(QString key);
    void updateData(QString key, QString value);
    void insertData(QString key, QString value);
    // users
    int countUser(QString username);
    int countUser(QString username, QString password);
    void addUser(QString username, QString password);
    QVector<QVector<QString>> getUser();
    void deleteUser(QString username);

private:
    static GManager* m_instance;
    sGManager* mgr;
    QtAwesome* m_QtAwesome;
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
    // style
    QString style_path;
    // win
    GWidget* win;
    int win_width;
    int win_height;
    // page
    GWidget* page_map;
    // widget
    QWidget* widget;
    QString widget_id;
    // font
    QString font_path;
    // img
    QString img_path;
    QMap<QString, QString> img_map;
    QString img_filter;
    QStringList img_filters;
    // picto
    QColor picto_color;
    // address
    QLineEdit* address;
    QString address_url;
    QString address_new;
    GWidget* address_key;
    // title
    QLabel* title;
    QMap<QString, QString> title_map;
    // profil
    int profil_size;
    // grip
    int grip_size;
    // login
    QString login_on;
    QPushButton* login_titlebar;
    QPushButton* login_home;
    // sqlite
    QString sqlite_db_path;
    // root
    QString root_user;
    QString root_pass;
    // pdf
    QString pdf_path;
    // path
    QString path_sep;
    // debug
    QTextEdit* debug;
    // dir
    QString dir_path;
};
//===============================================
#endif
//===============================================