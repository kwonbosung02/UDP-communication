# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.22.1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.22.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/kwonbosung/program/UDP-communication

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/kwonbosung/program/UDP-communication/build

# Include any dependencies generated for this target.
include CMakeFiles/udp-server.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/udp-server.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/udp-server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/udp-server.dir/flags.make

CMakeFiles/udp-server.dir/udp-server.cpp.o: CMakeFiles/udp-server.dir/flags.make
CMakeFiles/udp-server.dir/udp-server.cpp.o: ../udp-server.cpp
CMakeFiles/udp-server.dir/udp-server.cpp.o: CMakeFiles/udp-server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kwonbosung/program/UDP-communication/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/udp-server.dir/udp-server.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/udp-server.dir/udp-server.cpp.o -MF CMakeFiles/udp-server.dir/udp-server.cpp.o.d -o CMakeFiles/udp-server.dir/udp-server.cpp.o -c /Users/kwonbosung/program/UDP-communication/udp-server.cpp

CMakeFiles/udp-server.dir/udp-server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/udp-server.dir/udp-server.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kwonbosung/program/UDP-communication/udp-server.cpp > CMakeFiles/udp-server.dir/udp-server.cpp.i

CMakeFiles/udp-server.dir/udp-server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/udp-server.dir/udp-server.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kwonbosung/program/UDP-communication/udp-server.cpp -o CMakeFiles/udp-server.dir/udp-server.cpp.s

# Object files for target udp-server
udp__server_OBJECTS = \
"CMakeFiles/udp-server.dir/udp-server.cpp.o"

# External object files for target udp-server
udp__server_EXTERNAL_OBJECTS =

udp-server: CMakeFiles/udp-server.dir/udp-server.cpp.o
udp-server: CMakeFiles/udp-server.dir/build.make
udp-server: CMakeFiles/udp-server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/kwonbosung/program/UDP-communication/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable udp-server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/udp-server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/udp-server.dir/build: udp-server
.PHONY : CMakeFiles/udp-server.dir/build

CMakeFiles/udp-server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/udp-server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/udp-server.dir/clean

CMakeFiles/udp-server.dir/depend:
	cd /Users/kwonbosung/program/UDP-communication/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/kwonbosung/program/UDP-communication /Users/kwonbosung/program/UDP-communication /Users/kwonbosung/program/UDP-communication/build /Users/kwonbosung/program/UDP-communication/build /Users/kwonbosung/program/UDP-communication/build/CMakeFiles/udp-server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/udp-server.dir/depend

