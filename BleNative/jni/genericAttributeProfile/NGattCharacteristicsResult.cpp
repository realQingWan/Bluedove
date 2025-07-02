#include <winrt/windows.foundation.collections.h>
#include <winrt/windows.devices.bluetooth.genericattributeprofile.h>
#include <iostream>

#include "../../jni_generated/dev_qingwan_bluedove_genericAttributeProfile_GattCharacteristicsResult.h"
#include "../../Util.h"
#include "../Wrapper.h"

using namespace winrt;
using namespace Windows::Devices::Bluetooth::GenericAttributeProfile;
using namespace Windows::Foundation::Collections;

JNIEXPORT jlongArray JNICALL Java_dev_qingwan_bluedove_genericAttributeProfile_GattCharacteristicsResult_n_1getCharacteristics
  (JNIEnv *env, jclass, jlong ptr)
{
    auto* pResultWrapper = reinterpret_cast<Wrapper<GattCharacteristicsResult>*>(ptr);
    IVectorView<GattCharacteristic> services = pResultWrapper->value.Characteristics();

    auto longArray = env->NewLongArray(services.Size());
    std::vector<jlong> pointers(services.Size());
    for (jsize i = 0; i < services.Size(); ++i) {
        auto service = services.GetAt(i);
        auto* pService = new Wrapper(service);
        pointers[i] = reinterpret_cast<jlong>(pService);
    }
    env->SetLongArrayRegion(longArray, 0, services.Size(), pointers.data());
    return longArray;
}

JNIEXPORT jbyte JNICALL Java_dev_qingwan_bluedove_genericAttributeProfile_GattCharacteristicsResult_n_1getProtocolError
  (JNIEnv *, jclass, jlong ptr)
{
    auto* pResultWrapper = reinterpret_cast<Wrapper<GattCharacteristicsResult>*>(ptr);
    return pResultWrapper->value.ProtocolError().Value();
}

JNIEXPORT jint JNICALL Java_dev_qingwan_bluedove_genericAttributeProfile_GattCharacteristicsResult_n_1getStatus
  (JNIEnv *, jclass, jlong ptr)
{
    auto* pResultWrapper = reinterpret_cast<Wrapper<GattCharacteristicsResult>*>(ptr);
    return static_cast<jint>(pResultWrapper->value.Status());
}