//===============================================
#include "GManager.h"
//===============================================
GManager* GManager::m_instance = 0;
//===============================================
GManager::GManager() {
    // manager
    mgr = new sGManager;
    // app
    mgr->app = new sGApp;
    mgr->app->app_name = "ReadyCGI";
    mgr->app->logo_path = "/data/img/logo.png";
    mgr->app->style_path = "/data/css/style.css";
    mgr->app->icon_path = "/libs/font_awesome/css/font-awesome.min.css";
    mgr->app->font_path = "/libs/google_fonts";
    mgr->app->page_last = "home";
    mgr->app->user_name = "unknown";
    mgr->app->log_path = "./data/log/log.txt";
    // style
    mgr->style = new sGStyle;
    // cgi
    mgr->app->cgi = new rude::CGI();
}
//===============================================
GManager::~GManager() {
    
}
//===============================================
GManager* GManager::Instance() {
    if(m_instance == 0) {
        m_instance = new GManager;
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
// env
//===============================================
QString GManager::getEnv(QString key) {
    char* lValue = getenv(key.toStdString().c_str());
    if(lValue == 0) return "";
    return lValue;
}
//===============================================
void GManager::loadEnv() {
    sGApp* lApp = GManager::Instance()->getData()->app;
    // query_map
    lApp->query_string = getEnv("QUERY_STRING");
    lApp->query_map = splitMap(lApp->query_string, "&", "=");
    // page_id
    lApp->page_id = lApp->query_map.value("page_id", "");
    lApp->page_id = removeLast(lApp->page_id, '/');
    // cookie_map
    lApp->cookie_string = getEnv("HTTP_COOKIE");
    lApp->cookie_map = splitMap(lApp->cookie_string, ";", "=");
    // page_last
    lApp->page_last = lApp->cookie_map.value("page_last", "");
    // image
    lApp->image_file = lApp->cookie_map.value("image_file", "");
    lApp->image_path = lApp->query_map.value("image_path", "");
    lApp->image_run = lApp->query_map.value("image_run", "");
    // opencv
    lApp->opencv_state = lApp->cookie_map.value("opencv_state", "");
    // req
    lApp->req = getPost("req");
    // action
    lApp->action = getPost("action");
}
//===============================================
void GManager::showEnv() {
    const QStringList lEnvs = QStringList() <<
        "COMSPEC" << "DOCUMENT_ROOT" << "GATEWAY_INTERFACE" <<   
        "HTTP_ACCEPT" << "HTTP_ACCEPT_ENCODING" <<             
        "HTTP_ACCEPT_LANGUAGE" << "HTTP_CONNECTION" <<         
        "HTTP_HOST" << "HTTP_USER_AGENT" << "PATH" <<            
        "QUERY_STRING" << "REMOTE_ADDR" << "REMOTE_PORT" <<      
        "REQUEST_METHOD" << "REQUEST_URI" << "SCRIPT_FILENAME" <<
        "SCRIPT_NAME" << "SERVER_ADDR" << "SERVER_ADMIN" <<      
        "SERVER_NAME" << "SERVER_PORT" << "SERVER_PROTOCOL" <<     
        "SERVER_SIGNATURE" << "SERVER_SOFTWARE" << "HTTP_COOKIE" <<
        "INPUT_LENGTH" << "CONTENT_LENGTH" << "CONTENT_TYPE";
        
    printf("<div class='table_id'>\n");
    printf("<table>\n");
    printf("<tbody>\n");
    for( int i = 0; i < lEnvs.size(); i++ ) {
        QString lEnv = lEnvs[i];
        printf("<tr>\n");
        printf("<td>%s</td>\n", lEnv.toStdString().c_str());
        QString lValue = getEnv(lEnv);
        if(lValue == "") {lValue = "La variable d'environnement n'existe pas";}
        printf("<td>%s</td>\n", lValue.toStdString().c_str());
        printf("</tr>\n");
    }
    printf("</tbody>\n");
    printf("</table>\n");
    printf("</div >\n");
}
//===============================================
// string
//===============================================
QMap<QString, QString> GManager::splitMap(QString str, QString sepRow, QString sepCol) {
    QMap<QString, QString> lDataMap;
    if(str == "") {return lDataMap;}
    QStringList lDataRow = str.split(sepRow);
    for(int i = 0; i < lDataRow.size(); i++) {
        QString lData = lDataRow[i];
        QStringList lDataCol = lData.split(sepCol);
        QString lKey = lDataCol[0].simplified();
        QString lValue = lDataCol[1].simplified();
        lDataMap[lKey] = lValue;
    }
    return lDataMap;
}
//===============================================
QString GManager::removeLast(QString str, char remove) {
    QString lData = str;
    if(lData.back() == remove) lData.chop(1);
    return lData;
}
//===============================================
// post
//===============================================
QString GManager::getPost(QString key) {
    sGApp* lApp = GManager::Instance()->getData()->app;
    QString lData = "";
    const char* lKey = key.toStdString().c_str();
    if(lApp->cgi->exists(lKey)) {lData = lApp->cgi->value(lKey);}
    return lData;
}
//===============================================
bool GManager::isPost() {
    QString lContentLength = getEnv("CONTENT_LENGTH");
    if(lContentLength == "") return 0;
    return 1;
}
//===============================================
// redirect
//===============================================
void GManager::redirect(QString newUrl) {
    printf("Content-type: text/html\n\n");
    printf("<html>\n");
    printf("<head>\n");
    printf("<title>Redirection</title>\n");
    printf("<meta http-equiv='refresh' content='0; URL=%s'>\n", newUrl.toStdString().c_str());
    printf("</head>\n");
    printf("<body>\n");
    printf("</body>\n");
    printf("</html>\n");
    exit(0);
}
//===============================================
void GManager::redirectPost(QString newUrl) {
    printf("HTTP/1.1 303n\n");
    printf("Location: %s\n", newUrl.toStdString().c_str());
    exit(0);
}
//===============================================
// page
//===============================================
void GManager::selectPage() {
    sGApp* lApp = GManager::Instance()->getData()->app;
    if(lApp->page_id == "") {GManager::Instance()->redirect("/home");}
    if(lApp->page_map->getPage(lApp->page_id) == "") {GManager::Instance()->redirect("/"+lApp->page_last);}
    setCookie("page_last", lApp->page_id);
}
//===============================================
// cookie
//===============================================
void GManager::setCookie(QString key, QString value) {
    printf("Set-Cookie:%s = %s;\n", key.toStdString().c_str(), value.toStdString().c_str());
}
//===============================================
QString GManager::getCookie(QString key) {
    sGApp* lApp = GManager::Instance()->getData()->app;
    return lApp->cookie_map.value(key, "");
}
//===============================================
// file
//===============================================
QString GManager::getUploadFile(QString key, QString dir) {
    sGApp* lApp = GManager::Instance()->getData()->app;
    const char* lKey = key.toStdString().c_str();
    if(!(lApp->cgi->exists(lKey) && lApp->cgi->isFile(lKey))) {return "";}
    QString lPath = getFilePath(dir);
    QString lFilename = lApp->cgi->filename(lKey);
    QString lFilePath = lPath + "/" + lFilename;
    return lFilePath;
}
//===============================================
void GManager::uploadFile(QString key, QString dir) {
    sGApp* lApp = GManager::Instance()->getData()->app;
    const char* lKey = key.toStdString().c_str();
    if(!(lApp->cgi->exists(lKey) && lApp->cgi->isFile(lKey))) {return;}
    QString lFilePath = getUploadFile(key, dir);
    FILE* lFile = fopen(lFilePath.toLatin1().constData(), "wb");
        
    if(lFile) {
        const char* lData = lApp->cgi->value(lKey);
        int lFileSize = lApp->cgi->length(lKey);
        fwrite(lData, 1, lFileSize, lFile);
        fclose(lFile);
    }
}
//===============================================
QString GManager::getFilePath(QString dir) {
    QString lPath = "./data/users";
    QString lUsername = getUsername();
    QString lFilePath = lPath + "/" + lUsername + "/" + dir;
    createDir(lFilePath);
    return lFilePath;
}
//===============================================
QString GManager::getFilePath(QString dir, QString filename) {
    QString lPath = getFilePath(dir);
    QString lFilename = lPath + "/" + filename;
    return lFilename;
}
//===============================================
QStringList GManager::getFileList(QString dir) {
    QString lPath = getFilePath(dir);
    QStringList lFilters = getFileFilters(dir);
    QDir lDir(lPath);
    QStringList lFiles = lDir.entryList(lFilters, QDir::Files);
    return lFiles;
}
//===============================================
QStringList GManager::getFileFilters(QString dir) {
    QStringList lFilters;
    if(dir == "img") {
        lFilters << "*.png" << "*.jpg" << "*.bmp";
    }
    return lFilters;
}
//===============================================
// dir
//===============================================
void GManager::createDir(QString path) {
    QDir lDir(path);
    if(!lDir.exists()) {
        lDir.mkpath(".");
    }
}
//===============================================
// user
//===============================================
QString GManager::getUsername() {
    sGApp* lApp = GManager::Instance()->getData()->app;
    return lApp->user_name;
}
//===============================================
// log
//===============================================
void GManager::log(const char* format, ...) {
    sGApp* lApp = GManager::Instance()->getData()->app;
    createDir(QFileInfo(lApp->log_path).absolutePath());
    FILE* lFile = fopen(lApp->log_path.toStdString().c_str(), "a");
    if(lFile == 0) {return;}
    char lDate[256];
    char lData[256];
    Date(lDate);
    va_list lArgs;
    va_start(lArgs, format);
    vsprintf(lData, format, lArgs);
    va_end(lArgs);
    fprintf(lFile, "%s | %s\n", lDate, lData);
    fclose(lFile);
}
//===============================================
// date
//===============================================
void GManager::Date(char* buffer) {
    time_t lTime;
    time(&lTime);
    struct tm* lTimeInfo = localtime(&lTime);
    int lDay = lTimeInfo->tm_mday;
    int lMonth = lTimeInfo->tm_mon + 1;
    int lYear = lTimeInfo->tm_year + 1900;
    int lHour = lTimeInfo->tm_hour;
    int lMin = lTimeInfo->tm_min;
    int lSec = lTimeInfo->tm_sec;
    sprintf(buffer, "%02d/%02d/%04d %02d:%02d:%02d", lDay, lMonth, lYear, lHour, lMin, lSec);
}
//===============================================