# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_SOURCE_DIR = "/mnt/e/Spring 2020/COMP 362 S20/HafizTaseenLab02"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/mnt/e/Spring 2020/COMP 362 S20/HafizTaseenLab02/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/sub.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sub.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sub.dir/flags.make

CMakeFiles/sub.dir/sub.c.o: CMakeFiles/sub.dir/flags.make
CMakeFiles/sub.dir/sub.c.o: ../sub.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/e/Spring 2020/COMP 362 S20/HafizTaseenLab02/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/sub.dir/sub.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sub.dir/sub.c.o   -c "/mnt/e/Spring 2020/COMP 362 S20/HafizTaseenLab02/sub.c"

CMakeFiles/sub.dir/sub.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sub.dir/sub.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/e/Spring 2020/COMP 362 S20/HafizTaseenLab02/sub.c" > CMakeFiles/sub.dir/sub.c.i

CMakeFiles/sub.dir/sub.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sub.dir/sub.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/e/Spring 2020/COMP 362 S20/HafizTaseenLab02/sub.c" -o CMakeFiles/sub.dir/sub.c.s

# Object files for target sub
sub_OBJECTS = \
"CMakeFiles/sub.dir/sub.c.o"

# External object files for target sub
sub_EXTERNAL_OBJECTS =

sub: CMakeFiles/sub.dir/sub.c.o
sub: CMakeFiles/sub.dir/build.make
sub: CMakeFiles/sub.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/mnt/e/Spring 2020/COMP 362 S20/HafizTaseenLab02/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable sub"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sub.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sub.dir/build: sub

.PHONY : CMakeFiles/sub.dir/build

CMakeFiles/sub.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sub.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sub.dir/clean

CMakeFiles/sub.dir/depend:
	cd "/mnt/e/Spring 2020/COMP 362 S20/HafizTaseenLab02/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/mnt/e/Spring 2020/COMP 362 S20/HafizTaseenLab02" "/mnt/e/Spring 2020/COMP 362 S20/HafizTaseenLab02" "/mnt/e/Spring 2020/COMP 362 S20/HafizTaseenLab02/cmake-build-debug" "/mnt/e/Spring 2020/COMP 362 S20/HafizTaseenLab02/cmake-build-debug" "/mnt/e/Spring 2020/COMP 362 S20/HafizTaseenLab02/cmake-build-debug/CMakeFiles/sub.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/sub.dir/depend

