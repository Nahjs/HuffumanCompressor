# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.29

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = D:\QT\Tools\CMake_64\bin\cmake.exe

# The command to remove a file.
RM = D:\QT\Tools\CMake_64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\CLion\HUFCompressor

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\CLion\HUFCompressor\cmake-build-debug

# Utility rule file for MyProjectName_autogen.

# Include any custom commands dependencies for this target.
include CMakeFiles/MyProjectName_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/MyProjectName_autogen.dir/progress.make

CMakeFiles/MyProjectName_autogen: MyProjectName_autogen/timestamp

MyProjectName_autogen/timestamp: D:/QT/6.5.3/mingw_64/./bin/moc.exe
MyProjectName_autogen/timestamp: D:/QT/6.5.3/mingw_64/./bin/uic.exe
MyProjectName_autogen/timestamp: CMakeFiles/MyProjectName_autogen.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=D:\CLion\HUFCompressor\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target MyProjectName"
	D:\QT\Tools\CMake_64\bin\cmake.exe -E cmake_autogen D:/CLion/HUFCompressor/cmake-build-debug/CMakeFiles/MyProjectName_autogen.dir/AutogenInfo.json Debug
	D:\QT\Tools\CMake_64\bin\cmake.exe -E touch D:/CLion/HUFCompressor/cmake-build-debug/MyProjectName_autogen/timestamp

MyProjectName_autogen: CMakeFiles/MyProjectName_autogen
MyProjectName_autogen: MyProjectName_autogen/timestamp
MyProjectName_autogen: CMakeFiles/MyProjectName_autogen.dir/build.make
.PHONY : MyProjectName_autogen

# Rule to build all files generated by this target.
CMakeFiles/MyProjectName_autogen.dir/build: MyProjectName_autogen
.PHONY : CMakeFiles/MyProjectName_autogen.dir/build

CMakeFiles/MyProjectName_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\MyProjectName_autogen.dir\cmake_clean.cmake
.PHONY : CMakeFiles/MyProjectName_autogen.dir/clean

CMakeFiles/MyProjectName_autogen.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\CLion\HUFCompressor D:\CLion\HUFCompressor D:\CLion\HUFCompressor\cmake-build-debug D:\CLion\HUFCompressor\cmake-build-debug D:\CLion\HUFCompressor\cmake-build-debug\CMakeFiles\MyProjectName_autogen.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/MyProjectName_autogen.dir/depend

