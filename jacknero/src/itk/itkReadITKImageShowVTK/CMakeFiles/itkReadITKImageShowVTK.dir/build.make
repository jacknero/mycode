# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.4

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canoncical targets will work.
.SUFFIXES:

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/matsui/itk/itkReadITKImageShowVTK

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/matsui/itk/itkReadITKImageShowVTK

# Include any dependencies generated for this target.
include CMakeFiles/itkReadITKImageShowVTK.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/itkReadITKImageShowVTK.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/itkReadITKImageShowVTK.dir/flags.make

CMakeFiles/itkReadITKImageShowVTK.dir/depend.make.mark: CMakeFiles/itkReadITKImageShowVTK.dir/flags.make
CMakeFiles/itkReadITKImageShowVTK.dir/depend.make.mark: itkReadITKImageShowVTK.cxx

CMakeFiles/itkReadITKImageShowVTK.dir/itkReadITKImageShowVTK.o: CMakeFiles/itkReadITKImageShowVTK.dir/flags.make
CMakeFiles/itkReadITKImageShowVTK.dir/itkReadITKImageShowVTK.o: itkReadITKImageShowVTK.cxx
	$(CMAKE_COMMAND) -E cmake_progress_report /home/matsui/itk/itkReadITKImageShowVTK/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/itkReadITKImageShowVTK.dir/itkReadITKImageShowVTK.o"
	/usr/bin/c++   $(CXX_FLAGS) -o CMakeFiles/itkReadITKImageShowVTK.dir/itkReadITKImageShowVTK.o -c /home/matsui/itk/itkReadITKImageShowVTK/itkReadITKImageShowVTK.cxx

CMakeFiles/itkReadITKImageShowVTK.dir/itkReadITKImageShowVTK.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/itkReadITKImageShowVTK.dir/itkReadITKImageShowVTK.i"
	/usr/bin/c++  $(CXX_FLAGS) -E /home/matsui/itk/itkReadITKImageShowVTK/itkReadITKImageShowVTK.cxx > CMakeFiles/itkReadITKImageShowVTK.dir/itkReadITKImageShowVTK.i

CMakeFiles/itkReadITKImageShowVTK.dir/itkReadITKImageShowVTK.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/itkReadITKImageShowVTK.dir/itkReadITKImageShowVTK.s"
	/usr/bin/c++  $(CXX_FLAGS) -S /home/matsui/itk/itkReadITKImageShowVTK/itkReadITKImageShowVTK.cxx -o CMakeFiles/itkReadITKImageShowVTK.dir/itkReadITKImageShowVTK.s

CMakeFiles/itkReadITKImageShowVTK.dir/itkReadITKImageShowVTK.o.requires:

CMakeFiles/itkReadITKImageShowVTK.dir/itkReadITKImageShowVTK.o.provides: CMakeFiles/itkReadITKImageShowVTK.dir/itkReadITKImageShowVTK.o.requires
	$(MAKE) -f CMakeFiles/itkReadITKImageShowVTK.dir/build.make CMakeFiles/itkReadITKImageShowVTK.dir/itkReadITKImageShowVTK.o.provides.build

CMakeFiles/itkReadITKImageShowVTK.dir/itkReadITKImageShowVTK.o.provides.build: CMakeFiles/itkReadITKImageShowVTK.dir/itkReadITKImageShowVTK.o

CMakeFiles/itkReadITKImageShowVTK.dir/depend: CMakeFiles/itkReadITKImageShowVTK.dir/depend.make.mark

CMakeFiles/itkReadITKImageShowVTK.dir/depend.make.mark:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --magenta --bold "Scanning dependencies of target itkReadITKImageShowVTK"
	cd /home/matsui/itk/itkReadITKImageShowVTK && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/matsui/itk/itkReadITKImageShowVTK /home/matsui/itk/itkReadITKImageShowVTK /home/matsui/itk/itkReadITKImageShowVTK /home/matsui/itk/itkReadITKImageShowVTK /home/matsui/itk/itkReadITKImageShowVTK/CMakeFiles/itkReadITKImageShowVTK.dir/DependInfo.cmake

# Object files for target itkReadITKImageShowVTK
itkReadITKImageShowVTK_OBJECTS = \
"CMakeFiles/itkReadITKImageShowVTK.dir/itkReadITKImageShowVTK.o"

# External object files for target itkReadITKImageShowVTK
itkReadITKImageShowVTK_EXTERNAL_OBJECTS =

itkReadITKImageShowVTK: CMakeFiles/itkReadITKImageShowVTK.dir/itkReadITKImageShowVTK.o
itkReadITKImageShowVTK: /usr/lib/libGL.so
itkReadITKImageShowVTK: /usr/lib/libOSMesa.so
itkReadITKImageShowVTK: /usr/lib/libXt.so
itkReadITKImageShowVTK: /usr/lib/libX11.so
itkReadITKImageShowVTK: /usr/lib/libXext.so
itkReadITKImageShowVTK: CMakeFiles/itkReadITKImageShowVTK.dir/build.make
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable itkReadITKImageShowVTK"
	$(CMAKE_COMMAND) -P CMakeFiles/itkReadITKImageShowVTK.dir/cmake_clean_target.cmake
	/usr/bin/c++      -ftemplate-depth-50 -Wall  -Wno-deprecated  -fPIC    $(itkReadITKImageShowVTK_OBJECTS) $(itkReadITKImageShowVTK_EXTERNAL_OBJECTS)  -o itkReadITKImageShowVTK -rdynamic -L/usr/local/lib/InsightToolkit -L/usr/local/sbin/../lib/vtk-5.2 -lITKBasicFilters -lITKIO -lvtkRendering -lvtkIO -lvtkWidgets -lITKNrrdIO -litkgdcm -litkjpeg12 -litkjpeg16 -litkopenjpeg -litkpng -litktiff -litkjpeg8 -lITKSpatialObject -lITKCommon -litkvnl_inst -litkvnl_algo -litkv3p_netlib -litkvnl -litkvcl -lm -lITKMetaIO -litksys -lITKDICOMParser -lITKEXPAT -lITKniftiio -lITKznz -litkzlib -lvtkHybrid -lvtkRendering -lvtkGraphics -lvtkverdict -lvtkImaging -lvtkftgl -lvtkfreetype -lGL -lOSMesa -lXt -lSM -lICE -lSM -lICE -lX11 -lXext -lX11 -lXext -lvtkIO -lvtkFiltering -lvtkCommon -lpthread -lm -lvtkDICOMParser -lvtkmetaio -lvtksqlite -lvtkpng -lvtktiff -lvtkzlib -lvtkjpeg -lvtkexpat -lvtksys -ldl -lvtkexoIIc -lvtkNetCDF -Wl,-rpath,/usr/local/lib/InsightToolkit:/usr/local/sbin/../lib/vtk-5.2 

# Rule to build all files generated by this target.
CMakeFiles/itkReadITKImageShowVTK.dir/build: itkReadITKImageShowVTK

# Object files for target itkReadITKImageShowVTK
itkReadITKImageShowVTK_OBJECTS = \
"CMakeFiles/itkReadITKImageShowVTK.dir/itkReadITKImageShowVTK.o"

# External object files for target itkReadITKImageShowVTK
itkReadITKImageShowVTK_EXTERNAL_OBJECTS =

CMakeFiles/CMakeRelink.dir/itkReadITKImageShowVTK: CMakeFiles/itkReadITKImageShowVTK.dir/itkReadITKImageShowVTK.o
CMakeFiles/CMakeRelink.dir/itkReadITKImageShowVTK: /usr/lib/libGL.so
CMakeFiles/CMakeRelink.dir/itkReadITKImageShowVTK: /usr/lib/libOSMesa.so
CMakeFiles/CMakeRelink.dir/itkReadITKImageShowVTK: /usr/lib/libXt.so
CMakeFiles/CMakeRelink.dir/itkReadITKImageShowVTK: /usr/lib/libX11.so
CMakeFiles/CMakeRelink.dir/itkReadITKImageShowVTK: /usr/lib/libXext.so
CMakeFiles/CMakeRelink.dir/itkReadITKImageShowVTK: CMakeFiles/itkReadITKImageShowVTK.dir/build.make
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable CMakeFiles/CMakeRelink.dir/itkReadITKImageShowVTK"
	$(CMAKE_COMMAND) -P CMakeFiles/itkReadITKImageShowVTK.dir/cmake_clean_target.cmake
	/usr/bin/c++      -ftemplate-depth-50 -Wall  -Wno-deprecated  -fPIC    $(itkReadITKImageShowVTK_OBJECTS) $(itkReadITKImageShowVTK_EXTERNAL_OBJECTS)  -o CMakeFiles/CMakeRelink.dir/itkReadITKImageShowVTK -rdynamic -L/usr/local/lib/InsightToolkit -L/usr/local/sbin/../lib/vtk-5.2 -lITKBasicFilters -lITKIO -lvtkRendering -lvtkIO -lvtkWidgets -lITKNrrdIO -litkgdcm -litkjpeg12 -litkjpeg16 -litkopenjpeg -litkpng -litktiff -litkjpeg8 -lITKSpatialObject -lITKCommon -litkvnl_inst -litkvnl_algo -litkv3p_netlib -litkvnl -litkvcl -lm -lITKMetaIO -litksys -lITKDICOMParser -lITKEXPAT -lITKniftiio -lITKznz -litkzlib -lvtkHybrid -lvtkRendering -lvtkGraphics -lvtkverdict -lvtkImaging -lvtkftgl -lvtkfreetype -lGL -lOSMesa -lXt -lSM -lICE -lSM -lICE -lX11 -lXext -lX11 -lXext -lvtkIO -lvtkFiltering -lvtkCommon -lpthread -lm -lvtkDICOMParser -lvtkmetaio -lvtksqlite -lvtkpng -lvtktiff -lvtkzlib -lvtkjpeg -lvtkexpat -lvtksys -ldl -lvtkexoIIc -lvtkNetCDF 

# Rule to relink during preinstall.
CMakeFiles/itkReadITKImageShowVTK.dir/preinstall: CMakeFiles/CMakeRelink.dir/itkReadITKImageShowVTK

CMakeFiles/itkReadITKImageShowVTK.dir/requires: CMakeFiles/itkReadITKImageShowVTK.dir/itkReadITKImageShowVTK.o.requires

CMakeFiles/itkReadITKImageShowVTK.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/itkReadITKImageShowVTK.dir/cmake_clean.cmake

