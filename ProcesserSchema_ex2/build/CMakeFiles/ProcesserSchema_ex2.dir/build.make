# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.2

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
CMAKE_SOURCE_DIR = /home/cris/gitRep/OS_Experiment/ProcesserSchema_ex2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cris/gitRep/OS_Experiment/ProcesserSchema_ex2/build

# Include any dependencies generated for this target.
include CMakeFiles/ProcesserSchema_ex2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ProcesserSchema_ex2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ProcesserSchema_ex2.dir/flags.make

CMakeFiles/ProcesserSchema_ex2.dir/processschma.cpp.o: CMakeFiles/ProcesserSchema_ex2.dir/flags.make
CMakeFiles/ProcesserSchema_ex2.dir/processschma.cpp.o: ../processschma.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/cris/gitRep/OS_Experiment/ProcesserSchema_ex2/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/ProcesserSchema_ex2.dir/processschma.cpp.o"
	/usr/bin/g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/ProcesserSchema_ex2.dir/processschma.cpp.o -c /home/cris/gitRep/OS_Experiment/ProcesserSchema_ex2/processschma.cpp

CMakeFiles/ProcesserSchema_ex2.dir/processschma.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProcesserSchema_ex2.dir/processschma.cpp.i"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/cris/gitRep/OS_Experiment/ProcesserSchema_ex2/processschma.cpp > CMakeFiles/ProcesserSchema_ex2.dir/processschma.cpp.i

CMakeFiles/ProcesserSchema_ex2.dir/processschma.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProcesserSchema_ex2.dir/processschma.cpp.s"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/cris/gitRep/OS_Experiment/ProcesserSchema_ex2/processschma.cpp -o CMakeFiles/ProcesserSchema_ex2.dir/processschma.cpp.s

CMakeFiles/ProcesserSchema_ex2.dir/processschma.cpp.o.requires:
.PHONY : CMakeFiles/ProcesserSchema_ex2.dir/processschma.cpp.o.requires

CMakeFiles/ProcesserSchema_ex2.dir/processschma.cpp.o.provides: CMakeFiles/ProcesserSchema_ex2.dir/processschma.cpp.o.requires
	$(MAKE) -f CMakeFiles/ProcesserSchema_ex2.dir/build.make CMakeFiles/ProcesserSchema_ex2.dir/processschma.cpp.o.provides.build
.PHONY : CMakeFiles/ProcesserSchema_ex2.dir/processschma.cpp.o.provides

CMakeFiles/ProcesserSchema_ex2.dir/processschma.cpp.o.provides.build: CMakeFiles/ProcesserSchema_ex2.dir/processschma.cpp.o

CMakeFiles/ProcesserSchema_ex2.dir/main.cpp.o: CMakeFiles/ProcesserSchema_ex2.dir/flags.make
CMakeFiles/ProcesserSchema_ex2.dir/main.cpp.o: ../main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/cris/gitRep/OS_Experiment/ProcesserSchema_ex2/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/ProcesserSchema_ex2.dir/main.cpp.o"
	/usr/bin/g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/ProcesserSchema_ex2.dir/main.cpp.o -c /home/cris/gitRep/OS_Experiment/ProcesserSchema_ex2/main.cpp

CMakeFiles/ProcesserSchema_ex2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProcesserSchema_ex2.dir/main.cpp.i"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/cris/gitRep/OS_Experiment/ProcesserSchema_ex2/main.cpp > CMakeFiles/ProcesserSchema_ex2.dir/main.cpp.i

CMakeFiles/ProcesserSchema_ex2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProcesserSchema_ex2.dir/main.cpp.s"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/cris/gitRep/OS_Experiment/ProcesserSchema_ex2/main.cpp -o CMakeFiles/ProcesserSchema_ex2.dir/main.cpp.s

CMakeFiles/ProcesserSchema_ex2.dir/main.cpp.o.requires:
.PHONY : CMakeFiles/ProcesserSchema_ex2.dir/main.cpp.o.requires

CMakeFiles/ProcesserSchema_ex2.dir/main.cpp.o.provides: CMakeFiles/ProcesserSchema_ex2.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/ProcesserSchema_ex2.dir/build.make CMakeFiles/ProcesserSchema_ex2.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/ProcesserSchema_ex2.dir/main.cpp.o.provides

CMakeFiles/ProcesserSchema_ex2.dir/main.cpp.o.provides.build: CMakeFiles/ProcesserSchema_ex2.dir/main.cpp.o

CMakeFiles/ProcesserSchema_ex2.dir/process.cpp.o: CMakeFiles/ProcesserSchema_ex2.dir/flags.make
CMakeFiles/ProcesserSchema_ex2.dir/process.cpp.o: ../process.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/cris/gitRep/OS_Experiment/ProcesserSchema_ex2/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/ProcesserSchema_ex2.dir/process.cpp.o"
	/usr/bin/g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/ProcesserSchema_ex2.dir/process.cpp.o -c /home/cris/gitRep/OS_Experiment/ProcesserSchema_ex2/process.cpp

CMakeFiles/ProcesserSchema_ex2.dir/process.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProcesserSchema_ex2.dir/process.cpp.i"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/cris/gitRep/OS_Experiment/ProcesserSchema_ex2/process.cpp > CMakeFiles/ProcesserSchema_ex2.dir/process.cpp.i

CMakeFiles/ProcesserSchema_ex2.dir/process.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProcesserSchema_ex2.dir/process.cpp.s"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/cris/gitRep/OS_Experiment/ProcesserSchema_ex2/process.cpp -o CMakeFiles/ProcesserSchema_ex2.dir/process.cpp.s

CMakeFiles/ProcesserSchema_ex2.dir/process.cpp.o.requires:
.PHONY : CMakeFiles/ProcesserSchema_ex2.dir/process.cpp.o.requires

CMakeFiles/ProcesserSchema_ex2.dir/process.cpp.o.provides: CMakeFiles/ProcesserSchema_ex2.dir/process.cpp.o.requires
	$(MAKE) -f CMakeFiles/ProcesserSchema_ex2.dir/build.make CMakeFiles/ProcesserSchema_ex2.dir/process.cpp.o.provides.build
.PHONY : CMakeFiles/ProcesserSchema_ex2.dir/process.cpp.o.provides

CMakeFiles/ProcesserSchema_ex2.dir/process.cpp.o.provides.build: CMakeFiles/ProcesserSchema_ex2.dir/process.cpp.o

# Object files for target ProcesserSchema_ex2
ProcesserSchema_ex2_OBJECTS = \
"CMakeFiles/ProcesserSchema_ex2.dir/processschma.cpp.o" \
"CMakeFiles/ProcesserSchema_ex2.dir/main.cpp.o" \
"CMakeFiles/ProcesserSchema_ex2.dir/process.cpp.o"

# External object files for target ProcesserSchema_ex2
ProcesserSchema_ex2_EXTERNAL_OBJECTS =

ProcesserSchema_ex2: CMakeFiles/ProcesserSchema_ex2.dir/processschma.cpp.o
ProcesserSchema_ex2: CMakeFiles/ProcesserSchema_ex2.dir/main.cpp.o
ProcesserSchema_ex2: CMakeFiles/ProcesserSchema_ex2.dir/process.cpp.o
ProcesserSchema_ex2: CMakeFiles/ProcesserSchema_ex2.dir/build.make
ProcesserSchema_ex2: CMakeFiles/ProcesserSchema_ex2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ProcesserSchema_ex2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ProcesserSchema_ex2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ProcesserSchema_ex2.dir/build: ProcesserSchema_ex2
.PHONY : CMakeFiles/ProcesserSchema_ex2.dir/build

CMakeFiles/ProcesserSchema_ex2.dir/requires: CMakeFiles/ProcesserSchema_ex2.dir/processschma.cpp.o.requires
CMakeFiles/ProcesserSchema_ex2.dir/requires: CMakeFiles/ProcesserSchema_ex2.dir/main.cpp.o.requires
CMakeFiles/ProcesserSchema_ex2.dir/requires: CMakeFiles/ProcesserSchema_ex2.dir/process.cpp.o.requires
.PHONY : CMakeFiles/ProcesserSchema_ex2.dir/requires

CMakeFiles/ProcesserSchema_ex2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ProcesserSchema_ex2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ProcesserSchema_ex2.dir/clean

CMakeFiles/ProcesserSchema_ex2.dir/depend:
	cd /home/cris/gitRep/OS_Experiment/ProcesserSchema_ex2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cris/gitRep/OS_Experiment/ProcesserSchema_ex2 /home/cris/gitRep/OS_Experiment/ProcesserSchema_ex2 /home/cris/gitRep/OS_Experiment/ProcesserSchema_ex2/build /home/cris/gitRep/OS_Experiment/ProcesserSchema_ex2/build /home/cris/gitRep/OS_Experiment/ProcesserSchema_ex2/build/CMakeFiles/ProcesserSchema_ex2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ProcesserSchema_ex2.dir/depend
