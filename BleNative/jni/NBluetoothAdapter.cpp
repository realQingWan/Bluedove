#include <winrt/windows.devices.bluetooth.h>
#include <winrt/windows.foundation.h>
#include <iostream>
#include "../Util.h"

#include "../jni_generated/dev_qingwan_bluedove_BluetoothAdapter.h"

using namespace winrt;
using namespace Windows::Devices::Bluetooth;

struct BluetoothAdapterWrapper
{
    BluetoothAdapter value;
};


JNIEXPORT jlong JNICALL Java_dev_qingwan_bluedove_BluetoothAdapter_n_1getDefaultAsync
        (JNIEnv *, jclass) {
    auto adapter = BluetoothAdapter::GetDefaultAsync().get();
    auto pAdapter = new BluetoothAdapterWrapper(adapter);
    return reinterpret_cast<jlong>(pAdapter);
}

JNIEXPORT void JNICALL Java_dev_qingwan_bluedove_BluetoothAdapter_n_1releaseAdapter
  (JNIEnv *, jclass, jlong pAdapter)
{
    std::cout << "release" << std::endl;
    delete reinterpret_cast<BluetoothAdapterWrapper*>(pAdapter);
}

JNIEXPORT jstring JNICALL Java_dev_qingwan_bluedove_BluetoothAdapter_n_1getDeviceId
        (JNIEnv* env, jclass, jlong pAdapter) {
    auto* pAdapterWrapper = reinterpret_cast<BluetoothAdapterWrapper*>(pAdapter);
    std::string str = to_string(pAdapterWrapper->value.DeviceId());
    const char* deviceId = str.c_str();
    std::cout << "deviceId: " << deviceId << std::endl;
    return env->NewStringUTF(deviceId);
}

