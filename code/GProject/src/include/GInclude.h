//===============================================
#ifndef _GInclude_
#define _GInclude_
//===============================================
#if defined(__unix)
//===============================================
#define _D_GNU_SOURCE
#define _USE_MATH_DEFINES
//===============================================
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdarg>
#include <ctime>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
//===============================================
#define _GUSE_MYSQL_ON_
#define _GUSE_OPENGL_ON_
//===============================================
#if defined(_GUSE_MYSQL_ON_)
#include <mysql++.h>
#endif
//===============================================
#if defined(_GUSE_OPENGL_ON_)
#include <GLFW/glfw3.h>
#endif
//===============================================
#endif
//===============================================
#if defined(__WIN32)
//===============================================
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdarg>
#include <ctime>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
//===============================================
#endif
//===============================================
#include "GStruct.h"
//===============================================
#endif
//===============================================
