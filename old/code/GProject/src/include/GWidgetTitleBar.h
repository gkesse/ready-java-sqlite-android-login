//================================================
#ifndef _GWidgetTitleBar_
#define _GWidgetTitleBar_
//===============================================
#include "GWidget.h"
//===============================================
#if defined(_GUSE_QT_ON_)
//================================================
class GWidgetTitleBar : public GWidget {
public:
	GWidgetTitleBar(QWidget* parent = 0);
	~GWidgetTitleBar();

protected:
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mouseDoubleClickEvent(QMouseEvent *event);

public slots:
	void slotWindowTitleChange(QString text);
	void slotWindowIconChange(QIcon icon);
	void slotWindowMaximize(int oldState, int newState);
	void slotWindowFullScreen(int oldState, int newState);

private:
	const char* __CLASSNAME__;
	QLabel* m_icon;
	QLabel* m_title;
	QToolButton* m_minimize;
	QToolButton* m_maximize;
	QToolButton* m_close;
};
//================================================
#endif
//================================================
#endif
//================================================