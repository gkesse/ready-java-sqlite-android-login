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
#elif defined(__GNUC__) && defined(__MINGW32__)
//===============================================
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <pthread.h>
#include <dirent.h>
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
#include <windows.h>
//===============================================
#endif
//===============================================
#endif
//===============================================
