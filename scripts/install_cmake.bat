@echo off

set CMAKE_URL=https://github.com/Kitware/CMake/releases/download/v3.28.1/cmake-3.28.1-windows-x86_64.zip
set DOWNLOAD_PATH=%CD%\..\dependencies\cmake.zip
set INSTALL_PATH=%CD%\..\dependencies\cmake

echo Downloading CMake...
curl -L %CMAKE_URL% -o %DOWNLOAD_PATH%

echo Extracting CMake...
powershell -command "Expand-Archive -Path '%DOWNLOAD_PATH%' -DestinationPath '%INSTALL_PATH%'"

echo Deleting CMake zip...
del /Q %DOWNLOAD_PATH%

echo CMake installed in %INSTALL_PATH%
