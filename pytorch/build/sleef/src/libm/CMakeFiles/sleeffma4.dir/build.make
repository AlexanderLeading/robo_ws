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
include sleef/src/libm/CMakeFiles/sleeffma4.dir/depend.make

# Include the progress variables for this target.
include sleef/src/libm/CMakeFiles/sleeffma4.dir/progress.make

# Include the compile flags for this target's objects.
include sleef/src/libm/CMakeFiles/sleeffma4.dir/flags.make

sleef/src/libm/include/renamefma4.h: sleef/bin/mkrename
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/lichangheng/robo_ws/pytorch/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating include/renamefma4.h"
	cd /home/lichangheng/robo_ws/pytorch/build/sleef/src/libm && echo Generating renamefma4.h: mkrename "4" "8" "fma4"
	cd /home/lichangheng/robo_ws/pytorch/build/sleef/src/libm && ../../bin/mkrename "4" "8" "fma4" > /home/lichangheng/robo_ws/pytorch/build/sleef/src/libm/include/renamefma4.h

sleef/src/libm/CMakeFiles/sleeffma4.dir/sleefsimdsp.c.o: sleef/src/libm/CMakeFiles/sleeffma4.dir/flags.make
sleef/src/libm/CMakeFiles/sleeffma4.dir/sleefsimdsp.c.o: ../third_party/sleef/src/libm/sleefsimdsp.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lichangheng/robo_ws/pytorch/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object sleef/src/libm/CMakeFiles/sleeffma4.dir/sleefsimdsp.c.o"
	cd /home/lichangheng/robo_ws/pytorch/build/sleef/src/libm && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sleeffma4.dir/sleefsimdsp.c.o   -c /home/lichangheng/robo_ws/pytorch/third_party/sleef/src/libm/sleefsimdsp.c

sleef/src/libm/CMakeFiles/sleeffma4.dir/sleefsimdsp.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sleeffma4.dir/sleefsimdsp.c.i"
	cd /home/lichangheng/robo_ws/pytorch/build/sleef/src/libm && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/lichangheng/robo_ws/pytorch/third_party/sleef/src/libm/sleefsimdsp.c > CMakeFiles/sleeffma4.dir/sleefsimdsp.c.i

sleef/src/libm/CMakeFiles/sleeffma4.dir/sleefsimdsp.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sleeffma4.dir/sleefsimdsp.c.s"
	cd /home/lichangheng/robo_ws/pytorch/build/sleef/src/libm && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/lichangheng/robo_ws/pytorch/third_party/sleef/src/libm/sleefsimdsp.c -o CMakeFiles/sleeffma4.dir/sleefsimdsp.c.s

sleef/src/libm/CMakeFiles/sleeffma4.dir/sleefsimdsp.c.o.requires:

.PHONY : sleef/src/libm/CMakeFiles/sleeffma4.dir/sleefsimdsp.c.o.requires

sleef/src/libm/CMakeFiles/sleeffma4.dir/sleefsimdsp.c.o.provides: sleef/src/libm/CMakeFiles/sleeffma4.dir/sleefsimdsp.c.o.requires
	$(MAKE) -f sleef/src/libm/CMakeFiles/sleeffma4.dir/build.make sleef/src/libm/CMakeFiles/sleeffma4.dir/sleefsimdsp.c.o.provides.build
.PHONY : sleef/src/libm/CMakeFiles/sleeffma4.dir/sleefsimdsp.c.o.provides

sleef/src/libm/CMakeFiles/sleeffma4.dir/sleefsimdsp.c.o.provides.build: sleef/src/libm/CMakeFiles/sleeffma4.dir/sleefsimdsp.c.o


sleef/src/libm/CMakeFiles/sleeffma4.dir/sleefsimddp.c.o: sleef/src/libm/CMakeFiles/sleeffma4.dir/flags.make
sleef/src/libm/CMakeFiles/sleeffma4.dir/sleefsimddp.c.o: ../third_party/sleef/src/libm/sleefsimddp.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lichangheng/robo_ws/pytorch/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object sleef/src/libm/CMakeFiles/sleeffma4.dir/sleefsimddp.c.o"
	cd /home/lichangheng/robo_ws/pytorch/build/sleef/src/libm && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sleeffma4.dir/sleefsimddp.c.o   -c /home/lichangheng/robo_ws/pytorch/third_party/sleef/src/libm/sleefsimddp.c

sleef/src/libm/CMakeFiles/sleeffma4.dir/sleefsimddp.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sleeffma4.dir/sleefsimddp.c.i"
	cd /home/lichangheng/robo_ws/pytorch/build/sleef/src/libm && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/lichangheng/robo_ws/pytorch/third_party/sleef/src/libm/sleefsimddp.c > CMakeFiles/sleeffma4.dir/sleefsimddp.c.i

sleef/src/libm/CMakeFiles/sleeffma4.dir/sleefsimddp.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sleeffma4.dir/sleefsimddp.c.s"
	cd /home/lichangheng/robo_ws/pytorch/build/sleef/src/libm && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/lichangheng/robo_ws/pytorch/third_party/sleef/src/libm/sleefsimddp.c -o CMakeFiles/sleeffma4.dir/sleefsimddp.c.s

sleef/src/libm/CMakeFiles/sleeffma4.dir/sleefsimddp.c.o.requires:

.PHONY : sleef/src/libm/CMakeFiles/sleeffma4.dir/sleefsimddp.c.o.requires

sleef/src/libm/CMakeFiles/sleeffma4.dir/sleefsimddp.c.o.provides: sleef/src/libm/CMakeFiles/sleeffma4.dir/sleefsimddp.c.o.requires
	$(MAKE) -f sleef/src/libm/CMakeFiles/sleeffma4.dir/build.make sleef/src/libm/CMakeFiles/sleeffma4.dir/sleefsimddp.c.o.provides.build
.PHONY : sleef/src/libm/CMakeFiles/sleeffma4.dir/sleefsimddp.c.o.provides

sleef/src/libm/CMakeFiles/sleeffma4.dir/sleefsimddp.c.o.provides.build: sleef/src/libm/CMakeFiles/sleeffma4.dir/sleefsimddp.c.o


sleeffma4: sleef/src/libm/CMakeFiles/sleeffma4.dir/sleefsimdsp.c.o
sleeffma4: sleef/src/libm/CMakeFiles/sleeffma4.dir/sleefsimddp.c.o
sleeffma4: sleef/src/libm/CMakeFiles/sleeffma4.dir/build.make

.PHONY : sleeffma4

# Rule to build all files generated by this target.
sleef/src/libm/CMakeFiles/sleeffma4.dir/build: sleeffma4

.PHONY : sleef/src/libm/CMakeFiles/sleeffma4.dir/build

sleef/src/libm/CMakeFiles/sleeffma4.dir/requires: sleef/src/libm/CMakeFiles/sleeffma4.dir/sleefsimdsp.c.o.requires
sleef/src/libm/CMakeFiles/sleeffma4.dir/requires: sleef/src/libm/CMakeFiles/sleeffma4.dir/sleefsimddp.c.o.requires

.PHONY : sleef/src/libm/CMakeFiles/sleeffma4.dir/requires

sleef/src/libm/CMakeFiles/sleeffma4.dir/clean:
	cd /home/lichangheng/robo_ws/pytorch/build/sleef/src/libm && $(CMAKE_COMMAND) -P CMakeFiles/sleeffma4.dir/cmake_clean.cmake
.PHONY : sleef/src/libm/CMakeFiles/sleeffma4.dir/clean

sleef/src/libm/CMakeFiles/sleeffma4.dir/depend: sleef/src/libm/include/renamefma4.h
	cd /home/lichangheng/robo_ws/pytorch/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lichangheng/robo_ws/pytorch /home/lichangheng/robo_ws/pytorch/third_party/sleef/src/libm /home/lichangheng/robo_ws/pytorch/build /home/lichangheng/robo_ws/pytorch/build/sleef/src/libm /home/lichangheng/robo_ws/pytorch/build/sleef/src/libm/CMakeFiles/sleeffma4.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : sleef/src/libm/CMakeFiles/sleeffma4.dir/depend

