# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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
CMAKE_SOURCE_DIR = /home/lichangheng/robo_ws/pytorch

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lichangheng/robo_ws/pytorch/build

# Include any dependencies generated for this target.
include binaries/CMakeFiles/make_cifar_db.dir/depend.make

# Include the progress variables for this target.
include binaries/CMakeFiles/make_cifar_db.dir/progress.make

# Include the compile flags for this target's objects.
include binaries/CMakeFiles/make_cifar_db.dir/flags.make

binaries/CMakeFiles/make_cifar_db.dir/make_cifar_db.cc.o: binaries/CMakeFiles/make_cifar_db.dir/flags.make
binaries/CMakeFiles/make_cifar_db.dir/make_cifar_db.cc.o: ../binaries/make_cifar_db.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lichangheng/robo_ws/pytorch/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object binaries/CMakeFiles/make_cifar_db.dir/make_cifar_db.cc.o"
	cd /home/lichangheng/robo_ws/pytorch/build/binaries && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/make_cifar_db.dir/make_cifar_db.cc.o -c /home/lichangheng/robo_ws/pytorch/binaries/make_cifar_db.cc

binaries/CMakeFiles/make_cifar_db.dir/make_cifar_db.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/make_cifar_db.dir/make_cifar_db.cc.i"
	cd /home/lichangheng/robo_ws/pytorch/build/binaries && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lichangheng/robo_ws/pytorch/binaries/make_cifar_db.cc > CMakeFiles/make_cifar_db.dir/make_cifar_db.cc.i

binaries/CMakeFiles/make_cifar_db.dir/make_cifar_db.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/make_cifar_db.dir/make_cifar_db.cc.s"
	cd /home/lichangheng/robo_ws/pytorch/build/binaries && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lichangheng/robo_ws/pytorch/binaries/make_cifar_db.cc -o CMakeFiles/make_cifar_db.dir/make_cifar_db.cc.s

binaries/CMakeFiles/make_cifar_db.dir/make_cifar_db.cc.o.requires:

.PHONY : binaries/CMakeFiles/make_cifar_db.dir/make_cifar_db.cc.o.requires

binaries/CMakeFiles/make_cifar_db.dir/make_cifar_db.cc.o.provides: binaries/CMakeFiles/make_cifar_db.dir/make_cifar_db.cc.o.requires
	$(MAKE) -f binaries/CMakeFiles/make_cifar_db.dir/build.make binaries/CMakeFiles/make_cifar_db.dir/make_cifar_db.cc.o.provides.build
.PHONY : binaries/CMakeFiles/make_cifar_db.dir/make_cifar_db.cc.o.provides

binaries/CMakeFiles/make_cifar_db.dir/make_cifar_db.cc.o.provides.build: binaries/CMakeFiles/make_cifar_db.dir/make_cifar_db.cc.o


# Object files for target make_cifar_db
make_cifar_db_OBJECTS = \
"CMakeFiles/make_cifar_db.dir/make_cifar_db.cc.o"

# External object files for target make_cifar_db
make_cifar_db_EXTERNAL_OBJECTS =

bin/make_cifar_db: binaries/CMakeFiles/make_cifar_db.dir/make_cifar_db.cc.o
bin/make_cifar_db: binaries/CMakeFiles/make_cifar_db.dir/build.make
bin/make_cifar_db: lib/libprotobuf.a
bin/make_cifar_db: lib/libc10.so
bin/make_cifar_db: binaries/CMakeFiles/make_cifar_db.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lichangheng/robo_ws/pytorch/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/make_cifar_db"
	cd /home/lichangheng/robo_ws/pytorch/build/binaries && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/make_cifar_db.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
binaries/CMakeFiles/make_cifar_db.dir/build: bin/make_cifar_db

.PHONY : binaries/CMakeFiles/make_cifar_db.dir/build

binaries/CMakeFiles/make_cifar_db.dir/requires: binaries/CMakeFiles/make_cifar_db.dir/make_cifar_db.cc.o.requires

.PHONY : binaries/CMakeFiles/make_cifar_db.dir/requires

binaries/CMakeFiles/make_cifar_db.dir/clean:
	cd /home/lichangheng/robo_ws/pytorch/build/binaries && $(CMAKE_COMMAND) -P CMakeFiles/make_cifar_db.dir/cmake_clean.cmake
.PHONY : binaries/CMakeFiles/make_cifar_db.dir/clean

binaries/CMakeFiles/make_cifar_db.dir/depend:
	cd /home/lichangheng/robo_ws/pytorch/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lichangheng/robo_ws/pytorch /home/lichangheng/robo_ws/pytorch/binaries /home/lichangheng/robo_ws/pytorch/build /home/lichangheng/robo_ws/pytorch/build/binaries /home/lichangheng/robo_ws/pytorch/build/binaries/CMakeFiles/make_cifar_db.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : binaries/CMakeFiles/make_cifar_db.dir/depend

