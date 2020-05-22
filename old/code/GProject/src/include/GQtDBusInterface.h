//================================================
#ifndef _GQtDBusInterface_
#define _GQtDBusInterface_
//================================================
#include "GInclude.h"
//================================================
#if defined(_GUSE_QT_ON_)
//================================================
class GQtDBusInterface : public QDBusAbstractInterface {
	Q_OBJECT

public:
	GQtDBusInterface(const QString &service, const QString &path, const char* interface, const QDBusConnection &connection, QObject *parent = 0);
	~GQtDBusInterface();

private:
	const char* __CLASSNAME__;
};
//================================================
namespace org {
namespace readydev {
typedef ::GQtDBusInterface App;
}}
//================================================
#endif
//================================================
#endif
//================================================
