#include <winrt/windows.foundation.collections.h>
#include <winrt/windows.devices.bluetooth.genericattributeprofile.h>
#include <iostream>

#include "../../jni_generated/dev_qingwan_bluedove_genericAttributeProfile_GattDeviceServicesResult.h"
#include "../../Util.h"
#include "../Wrapper.h"

using namespace winrt;
using namespace Windows::Devices::Bluetooth::GenericAttributeProfile;
using namespace Windows::Foundation::Collections;

JNIEXPORT jlongArray JNICALL Java_dev_qingwan_bluedove_genericAttributeProfile_GattDeviceServicesResult_n_1getServices
  (JNIEnv *env, jclass, jlong ptr)
{
    auto* pResultWrapper = reinterpret_cast<Wrapper<GattDeviceServicesResult>*>(ptr);
    IVectorView<GattDeviceService> services = pResultWrapper->value.Services();

    auto longArray = env->NewLongArray(services.Size());
    std::vector<jlong> pointers(services.Size());
    for (jsize i = 0; i < services.Size(); ++i) {
        auto service = services.GetAt(i);
        auto* pService = new Wrapper<GattDeviceService>(service);
        pointers[i] = reinterpret_cast<jlong>(pService);
    }
    env->SetLongArrayRegion(longArray, 0, services.Size(), pointers.data());
    return longArray;
}

JNIEXPORT jbyte JNICALL Java_dev_qingwan_bluedove_genericAttributeProfile_GattDeviceServicesResult_n_1getProtocolError
  (JNIEnv *, jclass, jlong ptr)
{
    auto* pResultWrapper = reinterpret_cast<Wrapper<GattDeviceServicesResult>*>(ptr);
    return pResultWrapper->value.ProtocolError().Value();
}

JNIEXPORT jint JNICALL Java_dev_qingwan_bluedove_genericAttributeProfile_GattDeviceServicesResult_n_1getStatus
  (JNIEnv *, jclass, jlong ptr)
{
    auto* pResultWrapper = reinterpret_cast<Wrapper<GattDeviceServicesResult>*>(ptr);
    return static_cast<jint>(pResultWrapper->value.Status());
}