//===============================================
#ifndef _GInclude_
#define _GInclude_
//===============================================
#if defined(__unix)
//===============================================
#define _GPLATEFORME_ "UNIX"
//===============================================
#define _GUSE_QT_OFF_
//===============================================
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdarg>
#include <ctime>
//===============================================
using namespace std;
//===============================================
#endif
//===============================================
#if defined(__WIN32)
//===============================================
#define _GPLATEFORME_ "WINDOWS"
//===============================================
#define _GUSE_QT_OFF_
//===============================================
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstdarg>
#include <ctime>
//===============================================
using namespace std;
//===============================================
#include <QtWidgets>
#include <QScriptEngine>
#include <QDebug>
#include <QtAwesome.h>
//===============================================
#endif
//===============================================
#endif
//===============================================
