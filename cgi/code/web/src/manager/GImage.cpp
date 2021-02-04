//===============================================
#include "GImage.h"
#include "GManager.h"
//===============================================
GImage* GImage::m_instance = 0;
//===============================================
GImage::GImage() {

}
//===============================================
GImage::~GImage() {
    
}
//===============================================
GImage* GImage::Instance() {
    if(m_instance == 0) {
        m_instance = new GImage;
    }
    return m_instance;
}
//===============================================
void GImage::run(int argc, char** argv) {
    printf("content-type: image/bmp\n\n");
    QString lFilename = "./data/img/logo.bmp";
    FILE* lFile = fopen(lFilename.toStdString().c_str(), "rb");
    if(lFile != 0) {
        char lData;
        while(feof(lFile) == 0) {
            fread(&lData, 1, 1, lFile);
            printf("%c", lData);
        }
        fclose(lFile);
    }
}
//===============================================
