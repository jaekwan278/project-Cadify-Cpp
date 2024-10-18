#ifndef POINT_FUNCTION_H
#define POINT_FUNCTION_H

#include <vector>
#include <gp_Pnt.hxx>
#include <iostream>
#include <TopoDS_Face.hxx>
#include <TopExp_Explorer.hxx>
#include <TopoDS.hxx>
#include <TopoDS_Vertex.hxx>
#include <BRep_Tool.hxx>
#include "calc-function.h"

// Point 객체의 좌표를 출력하는 함수
void printVertices(const std::vector<gp_Pnt> &vertices, const std::string &label);
// Face 객체의 모든 촤표를 출력하는 함수
std::vector<gp_Pnt> getFaceVertices(const TopoDS_Face &face);
// 두 좌표 중 더 작은 좌표값을 가진 gp_Pnt를 반환 ( 비교순서 > X > Y > Z )
gp_Pnt findLowerPoint(const gp_Pnt &pointA, const gp_Pnt &pointB);
// 두 gp_Pnt 객체의 좌표를 비교하여 두께를 반환 ( 조건 : 두개의 좌표는 x y z 중 2가지의 좌표가 일치해야 함.)
double getThickFromTwoPoints(const gp_Pnt &pointA, const gp_Pnt &pointB);

#endif