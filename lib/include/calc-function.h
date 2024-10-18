#ifndef CALC_FUNCTION_H
#define CALC_FUNCTION_H

#include <cmath>
#include <gp_Pnt.hxx>

// set 배열에 저장하기 위한 사용자 규칙 구조체
struct Point{
    gp_Pnt point;

    bool operator<(const Point &other) const{
     if(point.X() != other.point.X()) return point.X() < other.point.X();
     if(point.Y() != other.point.Y()) return point.Y() < other.point.Y();
     return point.Z() < other.point.Z();
    }
};
// 부동소수점 두자리까지 표현하기 위한 함수
double roundTwoDecimal(double value);
gp_Pnt roundTwoDecimal(gp_Pnt pnt);


#endif