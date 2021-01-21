//===============================================
#ifndef _GOpenCV_
#define _GOpenCV_
//===============================================
#include "GInclude.h"
//===============================================
class GOpenCV { 
private:
    GOpenCV();
   
public:
    virtual ~GOpenCV();
    static GOpenCV* Instance();
    // image
    void loadImage(QString imgPath);
    void invertImage(QString imgPath);
    // video
    void loadVideo(QString videoPath);

private:
    static GOpenCV* m_instance;
};
//===============================================
#endif
//===============================================
