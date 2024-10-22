#ifndef AAG_FUNCTION_H
#define AAG_FUNCTION_H

#include <TopoDS_Face.hxx>
#include <BRepAdaptor_Surface.hxx>
#include <GeomAbs_SurfaceType.hxx>
#include <TopExp_Explorer.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <TopoDS.hxx>
#include <TopoDS_Edge.hxx>
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include "io-function.h"

struct AAGNode
{
     TopoDS_Face face;
     std::map<int, AAGNode> adjacentFaces;
     std::string surfaceType;
};

class AAGAnalyzer {
     public:
          AAGAnalyzer(const std::vector<TopoDS_Face>& faces);
          void printAAG() const;
     
     private:
          std::map<int, AAGNode> AAG;
          void analyzeShape(std::map<int, AAGNode>& baseMap);
          std::string getSurfaceType(const TopoDS_Face& face) const;
};

#endif