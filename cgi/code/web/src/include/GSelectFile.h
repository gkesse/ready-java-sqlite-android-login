//===============================================
#ifndef _GSelectFile_
#define _GSelectFile_
//===============================================
#include "GWidget.h"
//===============================================
class GSelectFile : public GWidget {
public:
    GSelectFile();
    ~GSelectFile();
    // method
    void print();
    void setCookies();
    void request();
    
private:
    QStringList m_files;
    QString m_path;
    int m_total;
    int m_page;
    int m_colMax;
};
//===============================================
#endif
//===============================================
