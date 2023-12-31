@echo off

pushd "%~dp0\..\.."

set CMAKE_OPTIONS=-DCMAKE_INSTALL_PREFIX=_install ^
-DBUILD_SAMPLES=ON ^
-DBUILD_SAMPLES_PROTOBUF=OFF ^
-DBUILD_ECAL_TESTS=OFF ^
-DBUILD_ECAL_TESTS_PROTOBUF=OFF ^
-DECAL_CORE_CONFIG_INIFILE=OFF ^
-DECAL_CORE_COMMAND_LINE=OFF ^
-DECAL_CORE_REGISTRATION=OFF ^
-DECAL_CORE_PUBLISHER=ON ^
-DECAL_CORE_SUBSCRIBER=ON ^
-DECAL_CORE_TIMEPLUGIN=OFF ^
-DECAL_NPCAP_SUPPORT=OFF

mkdir _build
cd _build

cmake .. -A x64 %CMAKE_OPTIONS%
cmake --build . --parallel --config Release

popd
