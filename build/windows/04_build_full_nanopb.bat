@echo off

pushd "%~dp0\..\.."

set CMAKE_OPTIONS=-DCMAKE_INSTALL_PREFIX=_install ^
-DBUILD_SAMPLES=ON ^
-DBUILD_SAMPLES_PROTOBUF=ON ^
-DBUILD_ECAL_TESTS=ON ^
-DECAL_CORE_CONFIG_INIFILE=ON ^
-DECAL_CORE_COMMAND_LINE=ON ^
-DECAL_CORE_REGISTRATION=ON ^
-DECAL_CORE_PUBLISHER=ON ^
-DECAL_CORE_SUBSCRIBER=ON ^
-DECAL_CORE_TIMEPLUGIN=ON ^
-DECAL_CORE_NANOPB=ON ^
-DECAL_CORE_PROTOBUF=OFF ^
-DECAL_NPCAP_SUPPORT=ON

mkdir _build
cd _build

cmake .. -A x64 %CMAKE_OPTIONS%
cmake --build . --config Release

popd
