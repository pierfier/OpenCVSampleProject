# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_SOURCE_DIR = /home/pierre/Robotics/OpenCV_Projects/OpenCVSampleProject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pierre/Robotics/OpenCV_Projects/OpenCVSampleProject/Build_Release

# Include any dependencies generated for this target.
include CMakeFiles/SampleProgram.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SampleProgram.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SampleProgram.dir/flags.make

CMakeFiles/SampleProgram.dir/main.cpp.o: CMakeFiles/SampleProgram.dir/flags.make
CMakeFiles/SampleProgram.dir/main.cpp.o: ../main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/pierre/Robotics/OpenCV_Projects/OpenCVSampleProject/Build_Release/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/SampleProgram.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/SampleProgram.dir/main.cpp.o -c /home/pierre/Robotics/OpenCV_Projects/OpenCVSampleProject/main.cpp

CMakeFiles/SampleProgram.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SampleProgram.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/pierre/Robotics/OpenCV_Projects/OpenCVSampleProject/main.cpp > CMakeFiles/SampleProgram.dir/main.cpp.i

CMakeFiles/SampleProgram.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SampleProgram.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/pierre/Robotics/OpenCV_Projects/OpenCVSampleProject/main.cpp -o CMakeFiles/SampleProgram.dir/main.cpp.s

CMakeFiles/SampleProgram.dir/main.cpp.o.requires:
.PHONY : CMakeFiles/SampleProgram.dir/main.cpp.o.requires

CMakeFiles/SampleProgram.dir/main.cpp.o.provides: CMakeFiles/SampleProgram.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/SampleProgram.dir/build.make CMakeFiles/SampleProgram.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/SampleProgram.dir/main.cpp.o.provides

CMakeFiles/SampleProgram.dir/main.cpp.o.provides.build: CMakeFiles/SampleProgram.dir/main.cpp.o

# Object files for target SampleProgram
SampleProgram_OBJECTS = \
"CMakeFiles/SampleProgram.dir/main.cpp.o"

# External object files for target SampleProgram
SampleProgram_EXTERNAL_OBJECTS =

SampleProgram: CMakeFiles/SampleProgram.dir/main.cpp.o
SampleProgram: CMakeFiles/SampleProgram.dir/build.make
SampleProgram: /usr/local/lib/libopencv_videostab.so.3.0.0
SampleProgram: /usr/local/lib/libopencv_video.so.3.0.0
SampleProgram: /usr/local/lib/libopencv_ts.a
SampleProgram: /usr/local/lib/libopencv_superres.so.3.0.0
SampleProgram: /usr/local/lib/libopencv_stitching.so.3.0.0
SampleProgram: /usr/local/lib/libopencv_softcascade.so.3.0.0
SampleProgram: /usr/local/lib/libopencv_shape.so.3.0.0
SampleProgram: /usr/local/lib/libopencv_photo.so.3.0.0
SampleProgram: /usr/local/lib/libopencv_optim.so.3.0.0
SampleProgram: /usr/local/lib/libopencv_ocl.so.3.0.0
SampleProgram: /usr/local/lib/libopencv_objdetect.so.3.0.0
SampleProgram: /usr/local/lib/libopencv_nonfree.so.3.0.0
SampleProgram: /usr/local/lib/libopencv_ml.so.3.0.0
SampleProgram: /usr/local/lib/libopencv_legacy.so.3.0.0
SampleProgram: /usr/local/lib/libopencv_imgproc.so.3.0.0
SampleProgram: /usr/local/lib/libopencv_highgui.so.3.0.0
SampleProgram: /usr/local/lib/libopencv_flann.so.3.0.0
SampleProgram: /usr/local/lib/libopencv_features2d.so.3.0.0
SampleProgram: /usr/local/lib/libopencv_cudawarping.so.3.0.0
SampleProgram: /usr/local/lib/libopencv_cudastereo.so.3.0.0
SampleProgram: /usr/local/lib/libopencv_cudaoptflow.so.3.0.0
SampleProgram: /usr/local/lib/libopencv_cudaimgproc.so.3.0.0
SampleProgram: /usr/local/lib/libopencv_cudafilters.so.3.0.0
SampleProgram: /usr/local/lib/libopencv_cudafeatures2d.so.3.0.0
SampleProgram: /usr/local/lib/libopencv_cudacodec.so.3.0.0
SampleProgram: /usr/local/lib/libopencv_cudabgsegm.so.3.0.0
SampleProgram: /usr/local/lib/libopencv_cudaarithm.so.3.0.0
SampleProgram: /usr/local/lib/libopencv_cuda.so.3.0.0
SampleProgram: /usr/local/lib/libopencv_core.so.3.0.0
SampleProgram: /usr/local/lib/libopencv_contrib.so.3.0.0
SampleProgram: /usr/local/lib/libopencv_calib3d.so.3.0.0
SampleProgram: /usr/local/lib/libopencv_bioinspired.so.3.0.0
SampleProgram: /usr/local/lib/libopencv_cudawarping.so.3.0.0
SampleProgram: /usr/local/lib/libopencv_legacy.so.3.0.0
SampleProgram: /usr/local/lib/libopencv_cudaimgproc.so.3.0.0
SampleProgram: /usr/local/lib/libopencv_cudafilters.so.3.0.0
SampleProgram: /usr/local/lib/libopencv_nonfree.so.3.0.0
SampleProgram: /usr/local/lib/libopencv_cudaarithm.so.3.0.0
SampleProgram: /usr/local/lib/libopencv_ocl.so.3.0.0
SampleProgram: /usr/local/lib/libopencv_video.so.3.0.0
SampleProgram: /usr/local/lib/libopencv_objdetect.so.3.0.0
SampleProgram: /usr/local/lib/libopencv_ml.so.3.0.0
SampleProgram: /usr/local/lib/libopencv_calib3d.so.3.0.0
SampleProgram: /usr/local/lib/libopencv_features2d.so.3.0.0
SampleProgram: /usr/local/lib/libopencv_highgui.so.3.0.0
SampleProgram: /usr/local/lib/libopencv_imgproc.so.3.0.0
SampleProgram: /usr/local/lib/libopencv_flann.so.3.0.0
SampleProgram: /usr/local/lib/libopencv_core.so.3.0.0
SampleProgram: CMakeFiles/SampleProgram.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable SampleProgram"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SampleProgram.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SampleProgram.dir/build: SampleProgram
.PHONY : CMakeFiles/SampleProgram.dir/build

CMakeFiles/SampleProgram.dir/requires: CMakeFiles/SampleProgram.dir/main.cpp.o.requires
.PHONY : CMakeFiles/SampleProgram.dir/requires

CMakeFiles/SampleProgram.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SampleProgram.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SampleProgram.dir/clean

CMakeFiles/SampleProgram.dir/depend:
	cd /home/pierre/Robotics/OpenCV_Projects/OpenCVSampleProject/Build_Release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pierre/Robotics/OpenCV_Projects/OpenCVSampleProject /home/pierre/Robotics/OpenCV_Projects/OpenCVSampleProject /home/pierre/Robotics/OpenCV_Projects/OpenCVSampleProject/Build_Release /home/pierre/Robotics/OpenCV_Projects/OpenCVSampleProject/Build_Release /home/pierre/Robotics/OpenCV_Projects/OpenCVSampleProject/Build_Release/CMakeFiles/SampleProgram.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SampleProgram.dir/depend

