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
include caffe2/perfkernels/CMakeFiles/Caffe2_perfkernels_avx.dir/depend.make

# Include the progress variables for this target.
include caffe2/perfkernels/CMakeFiles/Caffe2_perfkernels_avx.dir/progress.make

# Include the compile flags for this target's objects.
include caffe2/perfkernels/CMakeFiles/Caffe2_perfkernels_avx.dir/flags.make

caffe2/perfkernels/CMakeFiles/Caffe2_perfkernels_avx.dir/common_avx.cc.o: caffe2/perfkernels/CMakeFiles/Caffe2_perfkernels_avx.dir/flags.make
caffe2/perfkernels/CMakeFiles/Caffe2_perfkernels_avx.dir/common_avx.cc.o: ../caffe2/perfkernels/common_avx.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lichangheng/robo_ws/pytorch/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object caffe2/perfkernels/CMakeFiles/Caffe2_perfkernels_avx.dir/common_avx.cc.o"
	cd /home/lichangheng/robo_ws/pytorch/build/caffe2/perfkernels && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Caffe2_perfkernels_avx.dir/common_avx.cc.o -c /home/lichangheng/robo_ws/pytorch/caffe2/perfkernels/common_avx.cc

caffe2/perfkernels/CMakeFiles/Caffe2_perfkernels_avx.dir/common_avx.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Caffe2_perfkernels_avx.dir/common_avx.cc.i"
	cd /home/lichangheng/robo_ws/pytorch/build/caffe2/perfkernels && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lichangheng/robo_ws/pytorch/caffe2/perfkernels/common_avx.cc > CMakeFiles/Caffe2_perfkernels_avx.dir/common_avx.cc.i

caffe2/perfkernels/CMakeFiles/Caffe2_perfkernels_avx.dir/common_avx.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Caffe2_perfkernels_avx.dir/common_avx.cc.s"
	cd /home/lichangheng/robo_ws/pytorch/build/caffe2/perfkernels && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lichangheng/robo_ws/pytorch/caffe2/perfkernels/common_avx.cc -o CMakeFiles/Caffe2_perfkernels_avx.dir/common_avx.cc.s

caffe2/perfkernels/CMakeFiles/Caffe2_perfkernels_avx.dir/common_avx.cc.o.requires:

.PHONY : caffe2/perfkernels/CMakeFiles/Caffe2_perfkernels_avx.dir/common_avx.cc.o.requires

caffe2/perfkernels/CMakeFiles/Caffe2_perfkernels_avx.dir/common_avx.cc.o.provides: caffe2/perfkernels/CMakeFiles/Caffe2_perfkernels_avx.dir/common_avx.cc.o.requires
	$(MAKE) -f caffe2/perfkernels/CMakeFiles/Caffe2_perfkernels_avx.dir/build.make caffe2/perfkernels/CMakeFiles/Caffe2_perfkernels_avx.dir/common_avx.cc.o.provides.build
.PHONY : caffe2/perfkernels/CMakeFiles/Caffe2_perfkernels_avx.dir/common_avx.cc.o.provides

caffe2/perfkernels/CMakeFiles/Caffe2_perfkernels_avx.dir/common_avx.cc.o.provides.build: caffe2/perfkernels/CMakeFiles/Caffe2_perfkernels_avx.dir/common_avx.cc.o


caffe2/perfkernels/CMakeFiles/Caffe2_perfkernels_avx.dir/typed_axpy_avx.cc.o: caffe2/perfkernels/CMakeFiles/Caffe2_perfkernels_avx.dir/flags.make
caffe2/perfkernels/CMakeFiles/Caffe2_perfkernels_avx.dir/typed_axpy_avx.cc.o: ../caffe2/perfkernels/typed_axpy_avx.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lichangheng/robo_ws/pytorch/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object caffe2/perfkernels/CMakeFiles/Caffe2_perfkernels_avx.dir/typed_axpy_avx.cc.o"
	cd /home/lichangheng/robo_ws/pytorch/build/caffe2/perfkernels && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Caffe2_perfkernels_avx.dir/typed_axpy_avx.cc.o -c /home/lichangheng/robo_ws/pytorch/caffe2/perfkernels/typed_axpy_avx.cc

caffe2/perfkernels/CMakeFiles/Caffe2_perfkernels_avx.dir/typed_axpy_avx.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Caffe2_perfkernels_avx.dir/typed_axpy_avx.cc.i"
	cd /home/lichangheng/robo_ws/pytorch/build/caffe2/perfkernels && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lichangheng/robo_ws/pytorch/caffe2/perfkernels/typed_axpy_avx.cc > CMakeFiles/Caffe2_perfkernels_avx.dir/typed_axpy_avx.cc.i

caffe2/perfkernels/CMakeFiles/Caffe2_perfkernels_avx.dir/typed_axpy_avx.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Caffe2_perfkernels_avx.dir/typed_axpy_avx.cc.s"
	cd /home/lichangheng/robo_ws/pytorch/build/caffe2/perfkernels && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lichangheng/robo_ws/pytorch/caffe2/perfkernels/typed_axpy_avx.cc -o CMakeFiles/Caffe2_perfkernels_avx.dir/typed_axpy_avx.cc.s

caffe2/perfkernels/CMakeFiles/Caffe2_perfkernels_avx.dir/typed_axpy_avx.cc.o.requires:

.PHONY : caffe2/perfkernels/CMakeFiles/Caffe2_perfkernels_avx.dir/typed_axpy_avx.cc.o.requires

caffe2/perfkernels/CMakeFiles/Caffe2_perfkernels_avx.dir/typed_axpy_avx.cc.o.provides: caffe2/perfkernels/CMakeFiles/Caffe2_perfkernels_avx.dir/typed_axpy_avx.cc.o.requires
	$(MAKE) -f caffe2/perfkernels/CMakeFiles/Caffe2_perfkernels_avx.dir/build.make caffe2/perfkernels/CMakeFiles/Caffe2_perfkernels_avx.dir/typed_axpy_avx.cc.o.provides.build
.PHONY : caffe2/perfkernels/CMakeFiles/Caffe2_perfkernels_avx.dir/typed_axpy_avx.cc.o.provides

caffe2/perfkernels/CMakeFiles/Caffe2_perfkernels_avx.dir/typed_axpy_avx.cc.o.provides.build: caffe2/perfkernels/CMakeFiles/Caffe2_perfkernels_avx.dir/typed_axpy_avx.cc.o


caffe2/perfkernels/CMakeFiles/Caffe2_perfkernels_avx.dir/adagrad_avx.cc.o: caffe2/perfkernels/CMakeFiles/Caffe2_perfkernels_avx.dir/flags.make
caffe2/perfkernels/CMakeFiles/Caffe2_perfkernels_avx.dir/adagrad_avx.cc.o: ../caffe2/perfkernels/adagrad_avx.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lichangheng/robo_ws/pytorch/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object caffe2/perfkernels/CMakeFiles/Caffe2_perfkernels_avx.dir/adagrad_avx.cc.o"
	cd /home/lichangheng/robo_ws/pytorch/build/caffe2/perfkernels && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Caffe2_perfkernels_avx.dir/adagrad_avx.cc.o -c /home/lichangheng/robo_ws/pytorch/caffe2/perfkernels/adagrad_avx.cc

caffe2/perfkernels/CMakeFiles/Caffe2_perfkernels_avx.dir/adagrad_avx.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Caffe2_perfkernels_avx.dir/adagrad_avx.cc.i"
	cd /home/lichangheng/robo_ws/pytorch/build/caffe2/perfkernels && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lichangheng/robo_ws/pytorch/caffe2/perfkernels/adagrad_avx.cc > CMakeFiles/Caffe2_perfkernels_avx.dir/adagrad_avx.cc.i

caffe2/perfkernels/CMakeFiles/Caffe2_perfkernels_avx.dir/adagrad_avx.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Caffe2_perfkernels_avx.dir/adagrad_avx.cc.s"
	cd /home/lichangheng/robo_ws/pytorch/build/caffe2/perfkernels && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lichangheng/robo_ws/pytorch/caffe2/perfkernels/adagrad_avx.cc -o CMakeFiles/Caffe2_perfkernels_avx.dir/adagrad_avx.cc.s

caffe2/perfkernels/CMakeFiles/Caffe2_perfkernels_avx.dir/adagrad_avx.cc.o.requires:

.PHONY : caffe2/perfkernels/CMakeFiles/Caffe2_perfkernels_avx.dir/adagrad_avx.cc.o.requires

caffe2/perfkernels/CMakeFiles/Caffe2_perfkernels_avx.dir/adagrad_avx.cc.o.provides: caffe2/perfkernels/CMakeFiles/Caffe2_perfkernels_avx.dir/adagrad_avx.cc.o.requires
	$(MAKE) -f caffe2/perfkernels/CMakeFiles/Caffe2_perfkernels_avx.dir/build.make caffe2/perfkernels/CMakeFiles/Caffe2_perfkernels_avx.dir/adagrad_avx.cc.o.provides.build
.PHONY : caffe2/perfkernels/CMakeFiles/Caffe2_perfkernels_avx.dir/adagrad_avx.cc.o.provides

caffe2/perfkernels/CMakeFiles/Caffe2_perfkernels_avx.dir/adagrad_avx.cc.o.provides.build: caffe2/perfkernels/CMakeFiles/Caffe2_perfkernels_avx.dir/adagrad_avx.cc.o


# Object files for target Caffe2_perfkernels_avx
Caffe2_perfkernels_avx_OBJECTS = \
"CMakeFiles/Caffe2_perfkernels_avx.dir/common_avx.cc.o" \
"CMakeFiles/Caffe2_perfkernels_avx.dir/typed_axpy_avx.cc.o" \
"CMakeFiles/Caffe2_perfkernels_avx.dir/adagrad_avx.cc.o"

# External object files for target Caffe2_perfkernels_avx
Caffe2_perfkernels_avx_EXTERNAL_OBJECTS =

lib/libCaffe2_perfkernels_avx.a: caffe2/perfkernels/CMakeFiles/Caffe2_perfkernels_avx.dir/common_avx.cc.o
lib/libCaffe2_perfkernels_avx.a: caffe2/perfkernels/CMakeFiles/Caffe2_perfkernels_avx.dir/typed_axpy_avx.cc.o
lib/libCaffe2_perfkernels_avx.a: caffe2/perfkernels/CMakeFiles/Caffe2_perfkernels_avx.dir/adagrad_avx.cc.o
lib/libCaffe2_perfkernels_avx.a: caffe2/perfkernels/CMakeFiles/Caffe2_perfkernels_avx.dir/build.make
lib/libCaffe2_perfkernels_avx.a: caffe2/perfkernels/CMakeFiles/Caffe2_perfkernels_avx.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lichangheng/robo_ws/pytorch/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library ../../lib/libCaffe2_perfkernels_avx.a"
	cd /home/lichangheng/robo_ws/pytorch/build/caffe2/perfkernels && $(CMAKE_COMMAND) -P CMakeFiles/Caffe2_perfkernels_avx.dir/cmake_clean_target.cmake
	cd /home/lichangheng/robo_ws/pytorch/build/caffe2/perfkernels && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Caffe2_perfkernels_avx.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
caffe2/perfkernels/CMakeFiles/Caffe2_perfkernels_avx.dir/build: lib/libCaffe2_perfkernels_avx.a

.PHONY : caffe2/perfkernels/CMakeFiles/Caffe2_perfkernels_avx.dir/build

caffe2/perfkernels/CMakeFiles/Caffe2_perfkernels_avx.dir/requires: caffe2/perfkernels/CMakeFiles/Caffe2_perfkernels_avx.dir/common_avx.cc.o.requires
caffe2/perfkernels/CMakeFiles/Caffe2_perfkernels_avx.dir/requires: caffe2/perfkernels/CMakeFiles/Caffe2_perfkernels_avx.dir/typed_axpy_avx.cc.o.requires
caffe2/perfkernels/CMakeFiles/Caffe2_perfkernels_avx.dir/requires: caffe2/perfkernels/CMakeFiles/Caffe2_perfkernels_avx.dir/adagrad_avx.cc.o.requires

.PHONY : caffe2/perfkernels/CMakeFiles/Caffe2_perfkernels_avx.dir/requires

caffe2/perfkernels/CMakeFiles/Caffe2_perfkernels_avx.dir/clean:
	cd /home/lichangheng/robo_ws/pytorch/build/caffe2/perfkernels && $(CMAKE_COMMAND) -P CMakeFiles/Caffe2_perfkernels_avx.dir/cmake_clean.cmake
.PHONY : caffe2/perfkernels/CMakeFiles/Caffe2_perfkernels_avx.dir/clean

caffe2/perfkernels/CMakeFiles/Caffe2_perfkernels_avx.dir/depend:
	cd /home/lichangheng/robo_ws/pytorch/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lichangheng/robo_ws/pytorch /home/lichangheng/robo_ws/pytorch/caffe2/perfkernels /home/lichangheng/robo_ws/pytorch/build /home/lichangheng/robo_ws/pytorch/build/caffe2/perfkernels /home/lichangheng/robo_ws/pytorch/build/caffe2/perfkernels/CMakeFiles/Caffe2_perfkernels_avx.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : caffe2/perfkernels/CMakeFiles/Caffe2_perfkernels_avx.dir/depend

