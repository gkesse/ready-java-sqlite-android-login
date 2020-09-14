//===============================================
#ifndef _GGslTest_
#define _GGslTest_
//===============================================
#include "GInclude.h"
//===============================================
class GGslTest {
private:
    GGslTest();
    
public:
    ~GGslTest();
    static GGslTest* Instance();
    void matrix();
    void polynomial();
    
private:
    void matrixShow(gsl_spmatrix* mat);
    void matrixSave(const char* filename, gsl_spmatrix* mat);
    gsl_spmatrix* matrixLoad(const char* filename, int rows, int cols);
    void polynomialComplexShow(double* data, int size);
    
public:
    static GGslTest* m_instance;
};
//===============================================
#endif
//===============================================
