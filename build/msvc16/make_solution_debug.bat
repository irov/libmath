@echo off

set "CONFIGURATION=Debug"
set "SOLUTION_DIR=..\..\solutions\libmath_msvc16\%CONFIGURATION%"

@mkdir %SOLUTION_DIR%
@pushd %SOLUTION_DIR%
CMake -G "Visual Studio 16 2019" -S "%CD%\..\..\.." -DCMAKE_CONFIGURATION_TYPES:STRING=%CONFIGURATION% -DCMAKE_BUILD_TYPE:STRING=%CONFIGURATION% -DLIBMATH_EXAMPLES_BUILD:BOOL=TRUE
@popd

@echo on
@pause
