# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.30.5/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.30.5/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/jaekwan/WorkSpace/Project/project-CadifyCpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/jaekwan/WorkSpace/Project/project-CadifyCpp/build

# Include any dependencies generated for this target.
include CMakeFiles/CadifyCpp.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/CadifyCpp.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/CadifyCpp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CadifyCpp.dir/flags.make

CMakeFiles/CadifyCpp.dir/main.cpp.o: CMakeFiles/CadifyCpp.dir/flags.make
CMakeFiles/CadifyCpp.dir/main.cpp.o: /Users/jaekwan/WorkSpace/Project/project-CadifyCpp/main.cpp
CMakeFiles/CadifyCpp.dir/main.cpp.o: CMakeFiles/CadifyCpp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/jaekwan/WorkSpace/Project/project-CadifyCpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CadifyCpp.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CadifyCpp.dir/main.cpp.o -MF CMakeFiles/CadifyCpp.dir/main.cpp.o.d -o CMakeFiles/CadifyCpp.dir/main.cpp.o -c /Users/jaekwan/WorkSpace/Project/project-CadifyCpp/main.cpp

CMakeFiles/CadifyCpp.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/CadifyCpp.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jaekwan/WorkSpace/Project/project-CadifyCpp/main.cpp > CMakeFiles/CadifyCpp.dir/main.cpp.i

CMakeFiles/CadifyCpp.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/CadifyCpp.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jaekwan/WorkSpace/Project/project-CadifyCpp/main.cpp -o CMakeFiles/CadifyCpp.dir/main.cpp.s

# Object files for target CadifyCpp
CadifyCpp_OBJECTS = \
"CMakeFiles/CadifyCpp.dir/main.cpp.o"

# External object files for target CadifyCpp
CadifyCpp_EXTERNAL_OBJECTS =

CadifyCpp: CMakeFiles/CadifyCpp.dir/main.cpp.o
CadifyCpp: CMakeFiles/CadifyCpp.dir/build.make
CadifyCpp: /usr/local/lib/libTKXMesh.7.8.2.dylib
CadifyCpp: /usr/local/lib/libTKExpress.7.8.2.dylib
CadifyCpp: /usr/local/lib/libTKOpenGlTest.7.8.2.dylib
CadifyCpp: /usr/local/lib/libTKXDEDRAW.7.8.2.dylib
CadifyCpp: /usr/local/lib/libTKTObjDRAW.7.8.2.dylib
CadifyCpp: /usr/local/lib/libTKQADraw.7.8.2.dylib
CadifyCpp: /usr/local/lib/libTKXSDRAWDE.7.8.2.dylib
CadifyCpp: /usr/local/lib/libTKXSDRAWGLTF.7.8.2.dylib
CadifyCpp: /usr/local/lib/libTKXSDRAWIGES.7.8.2.dylib
CadifyCpp: /usr/local/lib/libTKXSDRAWOBJ.7.8.2.dylib
CadifyCpp: /usr/local/lib/libTKXSDRAWPLY.7.8.2.dylib
CadifyCpp: /usr/local/lib/libTKXSDRAWSTEP.7.8.2.dylib
CadifyCpp: /usr/local/lib/libTKXSDRAWSTL.7.8.2.dylib
CadifyCpp: /usr/local/lib/libTKXSDRAWVRML.7.8.2.dylib
CadifyCpp: /usr/local/lib/libTKOpenGl.7.8.2.dylib
CadifyCpp: /usr/local/lib/libTKDECascade.7.8.2.dylib
CadifyCpp: /usr/local/lib/libTKBinTObj.7.8.2.dylib
CadifyCpp: /usr/local/lib/libTKXmlTObj.7.8.2.dylib
CadifyCpp: /usr/local/lib/libTKTObj.7.8.2.dylib
CadifyCpp: /usr/local/lib/libTKBinXCAF.7.8.2.dylib
CadifyCpp: /usr/local/lib/libTKXmlXCAF.7.8.2.dylib
CadifyCpp: /usr/local/lib/libTKDEGLTF.7.8.2.dylib
CadifyCpp: /usr/local/lib/libTKDEIGES.7.8.2.dylib
CadifyCpp: /usr/local/lib/libTKDEOBJ.7.8.2.dylib
CadifyCpp: /usr/local/lib/libTKDEPLY.7.8.2.dylib
CadifyCpp: /usr/local/lib/libTKDESTEP.7.8.2.dylib
CadifyCpp: /usr/local/lib/libTKDESTL.7.8.2.dylib
CadifyCpp: /usr/local/lib/libTKDEVRML.7.8.2.dylib
CadifyCpp: /usr/local/lib/libTKRWMesh.7.8.2.dylib
CadifyCpp: /usr/local/lib/libTKDE.7.8.2.dylib
CadifyCpp: /usr/local/lib/libTKXSDRAW.7.8.2.dylib
CadifyCpp: /usr/local/lib/libTKMeshVS.7.8.2.dylib
CadifyCpp: /usr/local/lib/libTKXSBase.7.8.2.dylib
CadifyCpp: /usr/local/lib/libTKXCAF.7.8.2.dylib
CadifyCpp: /usr/local/lib/libTKDCAF.7.8.2.dylib
CadifyCpp: /usr/local/lib/libTKBin.7.8.2.dylib
CadifyCpp: /usr/local/lib/libTKBinL.7.8.2.dylib
CadifyCpp: /usr/local/lib/libTKXml.7.8.2.dylib
CadifyCpp: /usr/local/lib/libTKXmlL.7.8.2.dylib
CadifyCpp: /usr/local/lib/libTKStd.7.8.2.dylib
CadifyCpp: /usr/local/lib/libTKStdL.7.8.2.dylib
CadifyCpp: /usr/local/lib/libTKVCAF.7.8.2.dylib
CadifyCpp: /usr/local/lib/libTKCAF.7.8.2.dylib
CadifyCpp: /usr/local/lib/libTKLCAF.7.8.2.dylib
CadifyCpp: /usr/local/lib/libTKCDF.7.8.2.dylib
CadifyCpp: /usr/local/lib/libTKViewerTest.7.8.2.dylib
CadifyCpp: /usr/local/lib/libTKTopTest.7.8.2.dylib
CadifyCpp: /usr/local/lib/libTKOffset.7.8.2.dylib
CadifyCpp: /usr/local/lib/libTKFillet.7.8.2.dylib
CadifyCpp: /usr/local/lib/libTKFeat.7.8.2.dylib
CadifyCpp: /usr/local/lib/libTKBool.7.8.2.dylib
CadifyCpp: /usr/local/lib/libTKBO.7.8.2.dylib
CadifyCpp: /usr/local/lib/libTKPrim.7.8.2.dylib
CadifyCpp: /usr/local/lib/libTKV3d.7.8.2.dylib
CadifyCpp: /usr/local/lib/libTKDraw.7.8.2.dylib
CadifyCpp: /usr/local/lib/libTKHLR.7.8.2.dylib
CadifyCpp: /usr/local/lib/libTKMesh.7.8.2.dylib
CadifyCpp: /usr/local/lib/libTKShHealing.7.8.2.dylib
CadifyCpp: /usr/local/lib/libTKTopAlgo.7.8.2.dylib
CadifyCpp: /usr/local/lib/libTKGeomAlgo.7.8.2.dylib
CadifyCpp: /usr/local/lib/libTKBRep.7.8.2.dylib
CadifyCpp: /usr/local/lib/libTKGeomBase.7.8.2.dylib
CadifyCpp: /usr/local/lib/libTKG3d.7.8.2.dylib
CadifyCpp: /usr/local/lib/libTKG2d.7.8.2.dylib
CadifyCpp: /usr/local/lib/libTKService.7.8.2.dylib
CadifyCpp: /usr/local/lib/libTKMath.7.8.2.dylib
CadifyCpp: /usr/local/lib/libTKernel.7.8.2.dylib
CadifyCpp: /opt/homebrew/lib/libfreetype.dylib
CadifyCpp: CMakeFiles/CadifyCpp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/jaekwan/WorkSpace/Project/project-CadifyCpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable CadifyCpp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CadifyCpp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CadifyCpp.dir/build: CadifyCpp
.PHONY : CMakeFiles/CadifyCpp.dir/build

CMakeFiles/CadifyCpp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CadifyCpp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CadifyCpp.dir/clean

CMakeFiles/CadifyCpp.dir/depend:
	cd /Users/jaekwan/WorkSpace/Project/project-CadifyCpp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jaekwan/WorkSpace/Project/project-CadifyCpp /Users/jaekwan/WorkSpace/Project/project-CadifyCpp /Users/jaekwan/WorkSpace/Project/project-CadifyCpp/build /Users/jaekwan/WorkSpace/Project/project-CadifyCpp/build /Users/jaekwan/WorkSpace/Project/project-CadifyCpp/build/CMakeFiles/CadifyCpp.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/CadifyCpp.dir/depend
