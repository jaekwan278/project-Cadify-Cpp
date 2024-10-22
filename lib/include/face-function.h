#ifndef FACE_FUNCTION_H
#define FACE_FUNCTION_H

#include <vector>
#include <TopoDS_Face.hxx>
#include <TopExp_Explorer.hxx>
#include <TopoDS.hxx>
#include <GProp_GProps.hxx>
#include <BRepGProp.hxx>
#include "calc-function.h"

// 가장 큰 면적을 가진 TopoDS_Face 객체를 찾는 함수.
std::vector<TopoDS_Face> findLargestFaces(TopoDS_Shape& shape);
// TopoDS_Face 객체의 넓이를 계산
double calculateFaceArea(const TopoDS_Face& face);

std::vector<TopoDS_Face> findAllFaces(TopoDS_Shape& shape);

#endif