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
#define _GUSE_EXPRTK_OFF_
#define _GUSE_MUPARSER_OFF_
#define _GUSE_GSL_ON_
#define _GUSE_OPENCV_ON_
#define _GUSE_OPENGL_ON_
#define _GUSE_QT_ON_
#define _GUSE_QTAWESOME_ON_
#define _GUSE_QCUSTOMPLOT_ON_
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
