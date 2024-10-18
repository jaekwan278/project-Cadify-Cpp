#ifndef IO_FUNCTION_H
#define IO_FUNCTION_H

#include <TopoDS_Shape.hxx>
#include <STEPControl_Reader.hxx>
#include <TopoDS_Face.hxx>
#include <STEPControl_Writer.hxx>
#include <iostream>
/*
step 파일 입출력 관련 함수
*/

const std::string BASE_PATH = "/Users/jaekwan/WorkSpace/Project/project-Cadify-Cpp/testFile/";

// 경로에 있는 step 파일을 읽어 옴.
TopoDS_Shape processStepFile(const std::string &inputFilePath);

// TopoDS_Shape 객체를 step 파일 형식으로 저장.
void saveObjectToStep(const TopoDS_Shape &shape, const std::string &filePath);

#endif