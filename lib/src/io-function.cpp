#include "io-function.h"

TopoDS_Shape processStepFile(const std::string &inputFileName)
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

void saveObjectToStep(const TopoDS_Shape &shape, const std::string &filename)
{
    STEPControl_Writer writer;
    writer.Transfer(shape, STEPControl_AsIs);
    if (writer.Write(filename.c_str()))
    {
        std::cout << "Save face to " << filename << std::endl;
    }
    else
    {
        std::cerr << "Error saving face to " << filename << std::endl;
    }
}