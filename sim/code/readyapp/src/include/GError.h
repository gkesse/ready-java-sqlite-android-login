//===============================================
#ifndef _GError_
#define _GError_
//===============================================
#include "GInclude.h"
#include "GWidget.h"
//===============================================
class GError : public GWidget {    
    Q_OBJECT

public:
    GError(QWidget* parent = 0);
    ~GError();
};
//===============================================
#endif
//===============================================