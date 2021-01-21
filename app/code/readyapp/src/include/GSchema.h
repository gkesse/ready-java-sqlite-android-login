//===============================================
#ifndef _GSchema_
#define _GSchema_
//===============================================
#include "GInclude.h"
#include "GWidget.h"
//===============================================
class GSchema : public GWidget {    
    Q_OBJECT

public:
    GSchema(QWidget* parent = 0);
    ~GSchema();

public:
    int loadPage();
    
private:
    QTextEdit* m_textEdit;
};
//===============================================
#endif
//===============================================