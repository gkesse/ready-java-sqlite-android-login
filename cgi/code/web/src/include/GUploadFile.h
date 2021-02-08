//===============================================
#ifndef _GUploadFile_
#define _GUploadFile_
//===============================================
#include "GWidget.h"
//===============================================
class GUploadFile : public GWidget {
public:
    GUploadFile();
    ~GUploadFile();
    // method
    void print();
    void setCookies();
    void request();
};
//===============================================
#endif
//===============================================
