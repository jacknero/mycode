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
CMAKE_SOURCE_DIR = /home/matsui/itk/OutPutDeformableField

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/matsui/itk/OutPutDeformableField

# Include any dependencies generated for this target.
include CMakeFiles/OutPutDeformableField.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/OutPutDeformableField.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/OutPutDeformableField.dir/flags.make

CMakeFiles/OutPutDeformableField.dir/depend.make.mark: CMakeFiles/OutPutDeformableField.dir/flags.make
CMakeFiles/OutPutDeformableField.dir/depend.make.mark: OutPutDeformableField.cxx

CMakeFiles/OutPutDeformableField.dir/OutPutDeformableField.o: CMakeFiles/OutPutDeformableField.dir/flags.make
CMakeFiles/OutPutDeformableField.dir/OutPutDeformableField.o: OutPutDeformableField.cxx
	$(CMAKE_COMMAND) -E cmake_progress_report /home/matsui/itk/OutPutDeformableField/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/OutPutDeformableField.dir/OutPutDeformableField.o"
	/usr/bin/c++   $(CXX_FLAGS) -o CMakeFiles/OutPutDeformableField.dir/OutPutDeformableField.o -c /home/matsui/itk/OutPutDeformableField/OutPutDeformableField.cxx

CMakeFiles/OutPutDeformableField.dir/OutPutDeformableField.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OutPutDeformableField.dir/OutPutDeformableField.i"
	/usr/bin/c++  $(CXX_FLAGS) -E /home/matsui/itk/OutPutDeformableField/OutPutDeformableField.cxx > CMakeFiles/OutPutDeformableField.dir/OutPutDeformableField.i

CMakeFiles/OutPutDeformableField.dir/OutPutDeformableField.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OutPutDeformableField.dir/OutPutDeformableField.s"
	/usr/bin/c++  $(CXX_FLAGS) -S /home/matsui/itk/OutPutDeformableField/OutPutDeformableField.cxx -o CMakeFiles/OutPutDeformableField.dir/OutPutDeformableField.s

CMakeFiles/OutPutDeformableField.dir/OutPutDeformableField.o.requires:

CMakeFiles/OutPutDeformableField.dir/OutPutDeformableField.o.provides: CMakeFiles/OutPutDeformableField.dir/OutPutDeformableField.o.requires
	$(MAKE) -f CMakeFiles/OutPutDeformableField.dir/build.make CMakeFiles/OutPutDeformableField.dir/OutPutDeformableField.o.provides.build

CMakeFiles/OutPutDeformableField.dir/OutPutDeformableField.o.provides.build: CMakeFiles/OutPutDeformableField.dir/OutPutDeformableField.o

CMakeFiles/OutPutDeformableField.dir/depend: CMakeFiles/OutPutDeformableField.dir/depend.make.mark

CMakeFiles/OutPutDeformableField.dir/depend.make.mark:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --magenta --bold "Scanning dependencies of target OutPutDeformableField"
	cd /home/matsui/itk/OutPutDeformableField && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/matsui/itk/OutPutDeformableField /home/matsui/itk/OutPutDeformableField /home/matsui/itk/OutPutDeformableField /home/matsui/itk/OutPutDeformableField /home/matsui/itk/OutPutDeformableField/CMakeFiles/OutPutDeformableField.dir/DependInfo.cmake

# Object files for target OutPutDeformableField
OutPutDeformableField_OBJECTS = \
"CMakeFiles/OutPutDeformableField.dir/OutPutDeformableField.o"

# External object files for target OutPutDeformableField
OutPutDeformableField_EXTERNAL_OBJECTS =

OutPutDeformableField: CMakeFiles/OutPutDeformableField.dir/OutPutDeformableField.o
OutPutDeformableField: CMakeFiles/OutPutDeformableField.dir/build.make
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable OutPutDeformableField"
	$(CMAKE_COMMAND) -P CMakeFiles/OutPutDeformableField.dir/cmake_clean_target.cmake
	/usr/bin/c++      -ftemplate-depth-50 -Wall  -fPIC   $(OutPutDeformableField_OBJECTS) $(OutPutDeformableField_EXTERNAL_OBJECTS)  -o OutPutDeformableField -rdynamic -L/usr/local/lib/InsightToolkit -lITKIO -lITKNumerics -lITKNrrdIO -litkgdcm -litkjpeg12 -litkjpeg16 -litkopenjpeg -litkpng -litktiff -litkjpeg8 -lITKSpatialObject -lITKMetaIO -lITKDICOMParser -lITKEXPAT -lITKniftiio -lITKznz -litkzlib -lITKCommon -litkvnl_inst -litkvnl_algo -litkv3p_netlib -litkvnl -litkvcl -lm -litksys -lpthread -ldl -lm -Wl,-rpath,/usr/local/lib/InsightToolkit 

# Rule to build all files generated by this target.
CMakeFiles/OutPutDeformableField.dir/build: OutPutDeformableField

CMakeFiles/OutPutDeformableField.dir/requires: CMakeFiles/OutPutDeformableField.dir/OutPutDeformableField.o.requires

CMakeFiles/OutPutDeformableField.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/OutPutDeformableField.dir/cmake_clean.cmake
