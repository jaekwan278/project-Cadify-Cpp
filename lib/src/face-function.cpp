#include "face-function.h"

// 가장 큰 넓이를 가지고 있는 한 쌍의 면을 담은 배열 리턴
std::vector<TopoDS_Face> findLargestFaces(TopoDS_Shape& shape)
{
    // 가장 큰 넓이를 가지고 있는 복수의 면을 담을 배열
    std::vector<TopoDS_Face> largestFaces;
    double largestArea = 0.0;

    // 가장 큰 면 찾기
    for (TopExp_Explorer faceExplorer(shape, TopAbs_FACE); faceExplorer.More(); faceExplorer.Next())
    {
        TopoDS_Face face = TopoDS::Face(faceExplorer.Current());

        double area = roundTwoDecimal(calculateFaceArea(face));
        largestArea = roundTwoDecimal(largestArea); 

        if (area > largestArea)
        {
            largestArea = area;           // 순차적 비교
            largestFaces.clear();         // 기존 면 삭제
            largestFaces.push_back(face); // 새로운 면 추가
        }
        else if (area == largestArea)
        { // 반올림하여 소숫점 둘째자리까지 표현한 값이 일치하는지 확인.
            // 동일한경우 vector 배열에 추가 삽입
            largestFaces.push_back(face);
        }
    }

    return largestFaces;
}

double calculateFaceArea(const TopoDS_Face& face)
{
    GProp_GProps props;
    BRepGProp::SurfaceProperties(face, props);
    return props.Mass();
}

std::vector<TopoDS_Face> findAllFaces(TopoDS_Shape& shape){
    std::vector<TopoDS_Face> allFaces;

    for(TopExp_Explorer faceExplorer(shape, TopAbs_FACE); faceExplorer.More(); faceExplorer.Next()){
        TopoDS_Face face = TopoDS::Face(faceExplorer.Current());
        allFaces.push_back(face);
    }

    return allFaces;
}