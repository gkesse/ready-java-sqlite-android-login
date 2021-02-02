//===============================================
#ifndef _GFileDialog_
#define _GFileDialog_
//===============================================
#include "GInclude.h"
//===============================================
class GFileDialog : public QFileDialog {
    Q_OBJECT
    
public:
    GFileDialog(QWidget *parent, Qt::WindowFlags flags);
    ~GFileDialog();

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private:
    QPoint m_pressPos;
    bool m_pressFlag;
};
//===============================================
#endif
//===============================================