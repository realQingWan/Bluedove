#include <winrt/windows.devices.bluetooth.h>
#include <winrt/windows.foundation.h>
#include <iostream>
#include "../Util.h"

#include "../jni_generated/dev_qingwan_bluedove_BluetoothAdapter.h"
#include "Wrapper.h"

using namespace winrt;
using namespace Windows::Devices::Bluetooth;

struct BluetoothAdapterWrapper
{
    BluetoothAdapter value;
};

JNIEXPORT jlong JNICALL Java_dev_qingwan_bluedove_BluetoothAdapter_n_1getDefaultAsync
        (JNIEnv *, jclass)
{
    auto adapter = BluetoothAdapter::GetDefaultAsync().get();
    auto pAdapter = new Wrapper(adapter);
    return reinterpret_cast<jlong>(pAdapter);
}

JNIEXPORT void JNICALL Java_dev_qingwan_bluedove_BluetoothAdapter_n_1releaseAdapter
  (JNIEnv *, jclass, jlong ptr)
{
    delete reinterpret_cast<Wrapper<BluetoothAdapter>*>(ptr);
}

JNIEXPORT jboolean JNICALL Java_dev_qingwan_bluedove_BluetoothAdapter_n_1isAdvertisementOffloadSupported
  (JNIEnv *, jclass, jlong ptr)
{
    auto* pAdapterWrapper = reinterpret_cast<Wrapper<BluetoothAdapter>*>(ptr);
    return pAdapterWrapper->value.IsAdvertisementOffloadSupported();
}

JNIEXPORT jboolean JNICALL Java_dev_qingwan_bluedove_BluetoothAdapter_n_1isCentralRoleSupported
  (JNIEnv *, jclass, jlong ptr)
{
    auto* pAdapterWrapper = reinterpret_cast<Wrapper<BluetoothAdapter>*>(ptr);
    return pAdapterWrapper->value.IsCentralRoleSupported();
}

JNIEXPORT jboolean JNICALL Java_dev_qingwan_bluedove_BluetoothAdapter_n_1isClassicSupported
  (JNIEnv *, jclass, jlong ptr)
{
    auto* pAdapterWrapper = reinterpret_cast<Wrapper<BluetoothAdapter>*>(ptr);
    return pAdapterWrapper->value.IsClassicSupported();
}

JNIEXPORT jboolean JNICALL Java_dev_qingwan_bluedove_BluetoothAdapter_n_1isExtendedAdvertisingSupported
  (JNIEnv *, jclass, jlong ptr)
{
    auto* pAdapterWrapper = reinterpret_cast<Wrapper<BluetoothAdapter>*>(ptr);
    return pAdapterWrapper->value.IsExtendedAdvertisingSupported();
}

JNIEXPORT jboolean JNICALL Java_dev_qingwan_bluedove_BluetoothAdapter_n_1isLowEnergyCodedPhySupported
  (JNIEnv *, jclass, jlong ptr)
{
    auto* pAdapterWrapper = reinterpret_cast<Wrapper<BluetoothAdapter>*>(ptr);
    return pAdapterWrapper->value.IsLowEnergyCodedPhySupported();
}

JNIEXPORT jboolean JNICALL Java_dev_qingwan_bluedove_BluetoothAdapter_n_1isLowEnergySupported
  (JNIEnv *, jclass, jlong ptr)
{
    auto* pAdapterWrapper = reinterpret_cast<Wrapper<BluetoothAdapter>*>(ptr);
    return pAdapterWrapper->value.IsLowEnergySupported();
}

JNIEXPORT jstring JNICALL Java_dev_qingwan_bluedove_BluetoothAdapter_n_1getDeviceId
        (JNIEnv* env, jclass, jlong ptr)
{
    auto* pAdapterWrapper = reinterpret_cast<Wrapper<BluetoothAdapter>*>(ptr);
    std::string str = to_string(pAdapterWrapper->value.DeviceId());
    const char* deviceId = str.c_str();
    std::cout << "deviceId: " << deviceId << std::endl;
    return env->NewStringUTF(deviceId);
}

JNIEXPORT jboolean JNICALL Java_dev_qingwan_bluedove_BluetoothAdapter_n_1isLowEnergyUncoded2MPhySupported
  (JNIEnv *, jclass, jlong ptr)
{
    auto* pAdapterWrapper = reinterpret_cast<Wrapper<BluetoothAdapter>*>(ptr);
    return pAdapterWrapper->value.IsLowEnergyUncoded2MPhySupported();
}

JNIEXPORT jboolean JNICALL Java_dev_qingwan_bluedove_BluetoothAdapter_n_1isPeripheralRoleSupported
  (JNIEnv *, jclass, jlong ptr)
{
    auto* pAdapterWrapper = reinterpret_cast<Wrapper<BluetoothAdapter>*>(ptr);
    return pAdapterWrapper->value.IsPeripheralRoleSupported();
}

JNIEXPORT jint JNICALL Java_dev_qingwan_bluedove_BluetoothAdapter_n_1getMaxAdvertisementDataLength
  (JNIEnv *, jclass, jlong ptr)
{
    auto* pAdapterWrapper = reinterpret_cast<Wrapper<BluetoothAdapter>*>(ptr);
    std::cout << "MaxAdvertisementDataLength: " << pAdapterWrapper->value.MaxAdvertisementDataLength() << std::endl;
    return static_cast<int32_t>(pAdapterWrapper->value.MaxAdvertisementDataLength());
}

JNIEXPORT jlong JNICALL Java_dev_qingwan_bluedove_BluetoothAdapter_n_1getBluetoothAddress
  (JNIEnv *, jclass, jlong ptr)
{
    auto* pAdapterWrapper = reinterpret_cast<Wrapper<BluetoothAdapter>*>(ptr);
    std::cout << "BluetoothAddress: " << pAdapterWrapper->value.BluetoothAddress() << std::endl;
    return static_cast<int64_t>(pAdapterWrapper->value.BluetoothAddress());
}

JNIEXPORT jlong JNICALL Java_dev_qingwan_bluedove_BluetoothAdapter_n_1getRadioAsync
  (JNIEnv *, jclass, jlong ptr)
{
    auto* pAdapterWrapper = reinterpret_cast<Wrapper<BluetoothAdapter>*>(ptr);
    auto pRadioWrapper = new Wrapper(pAdapterWrapper->value.GetRadioAsync().get());
    return reinterpret_cast<jlong>(pRadioWrapper);
}
