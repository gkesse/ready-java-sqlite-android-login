//===============================================
#ifndef _GStackWidget_
#define _GStackWidget_
//===============================================
#include "GInclude.h"
//===============================================
class GStackWidget : public QStackedWidget {    
    Q_OBJECT

public:
    GStackWidget(QWidget* parent = 0);
    ~GStackWidget();

protected:
    QSize sizeHint() const;
    QSize minimumSizeHint() const;
};
//===============================================
#endif
//===============================================