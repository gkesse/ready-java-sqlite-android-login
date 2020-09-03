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
    qDebug() << "dataCount :\n" << dataCount("admin") << "\n";
    qDebug() << "dataCount :\n" << dataCount("admin/0") << "\n";
    qDebug() << "dataCol :\n" << dataCol("admin/name") << "\n";
    qDebug() << "dataRow :\n" << dataRow("admin/0") << "\n";
}
//===============================================
QJsonValue GJson::open() {
    sGManager* lMgr = GManager::Instance()->dataGet();
    sGJson* lJson = lMgr->json;
    QFile lJsonF(lJson->file.c_str());
    QJsonValue lJsonV;

    if(!lJsonF.open(QIODevice::ReadOnly)) {
        printf("[erreur] erreur ouverture fichier");
        return lJsonV;
    }
    
    QByteArray lJsonT = lJsonF.readAll();
    QJsonDocument lJsonD(QJsonDocument::fromJson(lJsonT));
    if(lJsonD.isObject()) {lJsonV = lJsonD.object();}
    else {lJsonV = lJsonD.array();}
    return lJsonV;
}
//===============================================
int GJson::dataCount(std::string key) {
    QJsonValue lJsonV = open();
    int lDataC = 0;
    
    QStringList lKeyL = QString(key.c_str()).split("/");
    
    for(int i = 0; i < lKeyL.size(); i++) {
        QString lKey = lKeyL[i];
        if(lJsonV.isObject()) {
            lJsonV = lJsonV[lKey];
        }
        else if(lJsonV.isArray()) {
            lJsonV = lJsonV[lKey.toInt()];
        }
        else {break;}
    }
    
    if(lJsonV.isObject()) {
        lDataC = lJsonV.toObject().size();
    }
    else if(lJsonV.isArray()) {
        lDataC = lJsonV.toArray().size();
    }
    return lDataC;
}
//===============================================
QStringList GJson::dataCol(std::string key) {
    QJsonValue lJsonV = open();
    QJsonObject lJsonO;
    QJsonArray lJsonA;
    QStringList lDataL;
    int lDataC;
    
    QStringList lKeyL = QString(key.c_str()).split("/");
    
    for(int i = 0; i < lKeyL.size(); i++) {
        QString lKey = lKeyL[i];
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
                for(int j = 0; j < lDataC; j++) {
                    QJsonValue lJsonV2 = lJsonA[j];
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
    }

    return lDataL;
}
//===============================================
QStringList GJson::dataRow(std::string key) {
    QJsonValue lJsonV = open();
    QJsonObject lJsonO;
    QStringList lDataL;
    
    QStringList lKeyL = QString(key.c_str()).split("/");
    
    for(int i = 0; i < lKeyL.size(); i++) {
        QString lKey = lKeyL[i];
        if(lJsonV.isObject()) {
            lJsonV = lJsonV[lKey];
        }
        else if(lJsonV.isArray()) {
            lJsonV = lJsonV[lKey.toInt()];
        }
        else {break;}
    }

    if(lJsonV.isObject()) {
        lJsonO = lJsonV.toObject();
        QStringList lKeys = lJsonO.keys();
        for(int i = 0; i < lKeys.size(); i++) {
            QString lDataK = lKeys[i];
            lJsonV = lJsonO.value(lDataK);
            lDataL << lJsonV.toString();
        }    
    }
    return lDataL;
}
//===============================================
