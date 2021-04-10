//===============================================
#ifndef _GKeyValue_
#define _GKeyValue_
//===============================================
#include "GInclude.h"
#include "GWidget.h"
//===============================================
class GKeyValue : public GWidget {    
    Q_OBJECT

public:
    GKeyValue(QWidget* parent = 0);
    ~GKeyValue();
    
private:
    QMap<QWidget*, QString> m_widgetId;
};
//===============================================
#endif
//===============================================