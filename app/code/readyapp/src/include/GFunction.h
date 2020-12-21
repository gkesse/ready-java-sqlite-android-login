//===============================================
#ifndef _GFunction_
#define _GFunction_
//===============================================
#include "GInclude.h"
//===============================================
class GFunction {
private:
    GFunction();
    
public:
    ~GFunction();
    static GFunction* Instance();
    static double onConstant(double x, void* params);
    static double onLine(double x, void* params);
    static double onPoly(double x, void* params);
    
public:
    static GFunction* m_instance;
};
//===============================================
#endif
//===============================================
