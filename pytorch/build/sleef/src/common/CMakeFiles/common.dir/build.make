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
include sleef/src/common/CMakeFiles/common.dir/depend.make

# Include the progress variables for this target.
include sleef/src/common/CMakeFiles/common.dir/progress.make

# Include the compile flags for this target's objects.
include sleef/src/common/CMakeFiles/common.dir/flags.make

sleef/src/common/CMakeFiles/common.dir/common.c.o: sleef/src/common/CMakeFiles/common.dir/flags.make
sleef/src/common/CMakeFiles/common.dir/common.c.o: ../third_party/sleef/src/common/common.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lichangheng/robo_ws/pytorch/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object sleef/src/common/CMakeFiles/common.dir/common.c.o"
	cd /home/lichangheng/robo_ws/pytorch/build/sleef/src/common && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/common.dir/common.c.o   -c /home/lichangheng/robo_ws/pytorch/third_party/sleef/src/common/common.c

sleef/src/common/CMakeFiles/common.dir/common.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/common.dir/common.c.i"
	cd /home/lichangheng/robo_ws/pytorch/build/sleef/src/common && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/lichangheng/robo_ws/pytorch/third_party/sleef/src/common/common.c > CMakeFiles/common.dir/common.c.i

sleef/src/common/CMakeFiles/common.dir/common.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/common.dir/common.c.s"
	cd /home/lichangheng/robo_ws/pytorch/build/sleef/src/common && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/lichangheng/robo_ws/pytorch/third_party/sleef/src/common/common.c -o CMakeFiles/common.dir/common.c.s

sleef/src/common/CMakeFiles/common.dir/common.c.o.requires:

.PHONY : sleef/src/common/CMakeFiles/common.dir/common.c.o.requires

sleef/src/common/CMakeFiles/common.dir/common.c.o.provides: sleef/src/common/CMakeFiles/common.dir/common.c.o.requires
	$(MAKE) -f sleef/src/common/CMakeFiles/common.dir/build.make sleef/src/common/CMakeFiles/common.dir/common.c.o.provides.build
.PHONY : sleef/src/common/CMakeFiles/common.dir/common.c.o.provides

sleef/src/common/CMakeFiles/common.dir/common.c.o.provides.build: sleef/src/common/CMakeFiles/common.dir/common.c.o


common: sleef/src/common/CMakeFiles/common.dir/common.c.o
common: sleef/src/common/CMakeFiles/common.dir/build.make

.PHONY : common

# Rule to build all files generated by this target.
sleef/src/common/CMakeFiles/common.dir/build: common

.PHONY : sleef/src/common/CMakeFiles/common.dir/build

sleef/src/common/CMakeFiles/common.dir/requires: sleef/src/common/CMakeFiles/common.dir/common.c.o.requires

.PHONY : sleef/src/common/CMakeFiles/common.dir/requires

sleef/src/common/CMakeFiles/common.dir/clean:
	cd /home/lichangheng/robo_ws/pytorch/build/sleef/src/common && $(CMAKE_COMMAND) -P CMakeFiles/common.dir/cmake_clean.cmake
.PHONY : sleef/src/common/CMakeFiles/common.dir/clean

sleef/src/common/CMakeFiles/common.dir/depend:
	cd /home/lichangheng/robo_ws/pytorch/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lichangheng/robo_ws/pytorch /home/lichangheng/robo_ws/pytorch/third_party/sleef/src/common /home/lichangheng/robo_ws/pytorch/build /home/lichangheng/robo_ws/pytorch/build/sleef/src/common /home/lichangheng/robo_ws/pytorch/build/sleef/src/common/CMakeFiles/common.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : sleef/src/common/CMakeFiles/common.dir/depend

