//===============================================
#include "GQtDBusInterface.h"
#include "GDir.h"
#include "GDebug.h"
//================================================
#if defined(_GUSE_QT_ON_)
//===============================================
GQtDBusInterface::GQtDBusInterface(const QString &service, const QString &path, const char* interface, const QDBusConnection &connection, QObject *parent) :
QDBusAbstractInterface(service, path, interface, connection, parent) {
	__CLASSNAME__ = __FUNCTION__;
}
//===============================================
GQtDBusInterface::~GQtDBusInterface() {

}
//===============================================
#endif
//===============================================
