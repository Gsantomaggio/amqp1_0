# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.26

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\SharedVirtualBox\rabbitmq-stream-c-client-main

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\SharedVirtualBox\rabbitmq-stream-c-client-main

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	"C:\Program Files\CMake\bin\cmake-gui.exe" -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	"C:\Program Files\CMake\bin\cmake.exe" --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	cd /d C:\SharedVirtualBox\rabbitmq-stream-c-client-main && $(CMAKE_COMMAND) -E cmake_progress_start C:\SharedVirtualBox\rabbitmq-stream-c-client-main\CMakeFiles C:\SharedVirtualBox\rabbitmq-stream-c-client-main\external\amqp1_0\\CMakeFiles\progress.marks
	cd /d C:\SharedVirtualBox\rabbitmq-stream-c-client-main && $(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 external/amqp1_0/all
	$(CMAKE_COMMAND) -E cmake_progress_start C:\SharedVirtualBox\rabbitmq-stream-c-client-main\CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	cd /d C:\SharedVirtualBox\rabbitmq-stream-c-client-main && $(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 external/amqp1_0/clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	cd /d C:\SharedVirtualBox\rabbitmq-stream-c-client-main && $(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 external/amqp1_0/preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	cd /d C:\SharedVirtualBox\rabbitmq-stream-c-client-main && $(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 external/amqp1_0/preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	cd /d C:\SharedVirtualBox\rabbitmq-stream-c-client-main && $(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles\Makefile.cmake 1
.PHONY : depend

# Convenience name for target.
external/amqp1_0/CMakeFiles/Experimental.dir/rule:
	cd /d C:\SharedVirtualBox\rabbitmq-stream-c-client-main && $(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 external/amqp1_0/CMakeFiles/Experimental.dir/rule
.PHONY : external/amqp1_0/CMakeFiles/Experimental.dir/rule

# Convenience name for target.
Experimental: external/amqp1_0/CMakeFiles/Experimental.dir/rule
.PHONY : Experimental

# fast build rule for target.
Experimental/fast:
	cd /d C:\SharedVirtualBox\rabbitmq-stream-c-client-main && $(MAKE) $(MAKESILENT) -f external\amqp1_0\CMakeFiles\Experimental.dir\build.make external/amqp1_0/CMakeFiles/Experimental.dir/build
.PHONY : Experimental/fast

# Convenience name for target.
external/amqp1_0/CMakeFiles/Nightly.dir/rule:
	cd /d C:\SharedVirtualBox\rabbitmq-stream-c-client-main && $(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 external/amqp1_0/CMakeFiles/Nightly.dir/rule
.PHONY : external/amqp1_0/CMakeFiles/Nightly.dir/rule

# Convenience name for target.
Nightly: external/amqp1_0/CMakeFiles/Nightly.dir/rule
.PHONY : Nightly

# fast build rule for target.
Nightly/fast:
	cd /d C:\SharedVirtualBox\rabbitmq-stream-c-client-main && $(MAKE) $(MAKESILENT) -f external\amqp1_0\CMakeFiles\Nightly.dir\build.make external/amqp1_0/CMakeFiles/Nightly.dir/build
.PHONY : Nightly/fast

# Convenience name for target.
external/amqp1_0/CMakeFiles/Continuous.dir/rule:
	cd /d C:\SharedVirtualBox\rabbitmq-stream-c-client-main && $(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 external/amqp1_0/CMakeFiles/Continuous.dir/rule
.PHONY : external/amqp1_0/CMakeFiles/Continuous.dir/rule

# Convenience name for target.
Continuous: external/amqp1_0/CMakeFiles/Continuous.dir/rule
.PHONY : Continuous

# fast build rule for target.
Continuous/fast:
	cd /d C:\SharedVirtualBox\rabbitmq-stream-c-client-main && $(MAKE) $(MAKESILENT) -f external\amqp1_0\CMakeFiles\Continuous.dir\build.make external/amqp1_0/CMakeFiles/Continuous.dir/build
.PHONY : Continuous/fast

# Convenience name for target.
external/amqp1_0/CMakeFiles/NightlyMemoryCheck.dir/rule:
	cd /d C:\SharedVirtualBox\rabbitmq-stream-c-client-main && $(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 external/amqp1_0/CMakeFiles/NightlyMemoryCheck.dir/rule
.PHONY : external/amqp1_0/CMakeFiles/NightlyMemoryCheck.dir/rule

# Convenience name for target.
NightlyMemoryCheck: external/amqp1_0/CMakeFiles/NightlyMemoryCheck.dir/rule
.PHONY : NightlyMemoryCheck

# fast build rule for target.
NightlyMemoryCheck/fast:
	cd /d C:\SharedVirtualBox\rabbitmq-stream-c-client-main && $(MAKE) $(MAKESILENT) -f external\amqp1_0\CMakeFiles\NightlyMemoryCheck.dir\build.make external/amqp1_0/CMakeFiles/NightlyMemoryCheck.dir/build
.PHONY : NightlyMemoryCheck/fast

# Convenience name for target.
external/amqp1_0/CMakeFiles/NightlyStart.dir/rule:
	cd /d C:\SharedVirtualBox\rabbitmq-stream-c-client-main && $(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 external/amqp1_0/CMakeFiles/NightlyStart.dir/rule
.PHONY : external/amqp1_0/CMakeFiles/NightlyStart.dir/rule

# Convenience name for target.
NightlyStart: external/amqp1_0/CMakeFiles/NightlyStart.dir/rule
.PHONY : NightlyStart

# fast build rule for target.
NightlyStart/fast:
	cd /d C:\SharedVirtualBox\rabbitmq-stream-c-client-main && $(MAKE) $(MAKESILENT) -f external\amqp1_0\CMakeFiles\NightlyStart.dir\build.make external/amqp1_0/CMakeFiles/NightlyStart.dir/build
.PHONY : NightlyStart/fast

# Convenience name for target.
external/amqp1_0/CMakeFiles/NightlyUpdate.dir/rule:
	cd /d C:\SharedVirtualBox\rabbitmq-stream-c-client-main && $(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 external/amqp1_0/CMakeFiles/NightlyUpdate.dir/rule
.PHONY : external/amqp1_0/CMakeFiles/NightlyUpdate.dir/rule

# Convenience name for target.
NightlyUpdate: external/amqp1_0/CMakeFiles/NightlyUpdate.dir/rule
.PHONY : NightlyUpdate

# fast build rule for target.
NightlyUpdate/fast:
	cd /d C:\SharedVirtualBox\rabbitmq-stream-c-client-main && $(MAKE) $(MAKESILENT) -f external\amqp1_0\CMakeFiles\NightlyUpdate.dir\build.make external/amqp1_0/CMakeFiles/NightlyUpdate.dir/build
.PHONY : NightlyUpdate/fast

# Convenience name for target.
external/amqp1_0/CMakeFiles/NightlyConfigure.dir/rule:
	cd /d C:\SharedVirtualBox\rabbitmq-stream-c-client-main && $(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 external/amqp1_0/CMakeFiles/NightlyConfigure.dir/rule
.PHONY : external/amqp1_0/CMakeFiles/NightlyConfigure.dir/rule

# Convenience name for target.
NightlyConfigure: external/amqp1_0/CMakeFiles/NightlyConfigure.dir/rule
.PHONY : NightlyConfigure

# fast build rule for target.
NightlyConfigure/fast:
	cd /d C:\SharedVirtualBox\rabbitmq-stream-c-client-main && $(MAKE) $(MAKESILENT) -f external\amqp1_0\CMakeFiles\NightlyConfigure.dir\build.make external/amqp1_0/CMakeFiles/NightlyConfigure.dir/build
.PHONY : NightlyConfigure/fast

# Convenience name for target.
external/amqp1_0/CMakeFiles/NightlyBuild.dir/rule:
	cd /d C:\SharedVirtualBox\rabbitmq-stream-c-client-main && $(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 external/amqp1_0/CMakeFiles/NightlyBuild.dir/rule
.PHONY : external/amqp1_0/CMakeFiles/NightlyBuild.dir/rule

# Convenience name for target.
NightlyBuild: external/amqp1_0/CMakeFiles/NightlyBuild.dir/rule
.PHONY : NightlyBuild

# fast build rule for target.
NightlyBuild/fast:
	cd /d C:\SharedVirtualBox\rabbitmq-stream-c-client-main && $(MAKE) $(MAKESILENT) -f external\amqp1_0\CMakeFiles\NightlyBuild.dir\build.make external/amqp1_0/CMakeFiles/NightlyBuild.dir/build
.PHONY : NightlyBuild/fast

# Convenience name for target.
external/amqp1_0/CMakeFiles/NightlyTest.dir/rule:
	cd /d C:\SharedVirtualBox\rabbitmq-stream-c-client-main && $(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 external/amqp1_0/CMakeFiles/NightlyTest.dir/rule
.PHONY : external/amqp1_0/CMakeFiles/NightlyTest.dir/rule

# Convenience name for target.
NightlyTest: external/amqp1_0/CMakeFiles/NightlyTest.dir/rule
.PHONY : NightlyTest

# fast build rule for target.
NightlyTest/fast:
	cd /d C:\SharedVirtualBox\rabbitmq-stream-c-client-main && $(MAKE) $(MAKESILENT) -f external\amqp1_0\CMakeFiles\NightlyTest.dir\build.make external/amqp1_0/CMakeFiles/NightlyTest.dir/build
.PHONY : NightlyTest/fast

# Convenience name for target.
external/amqp1_0/CMakeFiles/NightlyCoverage.dir/rule:
	cd /d C:\SharedVirtualBox\rabbitmq-stream-c-client-main && $(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 external/amqp1_0/CMakeFiles/NightlyCoverage.dir/rule
.PHONY : external/amqp1_0/CMakeFiles/NightlyCoverage.dir/rule

# Convenience name for target.
NightlyCoverage: external/amqp1_0/CMakeFiles/NightlyCoverage.dir/rule
.PHONY : NightlyCoverage

# fast build rule for target.
NightlyCoverage/fast:
	cd /d C:\SharedVirtualBox\rabbitmq-stream-c-client-main && $(MAKE) $(MAKESILENT) -f external\amqp1_0\CMakeFiles\NightlyCoverage.dir\build.make external/amqp1_0/CMakeFiles/NightlyCoverage.dir/build
.PHONY : NightlyCoverage/fast

# Convenience name for target.
external/amqp1_0/CMakeFiles/NightlyMemCheck.dir/rule:
	cd /d C:\SharedVirtualBox\rabbitmq-stream-c-client-main && $(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 external/amqp1_0/CMakeFiles/NightlyMemCheck.dir/rule
.PHONY : external/amqp1_0/CMakeFiles/NightlyMemCheck.dir/rule

# Convenience name for target.
NightlyMemCheck: external/amqp1_0/CMakeFiles/NightlyMemCheck.dir/rule
.PHONY : NightlyMemCheck

# fast build rule for target.
NightlyMemCheck/fast:
	cd /d C:\SharedVirtualBox\rabbitmq-stream-c-client-main && $(MAKE) $(MAKESILENT) -f external\amqp1_0\CMakeFiles\NightlyMemCheck.dir\build.make external/amqp1_0/CMakeFiles/NightlyMemCheck.dir/build
.PHONY : NightlyMemCheck/fast

# Convenience name for target.
external/amqp1_0/CMakeFiles/NightlySubmit.dir/rule:
	cd /d C:\SharedVirtualBox\rabbitmq-stream-c-client-main && $(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 external/amqp1_0/CMakeFiles/NightlySubmit.dir/rule
.PHONY : external/amqp1_0/CMakeFiles/NightlySubmit.dir/rule

# Convenience name for target.
NightlySubmit: external/amqp1_0/CMakeFiles/NightlySubmit.dir/rule
.PHONY : NightlySubmit

# fast build rule for target.
NightlySubmit/fast:
	cd /d C:\SharedVirtualBox\rabbitmq-stream-c-client-main && $(MAKE) $(MAKESILENT) -f external\amqp1_0\CMakeFiles\NightlySubmit.dir\build.make external/amqp1_0/CMakeFiles/NightlySubmit.dir/build
.PHONY : NightlySubmit/fast

# Convenience name for target.
external/amqp1_0/CMakeFiles/ExperimentalStart.dir/rule:
	cd /d C:\SharedVirtualBox\rabbitmq-stream-c-client-main && $(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 external/amqp1_0/CMakeFiles/ExperimentalStart.dir/rule
.PHONY : external/amqp1_0/CMakeFiles/ExperimentalStart.dir/rule

# Convenience name for target.
ExperimentalStart: external/amqp1_0/CMakeFiles/ExperimentalStart.dir/rule
.PHONY : ExperimentalStart

# fast build rule for target.
ExperimentalStart/fast:
	cd /d C:\SharedVirtualBox\rabbitmq-stream-c-client-main && $(MAKE) $(MAKESILENT) -f external\amqp1_0\CMakeFiles\ExperimentalStart.dir\build.make external/amqp1_0/CMakeFiles/ExperimentalStart.dir/build
.PHONY : ExperimentalStart/fast

# Convenience name for target.
external/amqp1_0/CMakeFiles/ExperimentalUpdate.dir/rule:
	cd /d C:\SharedVirtualBox\rabbitmq-stream-c-client-main && $(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 external/amqp1_0/CMakeFiles/ExperimentalUpdate.dir/rule
.PHONY : external/amqp1_0/CMakeFiles/ExperimentalUpdate.dir/rule

# Convenience name for target.
ExperimentalUpdate: external/amqp1_0/CMakeFiles/ExperimentalUpdate.dir/rule
.PHONY : ExperimentalUpdate

# fast build rule for target.
ExperimentalUpdate/fast:
	cd /d C:\SharedVirtualBox\rabbitmq-stream-c-client-main && $(MAKE) $(MAKESILENT) -f external\amqp1_0\CMakeFiles\ExperimentalUpdate.dir\build.make external/amqp1_0/CMakeFiles/ExperimentalUpdate.dir/build
.PHONY : ExperimentalUpdate/fast

# Convenience name for target.
external/amqp1_0/CMakeFiles/ExperimentalConfigure.dir/rule:
	cd /d C:\SharedVirtualBox\rabbitmq-stream-c-client-main && $(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 external/amqp1_0/CMakeFiles/ExperimentalConfigure.dir/rule
.PHONY : external/amqp1_0/CMakeFiles/ExperimentalConfigure.dir/rule

# Convenience name for target.
ExperimentalConfigure: external/amqp1_0/CMakeFiles/ExperimentalConfigure.dir/rule
.PHONY : ExperimentalConfigure

# fast build rule for target.
ExperimentalConfigure/fast:
	cd /d C:\SharedVirtualBox\rabbitmq-stream-c-client-main && $(MAKE) $(MAKESILENT) -f external\amqp1_0\CMakeFiles\ExperimentalConfigure.dir\build.make external/amqp1_0/CMakeFiles/ExperimentalConfigure.dir/build
.PHONY : ExperimentalConfigure/fast

# Convenience name for target.
external/amqp1_0/CMakeFiles/ExperimentalBuild.dir/rule:
	cd /d C:\SharedVirtualBox\rabbitmq-stream-c-client-main && $(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 external/amqp1_0/CMakeFiles/ExperimentalBuild.dir/rule
.PHONY : external/amqp1_0/CMakeFiles/ExperimentalBuild.dir/rule

# Convenience name for target.
ExperimentalBuild: external/amqp1_0/CMakeFiles/ExperimentalBuild.dir/rule
.PHONY : ExperimentalBuild

# fast build rule for target.
ExperimentalBuild/fast:
	cd /d C:\SharedVirtualBox\rabbitmq-stream-c-client-main && $(MAKE) $(MAKESILENT) -f external\amqp1_0\CMakeFiles\ExperimentalBuild.dir\build.make external/amqp1_0/CMakeFiles/ExperimentalBuild.dir/build
.PHONY : ExperimentalBuild/fast

# Convenience name for target.
external/amqp1_0/CMakeFiles/ExperimentalTest.dir/rule:
	cd /d C:\SharedVirtualBox\rabbitmq-stream-c-client-main && $(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 external/amqp1_0/CMakeFiles/ExperimentalTest.dir/rule
.PHONY : external/amqp1_0/CMakeFiles/ExperimentalTest.dir/rule

# Convenience name for target.
ExperimentalTest: external/amqp1_0/CMakeFiles/ExperimentalTest.dir/rule
.PHONY : ExperimentalTest

# fast build rule for target.
ExperimentalTest/fast:
	cd /d C:\SharedVirtualBox\rabbitmq-stream-c-client-main && $(MAKE) $(MAKESILENT) -f external\amqp1_0\CMakeFiles\ExperimentalTest.dir\build.make external/amqp1_0/CMakeFiles/ExperimentalTest.dir/build
.PHONY : ExperimentalTest/fast

# Convenience name for target.
external/amqp1_0/CMakeFiles/ExperimentalCoverage.dir/rule:
	cd /d C:\SharedVirtualBox\rabbitmq-stream-c-client-main && $(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 external/amqp1_0/CMakeFiles/ExperimentalCoverage.dir/rule
.PHONY : external/amqp1_0/CMakeFiles/ExperimentalCoverage.dir/rule

# Convenience name for target.
ExperimentalCoverage: external/amqp1_0/CMakeFiles/ExperimentalCoverage.dir/rule
.PHONY : ExperimentalCoverage

# fast build rule for target.
ExperimentalCoverage/fast:
	cd /d C:\SharedVirtualBox\rabbitmq-stream-c-client-main && $(MAKE) $(MAKESILENT) -f external\amqp1_0\CMakeFiles\ExperimentalCoverage.dir\build.make external/amqp1_0/CMakeFiles/ExperimentalCoverage.dir/build
.PHONY : ExperimentalCoverage/fast

# Convenience name for target.
external/amqp1_0/CMakeFiles/ExperimentalMemCheck.dir/rule:
	cd /d C:\SharedVirtualBox\rabbitmq-stream-c-client-main && $(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 external/amqp1_0/CMakeFiles/ExperimentalMemCheck.dir/rule
.PHONY : external/amqp1_0/CMakeFiles/ExperimentalMemCheck.dir/rule

# Convenience name for target.
ExperimentalMemCheck: external/amqp1_0/CMakeFiles/ExperimentalMemCheck.dir/rule
.PHONY : ExperimentalMemCheck

# fast build rule for target.
ExperimentalMemCheck/fast:
	cd /d C:\SharedVirtualBox\rabbitmq-stream-c-client-main && $(MAKE) $(MAKESILENT) -f external\amqp1_0\CMakeFiles\ExperimentalMemCheck.dir\build.make external/amqp1_0/CMakeFiles/ExperimentalMemCheck.dir/build
.PHONY : ExperimentalMemCheck/fast

# Convenience name for target.
external/amqp1_0/CMakeFiles/ExperimentalSubmit.dir/rule:
	cd /d C:\SharedVirtualBox\rabbitmq-stream-c-client-main && $(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 external/amqp1_0/CMakeFiles/ExperimentalSubmit.dir/rule
.PHONY : external/amqp1_0/CMakeFiles/ExperimentalSubmit.dir/rule

# Convenience name for target.
ExperimentalSubmit: external/amqp1_0/CMakeFiles/ExperimentalSubmit.dir/rule
.PHONY : ExperimentalSubmit

# fast build rule for target.
ExperimentalSubmit/fast:
	cd /d C:\SharedVirtualBox\rabbitmq-stream-c-client-main && $(MAKE) $(MAKESILENT) -f external\amqp1_0\CMakeFiles\ExperimentalSubmit.dir\build.make external/amqp1_0/CMakeFiles/ExperimentalSubmit.dir/build
.PHONY : ExperimentalSubmit/fast

# Convenience name for target.
external/amqp1_0/CMakeFiles/ContinuousStart.dir/rule:
	cd /d C:\SharedVirtualBox\rabbitmq-stream-c-client-main && $(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 external/amqp1_0/CMakeFiles/ContinuousStart.dir/rule
.PHONY : external/amqp1_0/CMakeFiles/ContinuousStart.dir/rule

# Convenience name for target.
ContinuousStart: external/amqp1_0/CMakeFiles/ContinuousStart.dir/rule
.PHONY : ContinuousStart

# fast build rule for target.
ContinuousStart/fast:
	cd /d C:\SharedVirtualBox\rabbitmq-stream-c-client-main && $(MAKE) $(MAKESILENT) -f external\amqp1_0\CMakeFiles\ContinuousStart.dir\build.make external/amqp1_0/CMakeFiles/ContinuousStart.dir/build
.PHONY : ContinuousStart/fast

# Convenience name for target.
external/amqp1_0/CMakeFiles/ContinuousUpdate.dir/rule:
	cd /d C:\SharedVirtualBox\rabbitmq-stream-c-client-main && $(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 external/amqp1_0/CMakeFiles/ContinuousUpdate.dir/rule
.PHONY : external/amqp1_0/CMakeFiles/ContinuousUpdate.dir/rule

# Convenience name for target.
ContinuousUpdate: external/amqp1_0/CMakeFiles/ContinuousUpdate.dir/rule
.PHONY : ContinuousUpdate

# fast build rule for target.
ContinuousUpdate/fast:
	cd /d C:\SharedVirtualBox\rabbitmq-stream-c-client-main && $(MAKE) $(MAKESILENT) -f external\amqp1_0\CMakeFiles\ContinuousUpdate.dir\build.make external/amqp1_0/CMakeFiles/ContinuousUpdate.dir/build
.PHONY : ContinuousUpdate/fast

# Convenience name for target.
external/amqp1_0/CMakeFiles/ContinuousConfigure.dir/rule:
	cd /d C:\SharedVirtualBox\rabbitmq-stream-c-client-main && $(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 external/amqp1_0/CMakeFiles/ContinuousConfigure.dir/rule
.PHONY : external/amqp1_0/CMakeFiles/ContinuousConfigure.dir/rule

# Convenience name for target.
ContinuousConfigure: external/amqp1_0/CMakeFiles/ContinuousConfigure.dir/rule
.PHONY : ContinuousConfigure

# fast build rule for target.
ContinuousConfigure/fast:
	cd /d C:\SharedVirtualBox\rabbitmq-stream-c-client-main && $(MAKE) $(MAKESILENT) -f external\amqp1_0\CMakeFiles\ContinuousConfigure.dir\build.make external/amqp1_0/CMakeFiles/ContinuousConfigure.dir/build
.PHONY : ContinuousConfigure/fast

# Convenience name for target.
external/amqp1_0/CMakeFiles/ContinuousBuild.dir/rule:
	cd /d C:\SharedVirtualBox\rabbitmq-stream-c-client-main && $(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 external/amqp1_0/CMakeFiles/ContinuousBuild.dir/rule
.PHONY : external/amqp1_0/CMakeFiles/ContinuousBuild.dir/rule

# Convenience name for target.
ContinuousBuild: external/amqp1_0/CMakeFiles/ContinuousBuild.dir/rule
.PHONY : ContinuousBuild

# fast build rule for target.
ContinuousBuild/fast:
	cd /d C:\SharedVirtualBox\rabbitmq-stream-c-client-main && $(MAKE) $(MAKESILENT) -f external\amqp1_0\CMakeFiles\ContinuousBuild.dir\build.make external/amqp1_0/CMakeFiles/ContinuousBuild.dir/build
.PHONY : ContinuousBuild/fast

# Convenience name for target.
external/amqp1_0/CMakeFiles/ContinuousTest.dir/rule:
	cd /d C:\SharedVirtualBox\rabbitmq-stream-c-client-main && $(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 external/amqp1_0/CMakeFiles/ContinuousTest.dir/rule
.PHONY : external/amqp1_0/CMakeFiles/ContinuousTest.dir/rule

# Convenience name for target.
ContinuousTest: external/amqp1_0/CMakeFiles/ContinuousTest.dir/rule
.PHONY : ContinuousTest

# fast build rule for target.
ContinuousTest/fast:
	cd /d C:\SharedVirtualBox\rabbitmq-stream-c-client-main && $(MAKE) $(MAKESILENT) -f external\amqp1_0\CMakeFiles\ContinuousTest.dir\build.make external/amqp1_0/CMakeFiles/ContinuousTest.dir/build
.PHONY : ContinuousTest/fast

# Convenience name for target.
external/amqp1_0/CMakeFiles/ContinuousCoverage.dir/rule:
	cd /d C:\SharedVirtualBox\rabbitmq-stream-c-client-main && $(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 external/amqp1_0/CMakeFiles/ContinuousCoverage.dir/rule
.PHONY : external/amqp1_0/CMakeFiles/ContinuousCoverage.dir/rule

# Convenience name for target.
ContinuousCoverage: external/amqp1_0/CMakeFiles/ContinuousCoverage.dir/rule
.PHONY : ContinuousCoverage

# fast build rule for target.
ContinuousCoverage/fast:
	cd /d C:\SharedVirtualBox\rabbitmq-stream-c-client-main && $(MAKE) $(MAKESILENT) -f external\amqp1_0\CMakeFiles\ContinuousCoverage.dir\build.make external/amqp1_0/CMakeFiles/ContinuousCoverage.dir/build
.PHONY : ContinuousCoverage/fast

# Convenience name for target.
external/amqp1_0/CMakeFiles/ContinuousMemCheck.dir/rule:
	cd /d C:\SharedVirtualBox\rabbitmq-stream-c-client-main && $(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 external/amqp1_0/CMakeFiles/ContinuousMemCheck.dir/rule
.PHONY : external/amqp1_0/CMakeFiles/ContinuousMemCheck.dir/rule

# Convenience name for target.
ContinuousMemCheck: external/amqp1_0/CMakeFiles/ContinuousMemCheck.dir/rule
.PHONY : ContinuousMemCheck

# fast build rule for target.
ContinuousMemCheck/fast:
	cd /d C:\SharedVirtualBox\rabbitmq-stream-c-client-main && $(MAKE) $(MAKESILENT) -f external\amqp1_0\CMakeFiles\ContinuousMemCheck.dir\build.make external/amqp1_0/CMakeFiles/ContinuousMemCheck.dir/build
.PHONY : ContinuousMemCheck/fast

# Convenience name for target.
external/amqp1_0/CMakeFiles/ContinuousSubmit.dir/rule:
	cd /d C:\SharedVirtualBox\rabbitmq-stream-c-client-main && $(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 external/amqp1_0/CMakeFiles/ContinuousSubmit.dir/rule
.PHONY : external/amqp1_0/CMakeFiles/ContinuousSubmit.dir/rule

# Convenience name for target.
ContinuousSubmit: external/amqp1_0/CMakeFiles/ContinuousSubmit.dir/rule
.PHONY : ContinuousSubmit

# fast build rule for target.
ContinuousSubmit/fast:
	cd /d C:\SharedVirtualBox\rabbitmq-stream-c-client-main && $(MAKE) $(MAKESILENT) -f external\amqp1_0\CMakeFiles\ContinuousSubmit.dir\build.make external/amqp1_0/CMakeFiles/ContinuousSubmit.dir/build
.PHONY : ContinuousSubmit/fast

# Help Target
help:
	@echo The following are some of the valid targets for this Makefile:
	@echo ... all (the default if no target is provided)
	@echo ... clean
	@echo ... depend
	@echo ... edit_cache
	@echo ... rebuild_cache
	@echo ... Continuous
	@echo ... ContinuousBuild
	@echo ... ContinuousConfigure
	@echo ... ContinuousCoverage
	@echo ... ContinuousMemCheck
	@echo ... ContinuousStart
	@echo ... ContinuousSubmit
	@echo ... ContinuousTest
	@echo ... ContinuousUpdate
	@echo ... Experimental
	@echo ... ExperimentalBuild
	@echo ... ExperimentalConfigure
	@echo ... ExperimentalCoverage
	@echo ... ExperimentalMemCheck
	@echo ... ExperimentalStart
	@echo ... ExperimentalSubmit
	@echo ... ExperimentalTest
	@echo ... ExperimentalUpdate
	@echo ... Nightly
	@echo ... NightlyBuild
	@echo ... NightlyConfigure
	@echo ... NightlyCoverage
	@echo ... NightlyMemCheck
	@echo ... NightlyMemoryCheck
	@echo ... NightlyStart
	@echo ... NightlySubmit
	@echo ... NightlyTest
	@echo ... NightlyUpdate
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	cd /d C:\SharedVirtualBox\rabbitmq-stream-c-client-main && $(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles\Makefile.cmake 0
.PHONY : cmake_check_build_system

