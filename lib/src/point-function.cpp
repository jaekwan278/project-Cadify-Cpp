#include "point-function.h"

void printVertices(const std::vector<gp_Pnt> &vertices)
{
    for (const auto &point : vertices)
    {
        std::cout << std::fixed << std::setprecision(1)
                  << "Vertex: (" << point.X() << ", " << point.Y() << ", " << point.Z() << ")" << std::endl;
    }
}

std::vector<gp_Pnt> getFaceVertices(const TopoDS_Face &face)
{
    std::vector<gp_Pnt> vertices;
    for (TopExp_Explorer vertexExp(face, TopAbs_VERTEX); vertexExp.More(); vertexExp.Next())
    {
        TopoDS_Vertex vertex = TopoDS::Vertex(vertexExp.Current());
        vertices.push_back(BRep_Tool::Pnt(vertex));
    }
    return vertices;
}

gp_Pnt findLowerPoint(const gp_Pnt &pointA, const gp_Pnt &pointB)
{
    double aX = roundTwoDecimal(pointA.X());
    double aY = roundTwoDecimal(pointA.Y());
    double aZ = roundTwoDecimal(pointA.Z());

    double bX = roundTwoDecimal(pointB.X());
    double bY = roundTwoDecimal(pointB.Y());
    double bZ = roundTwoDecimal(pointB.Z());

    if (aX != bX && aY == bY && aZ == bZ)
    {
        std::cout << "USED X" << std::endl;
        if (aX > bX)
        {
            return pointB;
        }
        else
        {
            return pointA;
        }
    }
    else if (aX == bX && aY != bY && aZ == bZ)
    {
        std::cout << "USED Y" << std::endl;
        if (aY > bY)
        {
            return pointB;
        }
        else
        {
            return pointA;
        }
    }
    else if (aX == bX && aY == bY && aZ != bZ)
    {
        std::cout << "USED Z" << std::endl;
        if (aZ > bZ)
        {
            return pointB;
        }
        else
        {
            return pointA;
        }
    }
    else
    {
        std::cerr << "Get Thick : 판단할 수 없는 구조." << std::endl;
        return gp_Pnt(0, 0, 0);
    }
}

double getThickFromTwoPoints(const gp_Pnt &pointA, const gp_Pnt &pointB)
{
    double aX = roundTwoDecimal(pointA.X());
    double aY = roundTwoDecimal(pointA.Y());
    double aZ = roundTwoDecimal(pointA.Z());

    double bX = roundTwoDecimal(pointB.X());
    double bY = roundTwoDecimal(pointB.Y());
    double bZ = roundTwoDecimal(pointB.Z());

    if (aX != bX && aY == bY && aZ == bZ)
    {
        std::cout << "USED X" << std::endl;
        if (aX > bX)
        {
            return aX - bX;
        }
        else
        {
            return bX - aX;
        }
    }
    else if (aX == bX && aY != bY && aZ == bZ)
    {
        std::cout << "USED Y" << std::endl;
        if (aY > bY)
        {
            return aY - bY;
        }
        else
        {
            return bY - aY;
        }
    }
    else if (aX == bX && aY == bY && aZ != bZ)
    {
        std::cout << "USED Z" << std::endl;
        if (aZ > bZ)
        {
            return aZ - bZ;
        }
        else
        {
            return bZ - aZ;
        }
    }
    else
    {
        std::cerr << "Get Thick : 판단할 수 없는 구조." << std::endl;
        return 0.0;
    }
}