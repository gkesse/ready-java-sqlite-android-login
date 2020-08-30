//===============================================
#ifndef _GFunction_
#define _GFunction_
//===============================================
#include "GInclude.h"
//===============================================
typedef struct _sGParams1 sGParams1;
typedef struct _sGParams2 sGParams2;
typedef struct _sGParams3 sGParams3;
typedef struct _sGParams4 sGParams4;
typedef struct _sGParams5 sGParams5;
typedef struct _sGPoly sGPoly;
//===============================================
struct _sGParams1 {
    double param1;
};
//===============================================
struct _sGParams2 {
    double param1;
    double param2;
};
//===============================================
struct _sGParams3 {
    double param1;
    double param2;
    double param3;
};
//===============================================
struct _sGParams4 {
    double param1;
    double param2;
    double param3;
    double param4;
};
//===============================================
struct _sGParams5 {
    double param1;
    double param2;
    double param3;
    double param4;
    double param5;
};
//===============================================
struct _sGPoly {
    double* coef;
    int size;
};
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
