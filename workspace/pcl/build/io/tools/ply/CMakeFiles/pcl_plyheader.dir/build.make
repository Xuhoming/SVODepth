# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.2

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
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

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/cwu/Experiment/SVO/workspace/pcl

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cwu/Experiment/SVO/workspace/pcl/build

# Include any dependencies generated for this target.
include io/tools/ply/CMakeFiles/pcl_plyheader.dir/depend.make

# Include the progress variables for this target.
include io/tools/ply/CMakeFiles/pcl_plyheader.dir/progress.make

# Include the compile flags for this target's objects.
include io/tools/ply/CMakeFiles/pcl_plyheader.dir/flags.make

io/tools/ply/CMakeFiles/pcl_plyheader.dir/plyheader.cpp.o: io/tools/ply/CMakeFiles/pcl_plyheader.dir/flags.make
io/tools/ply/CMakeFiles/pcl_plyheader.dir/plyheader.cpp.o: ../io/tools/ply/plyheader.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/cwu/Experiment/SVO/workspace/pcl/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object io/tools/ply/CMakeFiles/pcl_plyheader.dir/plyheader.cpp.o"
	cd /home/cwu/Experiment/SVO/workspace/pcl/build/io/tools/ply && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/pcl_plyheader.dir/plyheader.cpp.o -c /home/cwu/Experiment/SVO/workspace/pcl/io/tools/ply/plyheader.cpp

io/tools/ply/CMakeFiles/pcl_plyheader.dir/plyheader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pcl_plyheader.dir/plyheader.cpp.i"
	cd /home/cwu/Experiment/SVO/workspace/pcl/build/io/tools/ply && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/cwu/Experiment/SVO/workspace/pcl/io/tools/ply/plyheader.cpp > CMakeFiles/pcl_plyheader.dir/plyheader.cpp.i

io/tools/ply/CMakeFiles/pcl_plyheader.dir/plyheader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pcl_plyheader.dir/plyheader.cpp.s"
	cd /home/cwu/Experiment/SVO/workspace/pcl/build/io/tools/ply && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/cwu/Experiment/SVO/workspace/pcl/io/tools/ply/plyheader.cpp -o CMakeFiles/pcl_plyheader.dir/plyheader.cpp.s

io/tools/ply/CMakeFiles/pcl_plyheader.dir/plyheader.cpp.o.requires:
.PHONY : io/tools/ply/CMakeFiles/pcl_plyheader.dir/plyheader.cpp.o.requires

io/tools/ply/CMakeFiles/pcl_plyheader.dir/plyheader.cpp.o.provides: io/tools/ply/CMakeFiles/pcl_plyheader.dir/plyheader.cpp.o.requires
	$(MAKE) -f io/tools/ply/CMakeFiles/pcl_plyheader.dir/build.make io/tools/ply/CMakeFiles/pcl_plyheader.dir/plyheader.cpp.o.provides.build
.PHONY : io/tools/ply/CMakeFiles/pcl_plyheader.dir/plyheader.cpp.o.provides

io/tools/ply/CMakeFiles/pcl_plyheader.dir/plyheader.cpp.o.provides.build: io/tools/ply/CMakeFiles/pcl_plyheader.dir/plyheader.cpp.o

# Object files for target pcl_plyheader
pcl_plyheader_OBJECTS = \
"CMakeFiles/pcl_plyheader.dir/plyheader.cpp.o"

# External object files for target pcl_plyheader
pcl_plyheader_EXTERNAL_OBJECTS =

bin/pcl_plyheader: io/tools/ply/CMakeFiles/pcl_plyheader.dir/plyheader.cpp.o
bin/pcl_plyheader: io/tools/ply/CMakeFiles/pcl_plyheader.dir/build.make
bin/pcl_plyheader: /usr/lib/x86_64-linux-gnu/libboost_system.so
bin/pcl_plyheader: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
bin/pcl_plyheader: /usr/lib/x86_64-linux-gnu/libboost_thread.so
bin/pcl_plyheader: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
bin/pcl_plyheader: /usr/lib/x86_64-linux-gnu/libboost_iostreams.so
bin/pcl_plyheader: /usr/lib/x86_64-linux-gnu/libpthread.so
bin/pcl_plyheader: lib/libpcl_io_ply.so.1.8.0
bin/pcl_plyheader: /usr/lib/x86_64-linux-gnu/libboost_system.so
bin/pcl_plyheader: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
bin/pcl_plyheader: /usr/lib/x86_64-linux-gnu/libboost_thread.so
bin/pcl_plyheader: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
bin/pcl_plyheader: /usr/lib/x86_64-linux-gnu/libboost_iostreams.so
bin/pcl_plyheader: /usr/lib/x86_64-linux-gnu/libpthread.so
bin/pcl_plyheader: io/tools/ply/CMakeFiles/pcl_plyheader.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../../../bin/pcl_plyheader"
	cd /home/cwu/Experiment/SVO/workspace/pcl/build/io/tools/ply && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pcl_plyheader.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
io/tools/ply/CMakeFiles/pcl_plyheader.dir/build: bin/pcl_plyheader
.PHONY : io/tools/ply/CMakeFiles/pcl_plyheader.dir/build

io/tools/ply/CMakeFiles/pcl_plyheader.dir/requires: io/tools/ply/CMakeFiles/pcl_plyheader.dir/plyheader.cpp.o.requires
.PHONY : io/tools/ply/CMakeFiles/pcl_plyheader.dir/requires

io/tools/ply/CMakeFiles/pcl_plyheader.dir/clean:
	cd /home/cwu/Experiment/SVO/workspace/pcl/build/io/tools/ply && $(CMAKE_COMMAND) -P CMakeFiles/pcl_plyheader.dir/cmake_clean.cmake
.PHONY : io/tools/ply/CMakeFiles/pcl_plyheader.dir/clean

io/tools/ply/CMakeFiles/pcl_plyheader.dir/depend:
	cd /home/cwu/Experiment/SVO/workspace/pcl/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cwu/Experiment/SVO/workspace/pcl /home/cwu/Experiment/SVO/workspace/pcl/io/tools/ply /home/cwu/Experiment/SVO/workspace/pcl/build /home/cwu/Experiment/SVO/workspace/pcl/build/io/tools/ply /home/cwu/Experiment/SVO/workspace/pcl/build/io/tools/ply/CMakeFiles/pcl_plyheader.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : io/tools/ply/CMakeFiles/pcl_plyheader.dir/depend
