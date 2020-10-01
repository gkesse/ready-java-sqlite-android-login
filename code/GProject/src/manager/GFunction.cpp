//===============================================
#include "GFunction.h"
//===============================================
typedef struct _sGPoly sGPoly;
//===============================================
struct _sGPoly {
    double* coef;
    int size;
};
//===============================================
GFunction* GFunction::m_instance = 0;
//===============================================
GFunction::GFunction() {
    
}
//===============================================
GFunction::~GFunction() {
    
}
//===============================================
GFunction* GFunction::Instance() {
    if(m_instance == 0) {
        m_instance = new GFunction;
    }
    return m_instance;
}
//===============================================
double GFunction::onPoly(double x, void* params) {
    sGPoly* lParams = (sGPoly*)params;
    double* lCoef = lParams->coef;
    int lSize = lParams->size;
    double lY = gsl_poly_eval(lCoef, lSize, x);
    return lY;
}
//===============================================
