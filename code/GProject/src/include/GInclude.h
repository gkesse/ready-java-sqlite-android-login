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
#if defined(_GUSE_EXPRTK_ON_)
#include <exprtk.hpp>
#endif
//===============================================
#if defined(_GUSE_MUPARSER_ON_)
#include <muParser.h>
#endif
//===============================================
using namespace std;
//===============================================
#endif
//===============================================
#if defined(__WIN32)
//===============================================
#define _GPLATEFORME_ "WINDOWS"
//===============================================
#define _GUSE_EXPRTK_ON_0
#define _GUSE_MUPARSER_ON_0
#define _GUSE_GSL_ON_0
#define _GUSE_OPENCV_ON_0
#define _GUSE_OPENGL_ON_0
#define _GUSE_GSOAP_ON_0
#define _GUSE_CMOCKA_ON_
//===============================================
#define _GUSE_QT_ON_0
#define _GUSE_QTAWESOME_ON_0
#define _GUSE_QCUSTOMPLOT_ON_0
//===============================================
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdarg>
#include <ctime>
//===============================================
#if defined(_GUSE_EXPRTK_ON_)
#include <exprtk.hpp>
#endif
//===============================================
#if defined(_GUSE_MUPARSER_ON_)
#include <muParser.h>
#endif
//===============================================
#if defined(_GUSE_GSL_ON_)
#include <gsl/gsl_sf.h>
#endif
//===============================================
#if defined(_GUSE_OPENCV_ON_)
#include <opencv2/opencv.hpp>
#endif
//===============================================
#if defined(_GUSE_OPENGL_ON_)
#include <GLFW/glfw3.h>
#endif
//===============================================
#if defined(_GUSE_GSOAP_ON_)
//#include <gs>
#endif
//===============================================
#if defined(_GUSE_CMOCKA_ON_)
#include <setjmp.h>
#include <cmocka.h>
#endif
//===============================================
#if defined(_GUSE_QT_ON_)
#include <QtWidgets>
#include <QScriptEngine>
#include <QDebug>
#endif
//===============================================
#if defined(_GUSE_QTAWESOME_ON_)
#include <QtAwesome.h>
#endif
//===============================================
#if defined(_GUSE_QCUSTOMPLOT_ON_)
#include <qcustomplot.h>
#endif
//===============================================
using namespace std;
//===============================================
#endif
//===============================================
#include "GStruct.h"
//===============================================
#endif
//===============================================
