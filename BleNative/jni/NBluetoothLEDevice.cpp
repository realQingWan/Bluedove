#include <winrt/windows.devices.bluetooth.h>
#include <winrt/windows.foundation.h>
#include <iostream>

#include "../jni_generated/dev_qingwan_bluedove_BluetoothLEDevice.h"
#include "../Util.h"
#include "Wrapper.h"

using namespace winrt;
using namespace Windows::Devices::Bluetooth;

JNIEXPORT jlong JNICALL Java_dev_qingwan_bluedove_BluetoothLEDevice_n_1fromIdAsync
  (JNIEnv *env, jclass, jstring jDeviceId)
{
  hstring deviceId = JStringToHString(env, jDeviceId);
  if (deviceId.empty())
  {
    return 0;
  }
  auto device = BluetoothLEDevice::FromIdAsync(deviceId).get();
  auto pDevice = new Wrapper(device);
  return reinterpret_cast<jlong>(pDevice);
}

JNIEXPORT void JNICALL Java_dev_qingwan_bluedove_BluetoothLEDevice_n_1releaseDevice
  (JNIEnv *, jclass, jlong ptr)
{
  delete reinterpret_cast<Wrapper<BluetoothLEDevice>*>(ptr);
}

