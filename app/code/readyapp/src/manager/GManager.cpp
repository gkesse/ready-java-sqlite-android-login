//===============================================
#include "GManager.h"
#include "GMessageBox.h"
#include "GSQLite.h"
//===============================================
GManager* GManager::m_instance = 0;
//===============================================
// constructor
//===============================================
GManager::GManager(QObject* parent) {
    // manager
    mgr = new sGManager;
    // app
    mgr->app = new sGApp;
    mgr->app->app_name = "ReadyApp";
    mgr->app->style_path = getEnv("GSTYLE_PATH");
    mgr->app->win_width = 640;
    mgr->app->win_height = 480;
    mgr->app->font_path = getEnv("GFONT_PATH");
    mgr->app->img_path = getEnv("GIMG_PATH");
    mgr->app->picto_color = "white";
    mgr->app->address_url = "";   
    mgr->app->profil_size = 150;
    mgr->app->grip_size = 16;
    mgr->app->login_on = "off";
    mgr->app->sqlite_db_path = getEnv("GSQLITE_DB_PATH");
    mgr->app->root_user = "root";
    mgr->app->root_pass = "super";
    mgr->app->pdf_path = getEnv("GPDF_PATH");
    mgr->app->path_sep = getEnv("GPATH_SEP");
    // picto
    m_QtAwesome = new QtAwesome(qApp);
}
//===============================================
GManager::~GManager() {
    
}
//===============================================
GManager* GManager::Instance(QObject* parent) {
    if(m_instance == 0) {
        m_instance = new GManager(parent);
    }
    return m_instance;
}
//===============================================
// data
//===============================================
sGManager* GManager::getData() {
    return mgr;
}
//===============================================
void GManager::initData() {
    // root
    int lCount = countUser(mgr->app->root_user);
    if(lCount == 0) {
        addUser(mgr->app->root_user, mgr->app->root_pass);
    }
}
//===============================================
// env
//===============================================
QString GManager::getEnv(QString key) {
    QString lValue = qgetenv(key.toStdString().c_str());
    return lValue;
}
//===============================================
// style
//===============================================
void GManager::loadStyle() {
    QFile lFile(mgr->app->style_path);
    lFile.open(QFile::ReadOnly);
    QString lStyleSheet = QLatin1String(lFile.readAll());
    qApp->setStyleSheet(lStyleSheet);
}
//===============================================
// property
//===============================================
void GManager::setProperty(QWidget* widget, QString key, QVariant data) {
    widget->setProperty(key.toStdString().c_str(), data);
    widget->style()->unpolish(widget); 
    widget->style()->polish(widget); 
}
//===============================================
// picto
//===============================================
QIcon GManager::loadPicto(int picto, QColor color) {
    m_QtAwesome->initFontAwesome();
    m_QtAwesome->setDefaultOption("color", color);
    m_QtAwesome->setDefaultOption("color-active", color);
    return  m_QtAwesome->icon(picto);
}
//===============================================
// font
//===============================================
void GManager::loadFont()  {
    QDirIterator lDirIterator(mgr->app->font_path, QDir::Files, QDirIterator::NoIteratorFlags);
    while (lDirIterator.hasNext()) {
        QString lFile = lDirIterator.next();
        QFontDatabase::addApplicationFont(lFile);
    }
}
//===============================================
// img
//===============================================
void GManager::loadImg()  {
    QDirIterator lDirIterator(mgr->app->img_path, QDir::Files, QDirIterator::NoIteratorFlags);
    while (lDirIterator.hasNext()) {
        QString lFile = lDirIterator.next();
        QString lKey = QFileInfo(lFile).baseName();
        mgr->app->img_map[lKey] = lFile;
    }
}
//===============================================
// page
//===============================================
void GManager::setPage(QString address)  {
    int lPageId = mgr->app->page_id.value(address, -1);
    if(lPageId == -1) {
        mgr->app->address->setText(mgr->app->address_url);
        return;
    }
    GWidget* lPage = qobject_cast<GWidget*>(mgr->app->page_map->widget(lPageId));
    mgr->app->address_new = address;
    if(lPage->loadPage() == 0) {
        mgr->app->address->setText(mgr->app->address_url);
        return;
    }
    mgr->app->page_map->setCurrentIndex(lPageId);
    mgr->app->address->setText(address);
    mgr->app->address_url = address;
    mgr->app->address_key->setContent(address);
    mgr->app->title->setText(mgr->app->title_map[address]);
}
//===============================================
// layout
//===============================================
void GManager::clearLayout(QLayout *layout) {
    if(layout) {
        while(layout->count() > 0) {
            QLayoutItem* lItem = layout->takeAt(0);
            QWidget* lWidget = lItem->widget();
            if(lWidget) delete lWidget;
            delete lItem;
        }
    }
}
//===============================================
// crypto
//===============================================
QString GManager::getCrypto(QString text) {
    QString lCrypto = QString(QCryptographicHash::hash(text.toUtf8(), QCryptographicHash::Md5).toHex());
    return lCrypto;
}
//===============================================
// message
//===============================================
int GManager::showQuestion(QString text) {
    GMessageBox lMsgBox(mgr->app->win);
    lMsgBox.setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
    lMsgBox.setText(text);
    lMsgBox.setIconPixmap(QPixmap(mgr->app->img_map["logo"]));
    QPushButton* lOk = lMsgBox.addButton("Ok", QMessageBox::YesRole);
    QPushButton* lCancel = lMsgBox.addButton("Annuler", QMessageBox::NoRole);
    lMsgBox.setDefaultButton(lCancel);
    lMsgBox.setEscapeButton(lCancel);
    lMsgBox.exec();
    QAbstractButton* lButton = lMsgBox.clickedButton();
    int lAnswer = QMessageBox::Cancel;
    if(lButton == lOk) lAnswer = QMessageBox::Ok;
    return lAnswer;
}
//===============================================
int GManager::showInfo(QString text) {
    GMessageBox lMsgBox(mgr->app->win);
    lMsgBox.setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
    lMsgBox.setText(text);
    lMsgBox.setIconPixmap(QPixmap(mgr->app->img_map["logo"]));
    QPushButton* lOk = lMsgBox.addButton("Ok", QMessageBox::YesRole);
    lMsgBox.setDefaultButton(lOk);
    lMsgBox.setEscapeButton(lOk);
    lMsgBox.exec();
    int lAnswer = QMessageBox::Ok;
    return lAnswer;
}
//===============================================
// login
//===============================================
int GManager::isLogin() {
    if(mgr->app->login_on == "on") return 1;
    QString lMessage = QString("Vous n'êtes pas connectés !");
    showInfo(lMessage);
    return 0;
}
//===============================================
// table
//===============================================
QVector<QString> GManager::getTables() {
    QVector<QString> lTables = GSQLite::Instance()->queryCol("\
    select name from sqlite_master \
    where type='table' \
    order by name \
    ");
    return lTables;
}
//===============================================
int GManager::countTable(QString table) {
    QString lQuery = QString("\
    select count(*) from %1 \
    ").arg(table);
    int lCount = GSQLite::Instance()->queryValue(lQuery).toInt();
    return lCount;
}
//===============================================
void GManager::deleteTable(QString table) {
    QString lQuery = QString("\
    drop table %1 \
    ").arg(table);
    GSQLite::Instance()->queryWrite(lQuery);
}
//===============================================
// config_data
//===============================================
void GManager::saveData(QString key, QString value) {
    int lCount = countData(key);
    if(lCount > 0) updateData(key, value);
    else insertData(key, value);
}
//===============================================
QString GManager::loadData(QString key) {
    QString lQuery = QString("\
    select config_value from config_data \
    where config_key = '%1' \
    ").arg(key);
    QString lData = GSQLite::Instance()->queryValue(lQuery);
    return lData;
}
//===============================================
int GManager::countData(QString key) {
    QString lQuery = QString("\
    select count(*) from config_data \
    where config_key = '%1' \
    ").arg(key);
    int lCount = GSQLite::Instance()->queryValue(lQuery).toInt();
    return lCount;
}
//===============================================
void GManager::updateData(QString key, QString value) {
    QString lQuery = QString("\
    update config_data \
    set config_value = '%2' \
    where config_key = '%1' \
    ").arg(key).arg(value);
    GSQLite::Instance()->queryWrite(lQuery);
}
//===============================================
void GManager::insertData(QString key, QString value) {
    QString lQuery = QString("\
    insert into config_data (config_key, config_value) \
    values ('%1', '%2') \
    ").arg(key).arg(value);
    GSQLite::Instance()->queryWrite(lQuery);
}
//===============================================
// users
//===============================================
int GManager::countUser(QString username) {
    QString lQuery = QString("\
    select count(*) from users \
    where username = '%1' \
    ").arg(username);
    int lCount = GSQLite::Instance()->queryValue(lQuery).toInt();
    return lCount;
}
//===============================================
int GManager::countUser(QString username, QString password) {
    QString lPassword = username + "|" + password;
    lPassword = getCrypto(lPassword);
    QString lQuery = QString("\
    select count(*) from users \
    where username = '%1' \
    and password = '%2' \
    ").arg(username).arg(lPassword);
    int lCount = GSQLite::Instance()->queryValue(lQuery).toInt();
    return lCount;
}
//===============================================
void GManager::addUser(QString username, QString password) {
    QString lPassword = username + "|" + password;
    lPassword = getCrypto(lPassword);
    QString lQuery = QString("\
    insert into users (username, password) \
    values ('%1', '%2') \
    ").arg(username).arg(lPassword);
    GSQLite::Instance()->queryWrite(lQuery);
}
//===============================================
QVector<QVector<QString>> GManager::getUser() {
    QString lQuery = QString("\
    select * from users \
    order by username \
    ");
    QVector<QVector<QString>> lData = GSQLite::Instance()->queryMap(lQuery);
    return lData;
}
//===============================================
void GManager::deleteUser(QString username) {
    QString lQuery = QString("\
    delete from users \
    where username = '%1' \
    ").arg(username);
    GSQLite::Instance()->queryWrite(lQuery);
}
//===============================================
