# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/harun/Desktop/lessons/391/libceng391

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/harun/Desktop/lessons/391/libceng391

# Include any dependencies generated for this target.
include app/CMakeFiles/image-test.dir/depend.make

# Include the progress variables for this target.
include app/CMakeFiles/image-test.dir/progress.make

# Include the compile flags for this target's objects.
include app/CMakeFiles/image-test.dir/flags.make

app/CMakeFiles/image-test.dir/image_test.cpp.o: app/CMakeFiles/image-test.dir/flags.make
app/CMakeFiles/image-test.dir/image_test.cpp.o: app/image_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/harun/Desktop/lessons/391/libceng391/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object app/CMakeFiles/image-test.dir/image_test.cpp.o"
	cd /home/harun/Desktop/lessons/391/libceng391/app && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/image-test.dir/image_test.cpp.o -c /home/harun/Desktop/lessons/391/libceng391/app/image_test.cpp

app/CMakeFiles/image-test.dir/image_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/image-test.dir/image_test.cpp.i"
	cd /home/harun/Desktop/lessons/391/libceng391/app && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/harun/Desktop/lessons/391/libceng391/app/image_test.cpp > CMakeFiles/image-test.dir/image_test.cpp.i

app/CMakeFiles/image-test.dir/image_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/image-test.dir/image_test.cpp.s"
	cd /home/harun/Desktop/lessons/391/libceng391/app && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/harun/Desktop/lessons/391/libceng391/app/image_test.cpp -o CMakeFiles/image-test.dir/image_test.cpp.s

# Object files for target image-test
image__test_OBJECTS = \
"CMakeFiles/image-test.dir/image_test.cpp.o"

# External object files for target image-test
image__test_EXTERNAL_OBJECTS =

app/image-test: app/CMakeFiles/image-test.dir/image_test.cpp.o
app/image-test: app/CMakeFiles/image-test.dir/build.make
app/image-test: src/libceng391.a
app/image-test: app/CMakeFiles/image-test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/harun/Desktop/lessons/391/libceng391/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable image-test"
	cd /home/harun/Desktop/lessons/391/libceng391/app && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/image-test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
app/CMakeFiles/image-test.dir/build: app/image-test

.PHONY : app/CMakeFiles/image-test.dir/build

app/CMakeFiles/image-test.dir/clean:
	cd /home/harun/Desktop/lessons/391/libceng391/app && $(CMAKE_COMMAND) -P CMakeFiles/image-test.dir/cmake_clean.cmake
.PHONY : app/CMakeFiles/image-test.dir/clean

app/CMakeFiles/image-test.dir/depend:
	cd /home/harun/Desktop/lessons/391/libceng391 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/harun/Desktop/lessons/391/libceng391 /home/harun/Desktop/lessons/391/libceng391/app /home/harun/Desktop/lessons/391/libceng391 /home/harun/Desktop/lessons/391/libceng391/app /home/harun/Desktop/lessons/391/libceng391/app/CMakeFiles/image-test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : app/CMakeFiles/image-test.dir/depend

