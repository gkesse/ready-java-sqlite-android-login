//===============================================
#ifndef _GHtmlEdit_
#define _GHtmlEdit_
//===============================================
#include "GInclude.h"
#include "GWidget.h"
//===============================================
class GHtmlEdit : public GWidget {    
    Q_OBJECT

public:
    GHtmlEdit(QWidget* parent = 0);
    ~GHtmlEdit();
};
//===============================================
#endif
//===============================================