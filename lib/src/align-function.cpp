#include "align-function.h"

gp_Pnt toBaseCalc(gp_Pnt &point)
{
    double x = 0.0 - point.X();
    double y = 0.0 - point.Y();
    double z = 0.0 - point.Z();

    return gp_Pnt(x, y, z);
}

TopoDS_Shape moveModelToBase(TopoDS_Shape shape, gp_Pnt &referencePnt)
{
    gp_Vec translationVec = gp_Vec(referencePnt.X(), referencePnt.Y(), referencePnt.Z());

    gp_Trsf transformation;
    transformation.SetTranslation(translationVec);

    BRepBuilderAPI_Transform transform(shape, transformation);
    shape = transform.Shape();
    return shape;
}