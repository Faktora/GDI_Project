# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.2.3\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Faktora\Desktop\LinuxHome\Project\GDI_Projekt

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Faktora\Desktop\LinuxHome\Project\GDI_Projekt\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/GDI_Projekt.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/GDI_Projekt.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/GDI_Projekt.dir/flags.make

CMakeFiles/GDI_Projekt.dir/main.c.obj: CMakeFiles/GDI_Projekt.dir/flags.make
CMakeFiles/GDI_Projekt.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Faktora\Desktop\LinuxHome\Project\GDI_Projekt\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/GDI_Projekt.dir/main.c.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\GDI_Projekt.dir\main.c.obj   -c C:\Users\Faktora\Desktop\LinuxHome\Project\GDI_Projekt\main.c

CMakeFiles/GDI_Projekt.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/GDI_Projekt.dir/main.c.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Faktora\Desktop\LinuxHome\Project\GDI_Projekt\main.c > CMakeFiles\GDI_Projekt.dir\main.c.i

CMakeFiles/GDI_Projekt.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/GDI_Projekt.dir/main.c.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Faktora\Desktop\LinuxHome\Project\GDI_Projekt\main.c -o CMakeFiles\GDI_Projekt.dir\main.c.s

# Object files for target GDI_Projekt
GDI_Projekt_OBJECTS = \
"CMakeFiles/GDI_Projekt.dir/main.c.obj"

# External object files for target GDI_Projekt
GDI_Projekt_EXTERNAL_OBJECTS =

GDI_Projekt.exe: CMakeFiles/GDI_Projekt.dir/main.c.obj
GDI_Projekt.exe: CMakeFiles/GDI_Projekt.dir/build.make
GDI_Projekt.exe: CMakeFiles/GDI_Projekt.dir/linklibs.rsp
GDI_Projekt.exe: CMakeFiles/GDI_Projekt.dir/objects1.rsp
GDI_Projekt.exe: CMakeFiles/GDI_Projekt.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Faktora\Desktop\LinuxHome\Project\GDI_Projekt\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable GDI_Projekt.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\GDI_Projekt.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/GDI_Projekt.dir/build: GDI_Projekt.exe

.PHONY : CMakeFiles/GDI_Projekt.dir/build

CMakeFiles/GDI_Projekt.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\GDI_Projekt.dir\cmake_clean.cmake
.PHONY : CMakeFiles/GDI_Projekt.dir/clean

CMakeFiles/GDI_Projekt.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Faktora\Desktop\LinuxHome\Project\GDI_Projekt C:\Users\Faktora\Desktop\LinuxHome\Project\GDI_Projekt C:\Users\Faktora\Desktop\LinuxHome\Project\GDI_Projekt\cmake-build-debug C:\Users\Faktora\Desktop\LinuxHome\Project\GDI_Projekt\cmake-build-debug C:\Users\Faktora\Desktop\LinuxHome\Project\GDI_Projekt\cmake-build-debug\CMakeFiles\GDI_Projekt.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/GDI_Projekt.dir/depend

