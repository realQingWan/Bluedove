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
  auto deviceAsync = BluetoothLEDevice::FromIdAsync(deviceId);
  auto pDeviceAsync = new OperationWrapper(deviceAsync);
  return reinterpret_cast<jlong>(pDeviceAsync);
}

JNIEXPORT jlong JNICALL Java_dev_qingwan_bluedove_BluetoothLEDevice_n_1fromBluetoothAddressAsync
  (JNIEnv *, jclass, jlong address)
{
  auto deviceAsync = BluetoothLEDevice::FromBluetoothAddressAsync(address);
  if (deviceAsync == nullptr)
  {
    return 0;
  }
  auto pDeviceAsync = new OperationWrapper(deviceAsync);
  return reinterpret_cast<jlong>(pDeviceAsync);
}

JNIEXPORT jstring JNICALL Java_dev_qingwan_bluedove_BluetoothLEDevice_n_1getName
  (JNIEnv *env, jclass, jlong ptr)
{
  auto* pDeviceWrapper = reinterpret_cast<Wrapper<BluetoothLEDevice>*>(ptr);
  hstring name = pDeviceWrapper->value.Name();
  if (name.empty())
    return nullptr;
  return HStringToJString(env, pDeviceWrapper->value.Name());
}

JNIEXPORT jstring JNICALL Java_dev_qingwan_bluedove_BluetoothLEDevice_n_1getDeviceId
  (JNIEnv *env, jclass, jlong ptr)
{
  auto* pDeviceWrapper = reinterpret_cast<Wrapper<BluetoothLEDevice>*>(ptr);
  return HStringToJString(env, pDeviceWrapper->value.DeviceId());
}

JNIEXPORT jlong JNICALL Java_dev_qingwan_bluedove_BluetoothLEDevice_n_1getGattServicesAsync
  (JNIEnv *, jclass, jlong ptr)
{
  auto* pDeviceWrapper = reinterpret_cast<Wrapper<BluetoothLEDevice>*>(ptr);
  auto servicesOperation = pDeviceWrapper->value.GetGattServicesAsync();
  auto* pServicesOperation = new OperationWrapper(servicesOperation);
  return reinterpret_cast<jlong>(pServicesOperation);
}
