//===============================================
#ifndef _GShape_
#define _GShape_
//===============================================
class GShape {
public:
    typedef enum {Line, Rectangle, Ellipse} GType;
    
public:
    virtual void draw() const = 0; 
    
public:
    static GShape* Create(GType type);
};
//===============================================
#endif
//===============================================
