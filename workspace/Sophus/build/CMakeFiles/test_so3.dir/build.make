# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.2

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Produce verbose output by default.
VERBOSE = 1

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

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/cwu/Experiment/SVO/workspace/Sophus

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cwu/Experiment/SVO/workspace/Sophus/build

# Include any dependencies generated for this target.
include CMakeFiles/test_so3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test_so3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_so3.dir/flags.make

CMakeFiles/test_so3.dir/sophus/test_so3.cpp.o: CMakeFiles/test_so3.dir/flags.make
CMakeFiles/test_so3.dir/sophus/test_so3.cpp.o: ../sophus/test_so3.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/cwu/Experiment/SVO/workspace/Sophus/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/test_so3.dir/sophus/test_so3.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/test_so3.dir/sophus/test_so3.cpp.o -c /home/cwu/Experiment/SVO/workspace/Sophus/sophus/test_so3.cpp

CMakeFiles/test_so3.dir/sophus/test_so3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_so3.dir/sophus/test_so3.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/cwu/Experiment/SVO/workspace/Sophus/sophus/test_so3.cpp > CMakeFiles/test_so3.dir/sophus/test_so3.cpp.i

CMakeFiles/test_so3.dir/sophus/test_so3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_so3.dir/sophus/test_so3.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/cwu/Experiment/SVO/workspace/Sophus/sophus/test_so3.cpp -o CMakeFiles/test_so3.dir/sophus/test_so3.cpp.s

CMakeFiles/test_so3.dir/sophus/test_so3.cpp.o.requires:
.PHONY : CMakeFiles/test_so3.dir/sophus/test_so3.cpp.o.requires

CMakeFiles/test_so3.dir/sophus/test_so3.cpp.o.provides: CMakeFiles/test_so3.dir/sophus/test_so3.cpp.o.requires
	$(MAKE) -f CMakeFiles/test_so3.dir/build.make CMakeFiles/test_so3.dir/sophus/test_so3.cpp.o.provides.build
.PHONY : CMakeFiles/test_so3.dir/sophus/test_so3.cpp.o.provides

CMakeFiles/test_so3.dir/sophus/test_so3.cpp.o.provides.build: CMakeFiles/test_so3.dir/sophus/test_so3.cpp.o

# Object files for target test_so3
test_so3_OBJECTS = \
"CMakeFiles/test_so3.dir/sophus/test_so3.cpp.o"

# External object files for target test_so3
test_so3_EXTERNAL_OBJECTS =

test_so3: CMakeFiles/test_so3.dir/sophus/test_so3.cpp.o
test_so3: CMakeFiles/test_so3.dir/build.make
test_so3: libSophus.so
test_so3: CMakeFiles/test_so3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable test_so3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_so3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_so3.dir/build: test_so3
.PHONY : CMakeFiles/test_so3.dir/build

CMakeFiles/test_so3.dir/requires: CMakeFiles/test_so3.dir/sophus/test_so3.cpp.o.requires
.PHONY : CMakeFiles/test_so3.dir/requires

CMakeFiles/test_so3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_so3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_so3.dir/clean

CMakeFiles/test_so3.dir/depend:
	cd /home/cwu/Experiment/SVO/workspace/Sophus/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cwu/Experiment/SVO/workspace/Sophus /home/cwu/Experiment/SVO/workspace/Sophus /home/cwu/Experiment/SVO/workspace/Sophus/build /home/cwu/Experiment/SVO/workspace/Sophus/build /home/cwu/Experiment/SVO/workspace/Sophus/build/CMakeFiles/test_so3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_so3.dir/depend

