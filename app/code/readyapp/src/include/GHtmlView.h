//===============================================
#ifndef _GHtmlView_
#define _GHtmlView_
//===============================================
#include "GInclude.h"
#include "GWidget.h"
//===============================================
class GHtmlView : public GWidget {    
    Q_OBJECT

public:
    GHtmlView(QWidget* parent = 0);
    ~GHtmlView();
};
//===============================================
#endif
//===============================================