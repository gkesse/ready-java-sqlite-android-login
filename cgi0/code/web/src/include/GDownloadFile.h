//===============================================
#ifndef _GDownloadFile_
#define _GDownloadFile_
//===============================================
#include "GWidget.h"
//===============================================
class GDownloadFile : public GWidget {
public:
    GDownloadFile();
    ~GDownloadFile();
    // method
    void print();
    
private:
    QString m_tmpImgFile;
};
//===============================================
#endif
//===============================================
