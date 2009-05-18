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
CMAKE_SOURCE_DIR = /home/matsui/itk/SqureDifferentedImageFilter

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/matsui/itk/SqureDifferentedImageFilter

# Include any dependencies generated for this target.
include CMakeFiles/ImageRegistration8.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ImageRegistration8.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ImageRegistration8.dir/flags.make

CMakeFiles/ImageRegistration8.dir/depend.make.mark: CMakeFiles/ImageRegistration8.dir/flags.make
CMakeFiles/ImageRegistration8.dir/depend.make.mark: ImageRegistration6o.cxx

CMakeFiles/ImageRegistration8.dir/ImageRegistration6o.o: CMakeFiles/ImageRegistration8.dir/flags.make
CMakeFiles/ImageRegistration8.dir/ImageRegistration6o.o: ImageRegistration6o.cxx
	$(CMAKE_COMMAND) -E cmake_progress_report /home/matsui/itk/SqureDifferentedImageFilter/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/ImageRegistration8.dir/ImageRegistration6o.o"
	/usr/bin/c++   $(CXX_FLAGS) -o CMakeFiles/ImageRegistration8.dir/ImageRegistration6o.o -c /home/matsui/itk/SqureDifferentedImageFilter/ImageRegistration6o.cxx

CMakeFiles/ImageRegistration8.dir/ImageRegistration6o.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ImageRegistration8.dir/ImageRegistration6o.i"
	/usr/bin/c++  $(CXX_FLAGS) -E /home/matsui/itk/SqureDifferentedImageFilter/ImageRegistration6o.cxx > CMakeFiles/ImageRegistration8.dir/ImageRegistration6o.i

CMakeFiles/ImageRegistration8.dir/ImageRegistration6o.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ImageRegistration8.dir/ImageRegistration6o.s"
	/usr/bin/c++  $(CXX_FLAGS) -S /home/matsui/itk/SqureDifferentedImageFilter/ImageRegistration6o.cxx -o CMakeFiles/ImageRegistration8.dir/ImageRegistration6o.s

CMakeFiles/ImageRegistration8.dir/ImageRegistration6o.o.requires:

CMakeFiles/ImageRegistration8.dir/ImageRegistration6o.o.provides: CMakeFiles/ImageRegistration8.dir/ImageRegistration6o.o.requires
	$(MAKE) -f CMakeFiles/ImageRegistration8.dir/build.make CMakeFiles/ImageRegistration8.dir/ImageRegistration6o.o.provides.build

CMakeFiles/ImageRegistration8.dir/ImageRegistration6o.o.provides.build: CMakeFiles/ImageRegistration8.dir/ImageRegistration6o.o

CMakeFiles/ImageRegistration8.dir/depend: CMakeFiles/ImageRegistration8.dir/depend.make.mark

CMakeFiles/ImageRegistration8.dir/depend.make.mark:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --magenta --bold "Scanning dependencies of target ImageRegistration8"
	cd /home/matsui/itk/SqureDifferentedImageFilter && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/matsui/itk/SqureDifferentedImageFilter /home/matsui/itk/SqureDifferentedImageFilter /home/matsui/itk/SqureDifferentedImageFilter /home/matsui/itk/SqureDifferentedImageFilter /home/matsui/itk/SqureDifferentedImageFilter/CMakeFiles/ImageRegistration8.dir/DependInfo.cmake

# Object files for target ImageRegistration8
ImageRegistration8_OBJECTS = \
"CMakeFiles/ImageRegistration8.dir/ImageRegistration6o.o"

# External object files for target ImageRegistration8
ImageRegistration8_EXTERNAL_OBJECTS =

ImageRegistration8: CMakeFiles/ImageRegistration8.dir/ImageRegistration6o.o
ImageRegistration8: CMakeFiles/ImageRegistration8.dir/build.make
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ImageRegistration8"
	$(CMAKE_COMMAND) -P CMakeFiles/ImageRegistration8.dir/cmake_clean_target.cmake
	/usr/bin/c++      -ftemplate-depth-50 -Wall  -fPIC   $(ImageRegistration8_OBJECTS) $(ImageRegistration8_EXTERNAL_OBJECTS)  -o ImageRegistration8 -rdynamic -L/usr/local/lib/InsightToolkit -lITKIO -lITKNumerics -lITKNrrdIO -litkgdcm -litkjpeg12 -litkjpeg16 -litkopenjpeg -litkpng -litktiff -litkjpeg8 -lITKSpatialObject -lITKMetaIO -lITKDICOMParser -lITKEXPAT -lITKniftiio -lITKznz -litkzlib -lITKCommon -litkvnl_inst -litkvnl_algo -litkv3p_netlib -litkvnl -litkvcl -lm -litksys -lpthread -ldl -lm -Wl,-rpath,/usr/local/lib/InsightToolkit 

# Rule to build all files generated by this target.
CMakeFiles/ImageRegistration8.dir/build: ImageRegistration8

CMakeFiles/ImageRegistration8.dir/requires: CMakeFiles/ImageRegistration8.dir/ImageRegistration6o.o.requires

CMakeFiles/ImageRegistration8.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ImageRegistration8.dir/cmake_clean.cmake
