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
#include <exprtk.hpp>
#include <muParser.h>
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
#define _GUSE_EXPRTK_OFF_
#define _GUSE_MUPARSER_ON_
//===============================================
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstdarg>
#include <ctime>
//===============================================
#include <QtWidgets>
#include <QScriptEngine>
#include <QDebug>
#include <QtAwesome.h>
//===============================================
using namespace std;
//===============================================
#endif
//===============================================
#endif
//===============================================
