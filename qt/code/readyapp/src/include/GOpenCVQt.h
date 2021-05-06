//===============================================
#ifndef _GOpenCVQt_
#define _GOpenCVQt_
//===============================================
#include "GInclude.h"
#include "GWidget.h"
//===============================================
class GOpenCVQt : public GWidget {    
    Q_OBJECT

public:
    GOpenCVQt(QWidget* parent = 0);
    ~GOpenCVQt();
    
public slots:
    void slotItemClick();
    void slotItemClick(QAction* action);
    void showImage(QString filename);

private:
    QMap<QWidget*, QString> m_widgetId;
    QPushButton* m_setting;
    QMenu* m_settingMenu;
    QGraphicsScene* m_scene;
    QGraphicsView* m_view;
    QString m_state;
    QString m_filename;
    QGraphicsPixmapItem* m_currentImage;
};
//===============================================
#endif
//===============================================