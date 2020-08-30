//===============================================
#include "GFunction.h"
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
double GFunction::onConstant(double x, void* params) {
    sGParams1* lParams = (sGParams1*)params;
    double lY0 = lParams->param1;
    return lY0;
}
//===============================================
double GFunction::onLine(double x, void* params) {
    sGParams2* lParams = (sGParams2*)params;
    double lA = lParams->param1;
    double lB = lParams->param2;
    double lY = lA*x + lB;
    return lY;
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
