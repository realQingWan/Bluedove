#include <winrt/windows.devices.bluetooth.h>
#include <winrt/windows.foundation.h>
#include <iostream>

#include "../jni_generated/dev_qingwan_bluedove_BluetoothUuidHelper.h"
#include "../Util.h"
#include "Wrapper.h"

using namespace winrt;
using namespace Windows::Devices::Bluetooth;

JNIEXPORT jlong JNICALL Java_dev_qingwan_bluedove_BluetoothUuidHelper_n_1fromShortId
  (JNIEnv *, jclass, jint value)
{
    auto uuid = BluetoothUuidHelper::FromShortId(value);
    auto* pUuidWrapper = new Wrapper(uuid);
    return reinterpret_cast<jlong>(pUuidWrapper);
}