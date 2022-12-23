# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.25.1/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.25.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/chrisbetancur/Projects/OpenGLTesting/BetancurDemo/lib/glfw

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/chrisbetancur/Projects/OpenGLTesting/BetancurDemo/lib/glfw

# Include any dependencies generated for this target.
include examples/CMakeFiles/boing.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include examples/CMakeFiles/boing.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/CMakeFiles/boing.dir/progress.make

# Include the compile flags for this target's objects.
include examples/CMakeFiles/boing.dir/flags.make

examples/boing.app/Contents/Resources/glfw.icns: examples/glfw.icns
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Copying OS X content examples/boing.app/Contents/Resources/glfw.icns"
	$(CMAKE_COMMAND) -E copy /Users/chrisbetancur/Projects/OpenGLTesting/BetancurDemo/lib/glfw/examples/glfw.icns examples/boing.app/Contents/Resources/glfw.icns

examples/CMakeFiles/boing.dir/boing.c.o: examples/CMakeFiles/boing.dir/flags.make
examples/CMakeFiles/boing.dir/boing.c.o: examples/boing.c
examples/CMakeFiles/boing.dir/boing.c.o: examples/CMakeFiles/boing.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/chrisbetancur/Projects/OpenGLTesting/BetancurDemo/lib/glfw/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object examples/CMakeFiles/boing.dir/boing.c.o"
	cd /Users/chrisbetancur/Projects/OpenGLTesting/BetancurDemo/lib/glfw/examples && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT examples/CMakeFiles/boing.dir/boing.c.o -MF CMakeFiles/boing.dir/boing.c.o.d -o CMakeFiles/boing.dir/boing.c.o -c /Users/chrisbetancur/Projects/OpenGLTesting/BetancurDemo/lib/glfw/examples/boing.c

examples/CMakeFiles/boing.dir/boing.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/boing.dir/boing.c.i"
	cd /Users/chrisbetancur/Projects/OpenGLTesting/BetancurDemo/lib/glfw/examples && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/chrisbetancur/Projects/OpenGLTesting/BetancurDemo/lib/glfw/examples/boing.c > CMakeFiles/boing.dir/boing.c.i

examples/CMakeFiles/boing.dir/boing.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/boing.dir/boing.c.s"
	cd /Users/chrisbetancur/Projects/OpenGLTesting/BetancurDemo/lib/glfw/examples && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/chrisbetancur/Projects/OpenGLTesting/BetancurDemo/lib/glfw/examples/boing.c -o CMakeFiles/boing.dir/boing.c.s

# Object files for target boing
boing_OBJECTS = \
"CMakeFiles/boing.dir/boing.c.o"

# External object files for target boing
boing_EXTERNAL_OBJECTS =

examples/boing.app/Contents/MacOS/boing: examples/CMakeFiles/boing.dir/boing.c.o
examples/boing.app/Contents/MacOS/boing: examples/CMakeFiles/boing.dir/build.make
examples/boing.app/Contents/MacOS/boing: src/libglfw3.a
examples/boing.app/Contents/MacOS/boing: examples/CMakeFiles/boing.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/chrisbetancur/Projects/OpenGLTesting/BetancurDemo/lib/glfw/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable boing.app/Contents/MacOS/boing"
	cd /Users/chrisbetancur/Projects/OpenGLTesting/BetancurDemo/lib/glfw/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/boing.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/CMakeFiles/boing.dir/build: examples/boing.app/Contents/MacOS/boing
examples/CMakeFiles/boing.dir/build: examples/boing.app/Contents/Resources/glfw.icns
.PHONY : examples/CMakeFiles/boing.dir/build

examples/CMakeFiles/boing.dir/clean:
	cd /Users/chrisbetancur/Projects/OpenGLTesting/BetancurDemo/lib/glfw/examples && $(CMAKE_COMMAND) -P CMakeFiles/boing.dir/cmake_clean.cmake
.PHONY : examples/CMakeFiles/boing.dir/clean

examples/CMakeFiles/boing.dir/depend:
	cd /Users/chrisbetancur/Projects/OpenGLTesting/BetancurDemo/lib/glfw && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/chrisbetancur/Projects/OpenGLTesting/BetancurDemo/lib/glfw /Users/chrisbetancur/Projects/OpenGLTesting/BetancurDemo/lib/glfw/examples /Users/chrisbetancur/Projects/OpenGLTesting/BetancurDemo/lib/glfw /Users/chrisbetancur/Projects/OpenGLTesting/BetancurDemo/lib/glfw/examples /Users/chrisbetancur/Projects/OpenGLTesting/BetancurDemo/lib/glfw/examples/CMakeFiles/boing.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/CMakeFiles/boing.dir/depend
