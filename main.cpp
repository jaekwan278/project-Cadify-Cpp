#include "lib/include/align-function.h"
#include "lib/include/calc-function.h"
#include "lib/include/face-function.h"
#include "lib/include/io-function.h"
#include "lib/include/point-function.h"
#include <set>

TopoDS_Shape process(const std::string& fileName, const std::string& outputFilePath){

    TopoDS_Shape shape = processStepFile(fileName);
    // 최대 넓이를 가진 하나 이상의 면을 담는 배열
    std::vector<TopoDS_Face> largestFaces = findLargestFaces(shape);
    // 최대 넓이를 가진 면들의 좌표를 담는 배열 & 중복 제거 & ( x >> y >> z )순으로 비교
    std::set<Point> largestFacesPnts;
    // 최대 넓이를 가진 면들의 좌표를 모두 저장
    for(const TopoDS_Face& face : largestFaces){
        std::vector<gp_Pnt> pnts = getFaceVertices(face);
        for(const gp_Pnt& pnt : pnts){
            const gp_Pnt roundedPnt = roundTwoDecimal(pnt);
            largestFacesPnts.insert(Point{roundedPnt});
        }
    }
    // 중복제거된 오름차순의 좌표 출력
    for(const Point& pnt : largestFacesPnts){
        std::cout << std::fixed << std::setprecision(2) << 
                "Vertix : x = " << pnt.point.X() << ", y = " << pnt.point.Y() << ", z = " << pnt.point.Z() << std::endl;
    }
    // 저장된 좌표 중 최소값을 가진 좌표 하나를 추출
    gp_Pnt minimumPnt = (*largestFacesPnts.begin()).point;
    std::cout << std::fixed << std::setprecision(2) << 
        "Minimum Vertix : " << minimumPnt.X() << ", y = " << minimumPnt.Y() << ", z = " << minimumPnt.Z() << std::endl;
    // 최소 좌표값을 가진 꼭짓점에서 0,0,0 까지의 거리 계산
    gp_Pnt referecePnt = toBaseCalc(minimumPnt);
    
    return moveModelToBase(shape, referecePnt);
}


int main()
{
    const std::string fileName = "1.5T.step";
    const std::string outputFilePath = "1.5T-result.step";

    TopoDS_Shape shape = process(fileName, outputFilePath);

    std::vector<TopoDS_Face> largestFaces = findLargestFaces(shape);
    // 최대 넓이를 가진 면들의 좌표를 담는 배열 & 중복 제거 & ( x >> y >> z )순으로 비교
    std::set<Point> largestFacesPnts;
    // 최대 넓이를 가진 면들의 좌표를 모두 저장
    for(const TopoDS_Face& face : largestFaces){
        std::vector<gp_Pnt> pnts = getFaceVertices(face);
        for(const gp_Pnt& pnt : pnts){
            const gp_Pnt roundedPnt = roundTwoDecimal(pnt);
            largestFacesPnts.insert(Point{roundedPnt});
        }
    }
    // 중복제거된 오름차순의 좌표 출력
    for(const Point& pnt : largestFacesPnts){
        std::cout << std::fixed << std::setprecision(2) << 
                "Vertix : x = " << pnt.point.X() << ", y = " << pnt.point.Y() << ", z = " << pnt.point.Z() << std::endl;
    }

    saveObjectToStep(shape, outputFilePath);
}