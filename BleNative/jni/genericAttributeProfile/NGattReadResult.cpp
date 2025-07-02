#include <winrt/windows.foundation.collections.h>
#include <winrt/windows.devices.bluetooth.genericattributeprofile.h>
#include <winrt/Windows.Storage.Streams.h>
#include <iostream>

#include "../../jni_generated/dev_qingwan_bluedove_genericAttributeProfile_GattReadResult.h"
#include "../../Util.h"
#include "../Wrapper.h"

using namespace winrt;
using namespace Windows::Devices::Bluetooth::GenericAttributeProfile;
using namespace Windows::Storage::Streams;
using namespace Windows::Foundation::Collections;

JNIEXPORT jbyte JNICALL Java_dev_qingwan_bluedove_genericAttributeProfile_GattReadResult_n_1getProtocolError
  (JNIEnv *, jclass, jlong ptr)
{
  auto* pResultWrapper = reinterpret_cast<Wrapper<GattReadResult>*>(ptr);
  return pResultWrapper->value.ProtocolError().Value();
}

JNIEXPORT jint JNICALL Java_dev_qingwan_bluedove_genericAttributeProfile_GattReadResult_n_1getStatus
  (JNIEnv *, jclass, jlong ptr)
{
  auto* pResultWrapper = reinterpret_cast<Wrapper<GattReadResult>*>(ptr);
  return static_cast<jint>(pResultWrapper->value.Status());
}

JNIEXPORT jbyteArray JNICALL Java_dev_qingwan_bluedove_genericAttributeProfile_GattReadResult_n_1getValue
  (JNIEnv *env, jclass, jlong ptr)
{
  auto* pResultWrapper = reinterpret_cast<Wrapper<GattReadResult>*>(ptr);
  IBuffer buffer = pResultWrapper->value.Value();
  auto reader = DataReader::FromBuffer(buffer);
  try {
    uint32_t length = reader.UnconsumedBufferLength();
    jbyteArray result = env->NewByteArray(length);

    if (length > 0) {
      env->SetByteArrayRegion(result, 0, length,
                            reinterpret_cast<const jbyte*>(reader.DetachBuffer().data()));
    }

    return result;
  } catch (...) {
    env->ThrowNew(env->FindClass("java/lang/RuntimeException"),
                 "Failed to read buffer data");
    return nullptr;
  }
}