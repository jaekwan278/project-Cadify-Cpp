#ifndef ALIGN_FUNCTION_H
#define ALIGN_FUNCTION_H

#include <gp_Pnt.hxx>
#include <TopoDS_Shape.hxx>
#include <BRepBuilderAPI_Transform.hxx>

gp_Pnt toBaseCalc(gp_Pnt &point);

TopoDS_Shape moveModelToBase(TopoDS_Shape shape, gp_Pnt &referencePnt);

#endif