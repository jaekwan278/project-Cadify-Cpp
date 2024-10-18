#include "calc-function.h"

double roundTwoDecimal(double value)
{
    return std::round(value * 100.0) / 100.0;
}

gp_Pnt roundTwoDecimal(gp_Pnt pnt){
    return gp_Pnt(
        std::round(pnt.X() * 100.0) / 100.0,
        std::round(pnt.Y() * 100.0) / 100.0,
        std::round(pnt.Z() * 100.0) / 100.0
    );
}