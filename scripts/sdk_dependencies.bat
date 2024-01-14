@echo off

set SDKMANAGER_PATH=%CD%\..\dependencies\AndroidSDK\cmdline-tools\latest\bin

echo Downloading Android SDK Dependencies...

echo. | %SDKMANAGER_PATH%\sdkmanager --licenses
%SDKMANAGER_PATH%\sdkmanager "platform-tools" "platforms;android-33" "build-tools;33.0.0"

echo Android SDK Dependencies installed
