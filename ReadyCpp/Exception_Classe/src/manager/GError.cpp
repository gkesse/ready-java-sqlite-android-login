//===============================================
#include "GError.h"
//===============================================
GError::GError() throw() {
    m_number = -1;
    m_error = "_NO_ERROR_";
    m_level = -1;
}
//===============================================
GError::GError(const int& number, const string& error, const int& level) throw() {
    m_number = number;
    m_error = error;
    m_level = level;
}
//===============================================
GError::~GError() throw() {
    
}
//===============================================
const char* GError::what() const throw() {
    return m_error.c_str();
}
//===============================================
int GError::getNumber() const {
    return m_number;
}
//===============================================
int GError::getLevel() const {
    return m_level;
}
//===============================================
