#include <winrt/windows.devices.bluetooth.advertisement.h>
#include <winrt/windows.foundation.h>
#include <iostream>

#include "../../jni_generated/dev_qingwan_bluedove_advertisement_BluetoothLEAdvertisementWatcher_BluetoothLEAdvertisementReceivedEventArgs.h"
#include "../../Util.h"
#include "../Wrapper.h"

using namespace winrt;
using namespace Windows::Devices::Bluetooth::Advertisement;

JNIEXPORT jlong JNICALL Java_dev_qingwan_bluedove_advertisement_BluetoothLEAdvertisementWatcher_00024BluetoothLEAdvertisementReceivedEventArgs_n_1getBluetoothAddress
  (JNIEnv *, jclass, jlong ptr)
{
    auto* pAdapterWrapper = reinterpret_cast<Wrapper<BluetoothLEAdvertisementReceivedEventArgs>*>(ptr);
    return static_cast<int64_t>(pAdapterWrapper->value.BluetoothAddress());
}

JNIEXPORT jlong JNICALL Java_dev_qingwan_bluedove_advertisement_BluetoothLEAdvertisementWatcher_00024BluetoothLEAdvertisementReceivedEventArgs_n_1getAdvertisement
  (JNIEnv *, jclass, jlong ptr)
{
    auto* pAdapterWrapper = reinterpret_cast<Wrapper<BluetoothLEAdvertisementReceivedEventArgs>*>(ptr);
    return reinterpret_cast<jlong>(new Wrapper(pAdapterWrapper->value.Advertisement()));
}