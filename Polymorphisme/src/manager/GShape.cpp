//===============================================
#include "GShape.h"
#include "GShapeLine.h"
#include "GShapeRectangle.h"
#include "GShapeEllipse.h"
//===============================================
GShape* GShape::Create(GType type) {
    switch(type) {
        case Line: return new GShapeLine;
        case Rectangle: return new GShapeRectangle;
        case Ellipse: return new GShapeEllipse;
    }
    return 0;
}