@echo off

set COMMAND_LINE_TOOLS_URL=https://dl.google.com/android/repository/commandlinetools-win-11076708_latest.zip?hl=pt-br
set DOWNLOAD_PATH=%CD%\..\dependencies\command_line_tools.zip
set INSTALL_PATH=%CD%\..\dependencies\Android SDK

echo Downloading Command Line Tools...
curl -L %COMMAND_LINE_TOOLS_URL% -o %DOWNLOAD_PATH%

echo Extracting Command Line Tools...
powershell -command "Expand-Archive -Path '%DOWNLOAD_PATH%' -DestinationPath '%INSTALL_PATH%'"

echo Deleting Command Line Tools zip...
del /Q %DOWNLOAD_PATH%

echo Command Line Tools installed in %INSTALL_PATH%
