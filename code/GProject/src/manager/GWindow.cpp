//===============================================
#include "GWindow.h"
#include "GWindowMath.h"
#include "GDebug.h"
//===============================================
GWindow::GWindow(QWidget* parent) {
	__CLASSNAME__ = __FUNCTION__;
}
//===============================================
GWindow::~GWindow() {

}
//===============================================
GWindow* GWindow::Create(string key) {
    GDebug::Instance()->process("write", __CLASSNAME__, "::", __FUNCTION__, "()");
	if(key == "math") return new GWindowMath;
	return new GWindowMath;
}
//===============================================
