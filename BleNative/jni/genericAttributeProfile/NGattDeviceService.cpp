#include <winrt/windows.foundation.collections.h>
#include <winrt/windows.devices.bluetooth.genericattributeprofile.h>
#include <iostream>

#include "../../jni_generated/dev_qingwan_bluedove_genericAttributeProfile_GattDeviceService.h"
#include "../../Util.h"
#include "../Wrapper.h"

using namespace winrt;
using namespace Windows::Devices::Bluetooth::GenericAttributeProfile;
using namespace Windows::Foundation::Collections;

JNIEXPORT jlong JNICALL Java_dev_qingwan_bluedove_genericAttributeProfile_GattDeviceService_n_1getUuid
  (JNIEnv *, jclass, jlong ptr)
{
  auto* pServiceWrapper = reinterpret_cast<Wrapper<GattDeviceService>*>(ptr);
  return reinterpret_cast<jlong>(new Wrapper(pServiceWrapper->value.Uuid()));
}

JNIEXPORT jlong JNICALL Java_dev_qingwan_bluedove_genericAttributeProfile_GattDeviceService_n_1getCharacteristicsAsync
  (JNIEnv *, jclass, jlong ptr)
{
  auto* pServiceWrapper = reinterpret_cast<Wrapper<GattDeviceService>*>(ptr);
  auto characteristicsOpreation = pServiceWrapper->value.GetCharacteristicsAsync();
  auto pCharacteristicsOpreationWrapper = new OperationWrapper(characteristicsOpreation);
  return reinterpret_cast<jlong>(pCharacteristicsOpreationWrapper);
}