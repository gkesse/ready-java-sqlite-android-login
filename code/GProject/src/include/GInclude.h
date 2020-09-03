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
//===============================================
#include <sqlite3.h>
#include <opencv2/opencv.hpp>
//===============================================
#elif defined(__WIN32)
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
//===============================================
#endif
//===============================================
#define _EOA_ "_END_OF_ARGUMENT_"
//===============================================
#endif
//===============================================
