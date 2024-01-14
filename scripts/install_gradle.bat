@echo off

set GRADLE_URL=https://services.gradle.org/distributions/gradle-8.5-bin.zip
set DOWNLOAD_PATH=%CD%\..\dependencies\gradle.zip
set INSTALL_PATH=%CD%\..\dependencies\gradle

echo Downloading Gradle...
curl -L %GRADLE_URL% -o %DOWNLOAD_PATH%

echo Extracting Gradle...
powershell -command "Expand-Archive -Path '%DOWNLOAD_PATH%' -DestinationPath '%INSTALL_PATH%'"

echo Deleting Gradle zip...
del /Q %DOWNLOAD_PATH%

echo Gradle installed in %INSTALL_PATH%
