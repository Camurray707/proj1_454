# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

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
CMAKE_COMMAND = /home/chris/Apps/clion-2020.1.1/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/chris/Apps/clion-2020.1.1/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/chris/Desktop/cs_454/project1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/chris/Desktop/cs_454/project1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/CS_454.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CS_454.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CS_454.dir/flags.make

CMakeFiles/CS_454.dir/main.cpp.o: CMakeFiles/CS_454.dir/flags.make
CMakeFiles/CS_454.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chris/Desktop/cs_454/project1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CS_454.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CS_454.dir/main.cpp.o -c /home/chris/Desktop/cs_454/project1/main.cpp

CMakeFiles/CS_454.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CS_454.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/chris/Desktop/cs_454/project1/main.cpp > CMakeFiles/CS_454.dir/main.cpp.i

CMakeFiles/CS_454.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CS_454.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/chris/Desktop/cs_454/project1/main.cpp -o CMakeFiles/CS_454.dir/main.cpp.s

CMakeFiles/CS_454.dir/DFAList.cpp.o: CMakeFiles/CS_454.dir/flags.make
CMakeFiles/CS_454.dir/DFAList.cpp.o: ../DFAList.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chris/Desktop/cs_454/project1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/CS_454.dir/DFAList.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CS_454.dir/DFAList.cpp.o -c /home/chris/Desktop/cs_454/project1/DFAList.cpp

CMakeFiles/CS_454.dir/DFAList.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CS_454.dir/DFAList.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/chris/Desktop/cs_454/project1/DFAList.cpp > CMakeFiles/CS_454.dir/DFAList.cpp.i

CMakeFiles/CS_454.dir/DFAList.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CS_454.dir/DFAList.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/chris/Desktop/cs_454/project1/DFAList.cpp -o CMakeFiles/CS_454.dir/DFAList.cpp.s

# Object files for target CS_454
CS_454_OBJECTS = \
"CMakeFiles/CS_454.dir/main.cpp.o" \
"CMakeFiles/CS_454.dir/DFAList.cpp.o"

# External object files for target CS_454
CS_454_EXTERNAL_OBJECTS =

CS_454: CMakeFiles/CS_454.dir/main.cpp.o
CS_454: CMakeFiles/CS_454.dir/DFAList.cpp.o
CS_454: CMakeFiles/CS_454.dir/build.make
CS_454: CMakeFiles/CS_454.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/chris/Desktop/cs_454/project1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable CS_454"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CS_454.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CS_454.dir/build: CS_454

.PHONY : CMakeFiles/CS_454.dir/build

CMakeFiles/CS_454.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CS_454.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CS_454.dir/clean

CMakeFiles/CS_454.dir/depend:
	cd /home/chris/Desktop/cs_454/project1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/chris/Desktop/cs_454/project1 /home/chris/Desktop/cs_454/project1 /home/chris/Desktop/cs_454/project1/cmake-build-debug /home/chris/Desktop/cs_454/project1/cmake-build-debug /home/chris/Desktop/cs_454/project1/cmake-build-debug/CMakeFiles/CS_454.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CS_454.dir/depend

