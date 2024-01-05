@echo off

set JDK_URL=https://download.java.net/java/GA/jdk21.0.1/415e3f918a1f4062a0074a2794853d0d/12/GPL/openjdk-21.0.1_windows-x64_bin.zip
set DOWNLOAD_PATH=%CD%\jdk.zip
set INSTALL_PATH=%CD%\jdk

echo Downloading JDK...
curl -L %JDK_URL% -o %DOWNLOAD_PATH%

echo Extracting JDK...
powershell -command "Expand-Archive -Path '%DOWNLOAD_PATH%' -DestinationPath '%INSTALL_PATH%'"

echo JDK installed in %INSTALL_PATH%
