# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.6

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canoncical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

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
CMAKE_SOURCE_DIR = /home/matsui/git/mycode/jacknero/src/c++/Boost/filesystem

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/matsui/git/mycode/jacknero/src/c++/Boost/filesystem

# Include any dependencies generated for this target.
include CMakeFiles/ImageReadWrite.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ImageReadWrite.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ImageReadWrite.dir/flags.make

CMakeFiles/ImageReadWrite.dir/test.cpp.o: CMakeFiles/ImageReadWrite.dir/flags.make
CMakeFiles/ImageReadWrite.dir/test.cpp.o: test.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/matsui/git/mycode/jacknero/src/c++/Boost/filesystem/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/ImageReadWrite.dir/test.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/ImageReadWrite.dir/test.cpp.o -c /home/matsui/git/mycode/jacknero/src/c++/Boost/filesystem/test.cpp

CMakeFiles/ImageReadWrite.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ImageReadWrite.dir/test.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/matsui/git/mycode/jacknero/src/c++/Boost/filesystem/test.cpp > CMakeFiles/ImageReadWrite.dir/test.cpp.i

CMakeFiles/ImageReadWrite.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ImageReadWrite.dir/test.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/matsui/git/mycode/jacknero/src/c++/Boost/filesystem/test.cpp -o CMakeFiles/ImageReadWrite.dir/test.cpp.s

CMakeFiles/ImageReadWrite.dir/test.cpp.o.requires:
.PHONY : CMakeFiles/ImageReadWrite.dir/test.cpp.o.requires

CMakeFiles/ImageReadWrite.dir/test.cpp.o.provides: CMakeFiles/ImageReadWrite.dir/test.cpp.o.requires
	$(MAKE) -f CMakeFiles/ImageReadWrite.dir/build.make CMakeFiles/ImageReadWrite.dir/test.cpp.o.provides.build
.PHONY : CMakeFiles/ImageReadWrite.dir/test.cpp.o.provides

CMakeFiles/ImageReadWrite.dir/test.cpp.o.provides.build: CMakeFiles/ImageReadWrite.dir/test.cpp.o
.PHONY : CMakeFiles/ImageReadWrite.dir/test.cpp.o.provides.build

# Object files for target ImageReadWrite
ImageReadWrite_OBJECTS = \
"CMakeFiles/ImageReadWrite.dir/test.cpp.o"

# External object files for target ImageReadWrite
ImageReadWrite_EXTERNAL_OBJECTS =

ImageReadWrite: CMakeFiles/ImageReadWrite.dir/test.cpp.o
ImageReadWrite: /usr/lib/libboost_filesystem-gcc43-mt-1_35.so
ImageReadWrite: CMakeFiles/ImageReadWrite.dir/build.make
ImageReadWrite: CMakeFiles/ImageReadWrite.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ImageReadWrite"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ImageReadWrite.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ImageReadWrite.dir/build: ImageReadWrite
.PHONY : CMakeFiles/ImageReadWrite.dir/build

CMakeFiles/ImageReadWrite.dir/requires: CMakeFiles/ImageReadWrite.dir/test.cpp.o.requires
.PHONY : CMakeFiles/ImageReadWrite.dir/requires

CMakeFiles/ImageReadWrite.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ImageReadWrite.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ImageReadWrite.dir/clean

CMakeFiles/ImageReadWrite.dir/depend:
	cd /home/matsui/git/mycode/jacknero/src/c++/Boost/filesystem && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/matsui/git/mycode/jacknero/src/c++/Boost/filesystem /home/matsui/git/mycode/jacknero/src/c++/Boost/filesystem /home/matsui/git/mycode/jacknero/src/c++/Boost/filesystem /home/matsui/git/mycode/jacknero/src/c++/Boost/filesystem /home/matsui/git/mycode/jacknero/src/c++/Boost/filesystem/CMakeFiles/ImageReadWrite.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ImageReadWrite.dir/depend

