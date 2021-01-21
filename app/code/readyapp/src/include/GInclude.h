//===============================================
#ifndef _GInclude_
#define _GInclude_
//===============================================
#if defined(__unix)
//===============================================
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <unistd.h>
#include <signal.h>
//===============================================
#include <sqlite3.h>
#include <opencv2/opencv.hpp>
#include <gsl/gsl_spmatrix.h>
#include <gsl/gsl_poly.h>
//===============================================
#elif defined(__GNUC__) && defined(__MINGW32__)
//===============================================
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <pthread.h>
//===============================================
#include <sqlite3.h>
#include <opencv2/opencv.hpp>
#include <gsl/gsl_spmatrix.h>
#include <gsl/gsl_poly.h>
#include <QtWidgets>
#include <QtSql>
#include <QPrinter>
#include <QtAwesome.h>
//===============================================
#elif defined(__WIN32)
//===============================================
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <windows.h>
//===============================================
#include <sqlite3.h>
#include <opencv2/opencv.hpp>
#include <gsl/gsl_spmatrix.h>
#include <gsl/gsl_poly.h>
//===============================================
#endif
//===============================================
#endif
//===============================================
