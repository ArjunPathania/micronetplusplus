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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/arjunpathania/micronet++

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/arjunpathania/micronet++/build

# Include any dependencies generated for this target.
include CMakeFiles/train_xor.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/train_xor.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/train_xor.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/train_xor.dir/flags.make

CMakeFiles/train_xor.dir/src/train_xor.cpp.o: CMakeFiles/train_xor.dir/flags.make
CMakeFiles/train_xor.dir/src/train_xor.cpp.o: ../src/train_xor.cpp
CMakeFiles/train_xor.dir/src/train_xor.cpp.o: CMakeFiles/train_xor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/arjunpathania/micronet++/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/train_xor.dir/src/train_xor.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/train_xor.dir/src/train_xor.cpp.o -MF CMakeFiles/train_xor.dir/src/train_xor.cpp.o.d -o CMakeFiles/train_xor.dir/src/train_xor.cpp.o -c /home/arjunpathania/micronet++/src/train_xor.cpp

CMakeFiles/train_xor.dir/src/train_xor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/train_xor.dir/src/train_xor.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/arjunpathania/micronet++/src/train_xor.cpp > CMakeFiles/train_xor.dir/src/train_xor.cpp.i

CMakeFiles/train_xor.dir/src/train_xor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/train_xor.dir/src/train_xor.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/arjunpathania/micronet++/src/train_xor.cpp -o CMakeFiles/train_xor.dir/src/train_xor.cpp.s

# Object files for target train_xor
train_xor_OBJECTS = \
"CMakeFiles/train_xor.dir/src/train_xor.cpp.o"

# External object files for target train_xor
train_xor_EXTERNAL_OBJECTS =

train_xor: CMakeFiles/train_xor.dir/src/train_xor.cpp.o
train_xor: CMakeFiles/train_xor.dir/build.make
train_xor: libmicronet.a
train_xor: CMakeFiles/train_xor.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/arjunpathania/micronet++/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable train_xor"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/train_xor.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/train_xor.dir/build: train_xor
.PHONY : CMakeFiles/train_xor.dir/build

CMakeFiles/train_xor.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/train_xor.dir/cmake_clean.cmake
.PHONY : CMakeFiles/train_xor.dir/clean

CMakeFiles/train_xor.dir/depend:
	cd /home/arjunpathania/micronet++/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/arjunpathania/micronet++ /home/arjunpathania/micronet++ /home/arjunpathania/micronet++/build /home/arjunpathania/micronet++/build /home/arjunpathania/micronet++/build/CMakeFiles/train_xor.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/train_xor.dir/depend

