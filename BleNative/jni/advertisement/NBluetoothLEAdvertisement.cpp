#include <winrt/windows.devices.bluetooth.advertisement.h>
#include <winrt/windows.foundation.h>
#include <iostream>

#include "../../jni_generated/dev_qingwan_bluedove_advertisement_BluetoothLEAdvertisement.h"
#include "../../Util.h"
#include "../Wrapper.h"

using namespace winrt;
using namespace Windows::Devices::Bluetooth::Advertisement;

JNIEXPORT jstring JNICALL Java_dev_qingwan_bluedove_advertisement_BluetoothLEAdvertisement_n_1getLocalName
  (JNIEnv *env, jclass, jlong ptr)
{
    auto* pAdvertisementWrapper = reinterpret_cast<Wrapper<BluetoothLEAdvertisement>*>(ptr);
    return HStringToJString(env, pAdvertisementWrapper->value.LocalName());
}