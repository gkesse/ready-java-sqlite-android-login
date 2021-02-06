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
    mgr->app->app_name = "ReadyApp";
    mgr->app->logo_path = "/data/img/logo.png";
    mgr->app->style_path = "/data/css/style.css";
    mgr->app->icon_path = "/libs/font_awesome/css/font-awesome.min.css";
    mgr->app->font_path = "/libs/google_fonts";
    mgr->app->page_last = "home";
    mgr->app->user_name = "unknow";
    // style
    mgr->style = new sGStyle;
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
    // req_map
    lApp->req_string = getPost();
    lApp->req_map = splitMap(lApp->req_string, "&", "=");
    // req
    lApp->req = lApp->req_map.value("req", "");
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
        "INPUT_LENGTH" << "CONTENT_LENGTH";
        
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
        QString lKey = lDataCol[0];
        QString lValue = lDataCol[1];
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
QString GManager::getPost() {
    char lBuffer[1024] = {0}; 
    QString lEnv = getEnv("CONTENT_LENGTH"); 
    if(lEnv == "") {return "";}
    int lLength = lEnv.toInt();
    int lSize = sizeof(lBuffer) - 1;
    lLength = qMin(lLength, lSize); 
    fread(lBuffer, lLength, 1, stdin); 
    return lBuffer;
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
