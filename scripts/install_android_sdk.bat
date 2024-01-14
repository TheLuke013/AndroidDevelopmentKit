@echo off

set ANDROID_SDK_URL=https://dl.google.com/android/repository/sdk-tools-windows-4333796.zip
set DOWNLOAD_PATH=%CD%\..\dependencies\android-sdk.zip
set INSTALL_PATH=%CD%\..\dependencies\Android SDK

echo Downloading Android SDK...
curl -L %ANDROID_SDK_URL% -o %DOWNLOAD_PATH%

echo Extracting Android SDK...
powershell -command "Expand-Archive -Path '%DOWNLOAD_PATH%' -DestinationPath '%INSTALL_PATH%'"

echo Deleting Android SDK zip...
del /Q %DOWNLOAD_PATH%

echo Android SDK installed in %INSTALL_PATH%
