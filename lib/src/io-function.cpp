#include "io-function.h"

TopoDS_Shape openStepFile(const std::string &inputFileName)
{
    STEPControl_Reader reader;

    if (reader.ReadFile((BASE_PATH + inputFileName).c_str()) != IFSelect_RetDone)
    {
        std::cerr << "STEP 파일을 읽을 수 없습니다: " << inputFileName << std::endl;
        // throw std::runtime_error("step 파일 읽기 실패");
    }

    reader.TransferRoot();
    TopoDS_Shape shape = reader.OneShape();

    return shape;
}

void saveObjectToStep(const TopoDS_Shape &shape, const std::string &fileName)
{
    STEPControl_Writer writer;
    writer.Transfer(shape, STEPControl_AsIs);
    if (writer.Write(fileName.c_str()))
    {
        std::cout << "Save face to " << fileName << std::endl;
    }
    else
    {
        std::cerr << "Error saving face to " << fileName << std::endl;
    }
}

void saveObjectToStep(TopoDS_Face &face, const std::string &fileName, int& count){
    STEPControl_Writer writer;
    writer.Transfer(face, STEPControl_AsIs);
    if(writer.Write(fileName.c_str() + count)){
        std::cout << "Save face to " << fileName << count << std::endl;
    }
    else
    {
        std::cerr << "Error saving face to " << fileName << count << std::endl;
    }
}