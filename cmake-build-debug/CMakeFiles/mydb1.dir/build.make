# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\Jan\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\203.6682.181\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\Jan\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\203.6682.181\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\codes\cpp\mydb4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\codes\cpp\mydb4\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/mydb1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/mydb1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mydb1.dir/flags.make

CMakeFiles/mydb1.dir/main.cpp.obj: CMakeFiles/mydb1.dir/flags.make
CMakeFiles/mydb1.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\codes\cpp\mydb4\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mydb1.dir/main.cpp.obj"
	D:\environment\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\mydb1.dir\main.cpp.obj -c D:\codes\cpp\mydb4\main.cpp

CMakeFiles/mydb1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mydb1.dir/main.cpp.i"
	D:\environment\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\codes\cpp\mydb4\main.cpp > CMakeFiles\mydb1.dir\main.cpp.i

CMakeFiles/mydb1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mydb1.dir/main.cpp.s"
	D:\environment\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\codes\cpp\mydb4\main.cpp -o CMakeFiles\mydb1.dir\main.cpp.s

CMakeFiles/mydb1.dir/Meta.cpp.obj: CMakeFiles/mydb1.dir/flags.make
CMakeFiles/mydb1.dir/Meta.cpp.obj: ../Meta.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\codes\cpp\mydb4\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/mydb1.dir/Meta.cpp.obj"
	D:\environment\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\mydb1.dir\Meta.cpp.obj -c D:\codes\cpp\mydb4\Meta.cpp

CMakeFiles/mydb1.dir/Meta.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mydb1.dir/Meta.cpp.i"
	D:\environment\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\codes\cpp\mydb4\Meta.cpp > CMakeFiles\mydb1.dir\Meta.cpp.i

CMakeFiles/mydb1.dir/Meta.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mydb1.dir/Meta.cpp.s"
	D:\environment\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\codes\cpp\mydb4\Meta.cpp -o CMakeFiles\mydb1.dir\Meta.cpp.s

CMakeFiles/mydb1.dir/DataHandler.cpp.obj: CMakeFiles/mydb1.dir/flags.make
CMakeFiles/mydb1.dir/DataHandler.cpp.obj: ../DataHandler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\codes\cpp\mydb4\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/mydb1.dir/DataHandler.cpp.obj"
	D:\environment\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\mydb1.dir\DataHandler.cpp.obj -c D:\codes\cpp\mydb4\DataHandler.cpp

CMakeFiles/mydb1.dir/DataHandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mydb1.dir/DataHandler.cpp.i"
	D:\environment\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\codes\cpp\mydb4\DataHandler.cpp > CMakeFiles\mydb1.dir\DataHandler.cpp.i

CMakeFiles/mydb1.dir/DataHandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mydb1.dir/DataHandler.cpp.s"
	D:\environment\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\codes\cpp\mydb4\DataHandler.cpp -o CMakeFiles\mydb1.dir\DataHandler.cpp.s

CMakeFiles/mydb1.dir/Parse.cpp.obj: CMakeFiles/mydb1.dir/flags.make
CMakeFiles/mydb1.dir/Parse.cpp.obj: ../Parse.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\codes\cpp\mydb4\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/mydb1.dir/Parse.cpp.obj"
	D:\environment\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\mydb1.dir\Parse.cpp.obj -c D:\codes\cpp\mydb4\Parse.cpp

CMakeFiles/mydb1.dir/Parse.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mydb1.dir/Parse.cpp.i"
	D:\environment\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\codes\cpp\mydb4\Parse.cpp > CMakeFiles\mydb1.dir\Parse.cpp.i

CMakeFiles/mydb1.dir/Parse.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mydb1.dir/Parse.cpp.s"
	D:\environment\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\codes\cpp\mydb4\Parse.cpp -o CMakeFiles\mydb1.dir\Parse.cpp.s

CMakeFiles/mydb1.dir/Handler.cpp.obj: CMakeFiles/mydb1.dir/flags.make
CMakeFiles/mydb1.dir/Handler.cpp.obj: ../Handler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\codes\cpp\mydb4\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/mydb1.dir/Handler.cpp.obj"
	D:\environment\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\mydb1.dir\Handler.cpp.obj -c D:\codes\cpp\mydb4\Handler.cpp

CMakeFiles/mydb1.dir/Handler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mydb1.dir/Handler.cpp.i"
	D:\environment\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\codes\cpp\mydb4\Handler.cpp > CMakeFiles\mydb1.dir\Handler.cpp.i

CMakeFiles/mydb1.dir/Handler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mydb1.dir/Handler.cpp.s"
	D:\environment\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\codes\cpp\mydb4\Handler.cpp -o CMakeFiles\mydb1.dir\Handler.cpp.s

CMakeFiles/mydb1.dir/AvlNode.cpp.obj: CMakeFiles/mydb1.dir/flags.make
CMakeFiles/mydb1.dir/AvlNode.cpp.obj: ../AvlNode.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\codes\cpp\mydb4\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/mydb1.dir/AvlNode.cpp.obj"
	D:\environment\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\mydb1.dir\AvlNode.cpp.obj -c D:\codes\cpp\mydb4\AvlNode.cpp

CMakeFiles/mydb1.dir/AvlNode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mydb1.dir/AvlNode.cpp.i"
	D:\environment\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\codes\cpp\mydb4\AvlNode.cpp > CMakeFiles\mydb1.dir\AvlNode.cpp.i

CMakeFiles/mydb1.dir/AvlNode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mydb1.dir/AvlNode.cpp.s"
	D:\environment\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\codes\cpp\mydb4\AvlNode.cpp -o CMakeFiles\mydb1.dir\AvlNode.cpp.s

# Object files for target mydb1
mydb1_OBJECTS = \
"CMakeFiles/mydb1.dir/main.cpp.obj" \
"CMakeFiles/mydb1.dir/Meta.cpp.obj" \
"CMakeFiles/mydb1.dir/DataHandler.cpp.obj" \
"CMakeFiles/mydb1.dir/Parse.cpp.obj" \
"CMakeFiles/mydb1.dir/Handler.cpp.obj" \
"CMakeFiles/mydb1.dir/AvlNode.cpp.obj"

# External object files for target mydb1
mydb1_EXTERNAL_OBJECTS =

mydb1.exe: CMakeFiles/mydb1.dir/main.cpp.obj
mydb1.exe: CMakeFiles/mydb1.dir/Meta.cpp.obj
mydb1.exe: CMakeFiles/mydb1.dir/DataHandler.cpp.obj
mydb1.exe: CMakeFiles/mydb1.dir/Parse.cpp.obj
mydb1.exe: CMakeFiles/mydb1.dir/Handler.cpp.obj
mydb1.exe: CMakeFiles/mydb1.dir/AvlNode.cpp.obj
mydb1.exe: CMakeFiles/mydb1.dir/build.make
mydb1.exe: CMakeFiles/mydb1.dir/linklibs.rsp
mydb1.exe: CMakeFiles/mydb1.dir/objects1.rsp
mydb1.exe: CMakeFiles/mydb1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\codes\cpp\mydb4\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable mydb1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\mydb1.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mydb1.dir/build: mydb1.exe

.PHONY : CMakeFiles/mydb1.dir/build

CMakeFiles/mydb1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\mydb1.dir\cmake_clean.cmake
.PHONY : CMakeFiles/mydb1.dir/clean

CMakeFiles/mydb1.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\codes\cpp\mydb4 D:\codes\cpp\mydb4 D:\codes\cpp\mydb4\cmake-build-debug D:\codes\cpp\mydb4\cmake-build-debug D:\codes\cpp\mydb4\cmake-build-debug\CMakeFiles\mydb1.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mydb1.dir/depend

