//================================================
#ifndef _GQt_
#define _GQt_
//================================================
#include "GInclude.h"
//================================================
#if defined(_GUSE_QT_ON_)
//================================================
class GQt : public QObject {
	Q_OBJECT

private:
    GQt();

public:
    ~GQt();
    static GQt* Instance();
    void test(int argc, char** argv);

private:
    void defaulTest(int argc, char** argv);
    void dbus(int argc, char** argv);

public slots:
	void slotDBus(QString nickname, QString text);

private:
    const char* __CLASSNAME__;
    static GQt* m_instance;
};
//================================================
#endif
//================================================
#endif
//================================================
