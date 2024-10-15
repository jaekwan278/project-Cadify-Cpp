#include <STEPControl_Reader.hxx>
#include <STEPControl_Writer.hxx>
#include <TopoDS_Shape.hxx>
#include <TopExp_Explorer.hxx>
#include <TopoDS.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Vertex.hxx>
#include <BRep_Tool.hxx>
#include <Geom_Surface.hxx>
#include <BRepAdaptor_Surface.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <gp_Trsf.hxx>
#include <gp_Ax1.hxx>
#include <gp_Dir.hxx>
#include <BRepBuilderAPI_Transform.hxx>
#include <BRepGProp.hxx>
#include <GProp_GProps.hxx>
#include <Precision.hxx>
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

// 스텝 파일 리더
TopoDS_Shape processStepFile(const std::string& inputFilePath, const std::string& outputFilePath) {
    STEPControl_Reader reader;
    if (reader.ReadFile(inputFilePath.c_str()) != IFSelect_RetDone) {
        std::cerr << "STEP 파일을 읽을 수 없습니다: " << inputFilePath << std::endl;
        throw std::runtime_error("step 파일 읽기 실패");
    }

    reader.TransferRoot();
    TopoDS_Shape shape = reader.OneShape();

    return shape;
}

// 면적 계산 함수
double calculateFaceArea(const TopoDS_Face& face) {
    GProp_GProps props;
    BRepGProp::SurfaceProperties(face, props);
    return props.Mass();
}

// 변환된 형상을 STEP 파일로 저장하는 함수
void saveAsStepFile(const TopoDS_Shape& shape, const std::string& filePath) {
    STEPControl_Writer writer;
    writer.Transfer(shape, STEPControl_AsIs);
    if (writer.Write(filePath.c_str()) != IFSelect_RetDone) {
        std::cerr << "STEP 파일 저장 실패: " << filePath << std::endl;
    }
    else {
        std::cout << "STEP 파일 저장 성공: " << filePath << std::endl;
    }
}

// 면의 모든 꼭짓점 좌표를 얻는 함수
std::vector<gp_Pnt> getFaceVertices(const TopoDS_Face& face) {
    std::vector<gp_Pnt> vertices;
    for (TopExp_Explorer vertexExp(face, TopAbs_VERTEX); vertexExp.More(); vertexExp.Next()) {
        TopoDS_Vertex vertex = TopoDS::Vertex(vertexExp.Current());
        vertices.push_back(BRep_Tool::Pnt(vertex));
    }
    return vertices;
}

// 변환 전후의 좌표를 출력하는 함수
void printVertices(const std::vector<gp_Pnt>& vertices, const std::string& label) {
    std::cout << label << std::endl;
    for (const auto& point : vertices) {
        std::cout << std::fixed << std::setprecision(1)
            << "Vertex: (" << point.X() << ", " << point.Y() << ", " << point.Z() << ")" << std::endl;
    }
}

int main() {
    std::string inputFilePath = "/Users/jaekwan/WorkSpace/Study/OCCT/study-opencascade/testFile/basic.step";
    std::string outputFilePath = "result.step";
    // 파일 읽기 & 쓰기 
    // return : shape 객체
    TopoDS_Shape shape = processStepFile(inputFilePath, outputFilePath);

    // 가장 큰 면적을 가지고 있는 복수의 면을 담을 배열
    std::vector<TopoDS_Face> largestFaces;
    double largestArea = 0.0;

    // 가장 큰 면 찾기
    for (TopExp_Explorer faceExplorer(shape, TopAbs_FACE); faceExplorer.More(); faceExplorer.Next()) {
        TopoDS_Face face = TopoDS::Face(faceExplorer.Current());
        double area = calculateFaceArea(face);
        if (area > largestArea) {
            largestArea = area;             // 순차적 비교
            largestFaces.clear();           // 기존 면 삭제
            largestFaces.push_back(face);   // 새로운 면 추가
        } else if(area == largestArea){
            // 면적이 동일한 경우
            largestFaces.push_back(face);
        }
    }
    for (const TopoDS_Face& face : largestFaces) {
        // 면의 꼭짓점 좌표를 가져옴
        std::vector<gp_Pnt> vertices = getFaceVertices(face);
        printVertices(vertices, "꼭짓점 좌표:");
    }
}