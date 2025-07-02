cmake_minimum_required(VERSION 3.31)

project(BleNative)

if(NOT DEFINED ENV{JAVA_HOME})
    message(FATAL_ERROR "JAVA_HOME environment variable not set!")
endif()

include_directories($ENV{JAVA_HOME}/include)
include_directories($ENV{JAVA_HOME}/include/win32)

set(CMAKE_CXX_STANDARD 20)

add_library(BleNative SHARED
        entry.cpp
        jni/NBluetoothAdapter.cpp
        Util.cpp
        Util.h
        jni/NRadio.cpp
        jni/Wrapper.h
        jni/NBluetoothLEDevice.cpp
        jni/advertisement/NBluetoothLEAdvertisementWatcher.cpp
        jni/advertisement/NBluetoothLEAdvertisementReceivedEventArgs.cpp
        jni/Native.cpp
        jni/NBluetoothSignalStrengthFilter.cpp
        jni/advertisement/NBluetoothLEAdvertisement.cpp
        jni/genericAttributeProfile/NGattDeviceServicesResult.cpp
        jni/genericAttributeProfile/NGattDeviceService.cpp
        "jni/NBluetoothUuidHelper .cpp"
        jni/winrt/NGUID.cpp
        jni/genericAttributeProfile/NGattCharacteristicsResult.cpp
        jni/genericAttributeProfile/NGattCharacteristic.cpp
        jni/winrt/NAsyncOperation.cpp
        jni/genericAttributeProfile/NGattReadResult.cpp)
