//===============================================
#include "GJson.h"
#include "GManager.h"
//===============================================
GJson* GJson::m_instance = 0;
//===============================================
GJson::GJson() {
    
}
//===============================================
GJson::~GJson() {
    
}
//===============================================
GJson* GJson::Instance() {
    if(m_instance == 0) {
        m_instance = new GJson;
    }
    return m_instance;
}
//===============================================
void GJson::test() {
    qDebug() << "dataCount :\n" << dataCount("admin", _EOA_) << "\n";
    qDebug() << "dataCount :\n" << dataCount("admin", "0", _EOA_) << "\n";
    qDebug() << "dataCol :\n" << dataCol("admin", "name", _EOA_) << "\n";
    qDebug() << "dataRow :\n" << dataRow("admin", "0", _EOA_) << "\n";
}
//===============================================
int GJson::dataCount(const char* key, ...) {
    sGManager* lMgr = GManager::Instance()->dataGet();
    sGJson* lJson = lMgr->json;
    QFile lJsonF(lJson->file);
    if(!lJsonF.open(QIODevice::ReadOnly)) {
        printf("[erreur] erreur ouverture fichier");
        return -1;
    }
    QByteArray lJsonT = lJsonF.readAll();
    QJsonDocument lJsonD(QJsonDocument::fromJson(lJsonT));
    QJsonObject lJsonO = lJsonD.object();
    QJsonValue lJsonV = lJsonO;
    int lDataC = 0;
    
    va_list lArgs;
    va_start(lArgs, key);
    QString lKey = key;
    while(1) {
        if(lKey == _EOA_) break;
        if(lJsonV.isObject()) {
            lJsonV = lJsonV[lKey];
        }
        else if(lJsonV.isArray()) {
            lJsonV = lJsonV[lKey.toInt()];
        }
        else {break;}
        lKey = va_arg(lArgs, char*);
    }
    va_end(lArgs);
    if(lJsonV.isObject()) {
        lDataC = lJsonV.toObject().size();
    }
    else if(lJsonV.isArray()) {
        lDataC = lJsonV.toArray().size();
    }
    return lDataC;
}
//===============================================
QStringList GJson::dataCol(const char* key, ...) {
    sGManager* lMgr = GManager::Instance()->dataGet();
    sGJson* lJson = lMgr->json;
    QFile lJsonF(lJson->file);
    if(!lJsonF.open(QIODevice::ReadOnly)) {
        printf("[erreur] erreur ouverture fichier");
        return QStringList();
    }
    QByteArray lJsonT = lJsonF.readAll();
    QJsonDocument lJsonD(QJsonDocument::fromJson(lJsonT));
    QJsonObject lJsonO = lJsonD.object();
    QJsonValue lJsonV = lJsonO;
    QJsonArray lJsonA;
    QStringList lDataL;
    int lDataC;
    
    va_list lArgs;
    va_start(lArgs, key);
    QString lKey = key;
    while(1) {
        if(lKey == _EOA_) break;
        if(lJsonV.isObject()) {
            lJsonV = lJsonV[lKey];
        }
        else if(lJsonV.isArray()) {
            bool lNumOk;
            lKey.toInt(&lNumOk);
            if(lNumOk == 1) {
                lJsonV = lJsonV[lKey.toInt()];
            }
            else {
                lJsonA = lJsonV.toArray();
                lDataC = lJsonA.size();
                for(int i = 0; i < lDataC; i++) {
                    QJsonValue lJsonV2 = lJsonA[i];
                    if(lJsonV2.isObject()) {
                        lJsonO = lJsonV2.toObject();
                        lDataL << lJsonO[lKey].toString();
                    }
                    else {
                        lDataL << lJsonV2.toString();
                    }
                }
            }
        }
        else {break;}
        lKey = va_arg(lArgs, char*);
    }
    va_end(lArgs);
    return lDataL;
}
//===============================================
QStringList GJson::dataRow(const char* key, ...) {
    sGManager* lMgr = GManager::Instance()->dataGet();
    sGJson* lJson = lMgr->json;
    QFile lJsonF(lJson->file);
    if(!lJsonF.open(QIODevice::ReadOnly)) {
        printf("[erreur] erreur ouverture fichier");
        return QStringList();
    }
    QByteArray lJsonT = lJsonF.readAll();
    QJsonDocument lJsonD(QJsonDocument::fromJson(lJsonT));
    QJsonObject lJsonO = lJsonD.object();
    QJsonValue lJsonV = lJsonO;
    QStringList lDataL;
    
    va_list lArgs;
    va_start(lArgs, key);
    QString lKey = key;
    while(1) {
        if(lKey == _EOA_) break;
        if(lJsonV.isObject()) {
            lJsonV = lJsonV[lKey];
        }
        else if(lJsonV.isArray()) {
            lJsonV = lJsonV[lKey.toInt()];
        }
        else {break;}
        lKey = va_arg(lArgs, char*);
    }
    va_end(lArgs);
    if(lJsonV.isObject()) {
        lJsonO = lJsonV.toObject();
        foreach(const QString& lDataK, lJsonO.keys()) {
            lJsonV = lJsonO.value(key);
            lDataL << lJsonV.toString();
        }    
    }
    return lDataL;
}
//===============================================
