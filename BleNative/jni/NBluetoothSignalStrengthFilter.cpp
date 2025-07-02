#include <winrt/windows.devices.bluetooth.h>
#include <winrt/windows.foundation.h>
#include <iostream>

#include "../jni_generated/dev_qingwan_bluedove_BluetoothSignalStrengthFilter.h"
#include "../Util.h"
#include "Wrapper.h"

using namespace winrt;
using namespace Windows::Devices::Bluetooth;

JNIEXPORT jshort JNICALL Java_dev_qingwan_bluedove_BluetoothSignalStrengthFilter_n_1getInRangeThresholdInDBm
  (JNIEnv *env, jclass, jlong ptr)
{
    auto* pFilterWrapper = reinterpret_cast<Wrapper<BluetoothSignalStrengthFilter>*>(ptr);
    auto value = pFilterWrapper->value.InRangeThresholdInDBm();
    if (value == nullptr)
    {
        env->ThrowNew(env->FindClass("java/lang/IllegalStateException"), "InRangeThresholdInDBm not set");
        return 0;
    }
    return value.Value();
}

JNIEXPORT void JNICALL Java_dev_qingwan_bluedove_BluetoothSignalStrengthFilter_n_1setInRangeThresholdInDBm
  (JNIEnv *, jclass, jlong ptr, jshort value)
{
    auto* pFilterWrapper = reinterpret_cast<Wrapper<BluetoothSignalStrengthFilter>*>(ptr);
    pFilterWrapper->value.InRangeThresholdInDBm(value);
}

JNIEXPORT jshort JNICALL Java_dev_qingwan_bluedove_BluetoothSignalStrengthFilter_n_1getOutOfRangeThresholdInDBm
  (JNIEnv *env, jclass, jlong ptr)
{
    auto* pFilterWrapper = reinterpret_cast<Wrapper<BluetoothSignalStrengthFilter>*>(ptr);
    auto value = pFilterWrapper->value.OutOfRangeThresholdInDBm();
    if (value == nullptr)
    {
        env->ThrowNew(env->FindClass("java/lang/IllegalStateException"), "OutOfRangeThresholdInDBm not set");
        return 0;
    }
    return value.Value();
}

JNIEXPORT void JNICALL Java_dev_qingwan_bluedove_BluetoothSignalStrengthFilter_n_1setOutOfRangeThresholdInDBm
  (JNIEnv *, jclass, jlong ptr, jshort value)
{
    auto* pFilterWrapper = reinterpret_cast<Wrapper<BluetoothSignalStrengthFilter>*>(ptr);
    pFilterWrapper->value.OutOfRangeThresholdInDBm(value);
}

JNIEXPORT void JNICALL Java_dev_qingwan_bluedove_BluetoothSignalStrengthFilter_n_1setOutOfRangeTimeout
  (JNIEnv *, jclass, jlong ptr, jlong ms)
{
    auto* pFilterWrapper = reinterpret_cast<Wrapper<BluetoothSignalStrengthFilter>*>(ptr);
    pFilterWrapper->value.OutOfRangeTimeout(Windows::Foundation::TimeSpan {std::chrono::milliseconds(ms)});
}

JNIEXPORT jlong JNICALL Java_dev_qingwan_bluedove_BluetoothSignalStrengthFilter_n_1getOutOfRangeTimeout
  (JNIEnv *env, jclass, jlong ptr)
{
    auto* pFilterWrapper = reinterpret_cast<Wrapper<BluetoothSignalStrengthFilter>*>(ptr);
    auto value = pFilterWrapper->value.OutOfRangeTimeout();
    if (value == nullptr)
    {
        env->ThrowNew(env->FindClass("java/lang/IllegalStateException"), "OutOfRangeTimeout not set");
        return 0;
    }
    return duration_cast<std::chrono::milliseconds>(value.Value()).count();
}

JNIEXPORT void JNICALL Java_dev_qingwan_bluedove_BluetoothSignalStrengthFilter_n_1setSamplingInterval
  (JNIEnv *, jclass, jlong ptr, jlong ms)
{
    auto* pFilterWrapper = reinterpret_cast<Wrapper<BluetoothSignalStrengthFilter>*>(ptr);
    pFilterWrapper->value.SamplingInterval(Windows::Foundation::TimeSpan {std::chrono::milliseconds(ms)});
}

JNIEXPORT jlong JNICALL Java_dev_qingwan_bluedove_BluetoothSignalStrengthFilter_n_1getSamplingInterval
  (JNIEnv *env, jclass, jlong ptr)
{
    auto* pFilterWrapper = reinterpret_cast<Wrapper<BluetoothSignalStrengthFilter>*>(ptr);
    auto value = pFilterWrapper->value.SamplingInterval();
    if (value == nullptr)
    {
        env->ThrowNew(env->FindClass("java/lang/IllegalStateException"), "SamplingInterval not set");
        return 0;
    }
    return duration_cast<std::chrono::milliseconds>(pFilterWrapper->value.SamplingInterval().Value()).count();
}

