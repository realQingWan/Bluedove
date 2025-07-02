#include <winrt/windows.devices.bluetooth.advertisement.h>
#include <winrt/windows.foundation.h>
#include <iostream>

#include "../../jni_generated/dev_qingwan_bluedove_advertisement_BluetoothLEAdvertisementWatcher.h"
#include "../../Util.h"
#include "../Wrapper.h"

using namespace winrt;
using namespace Windows::Devices::Bluetooth::Advertisement;

JNIEXPORT jlong JNICALL Java_dev_qingwan_bluedove_advertisement_BluetoothLEAdvertisementWatcher_n_1newWatcher
  (JNIEnv *, jclass)
{
    auto watcher = BluetoothLEAdvertisementWatcher();
    auto pWatcher = new Wrapper(watcher);
    return reinterpret_cast<jlong>(pWatcher);
}

JNIEXPORT jint JNICALL Java_dev_qingwan_bluedove_advertisement_BluetoothLEAdvertisementWatcher_n_1getStatus
  (JNIEnv *, jclass, jlong ptr)
{
    auto* pWatcherWrapper = reinterpret_cast<Wrapper<BluetoothLEAdvertisementWatcher>*>(ptr);
    return static_cast<jint>(pWatcherWrapper->value.Status());
}

JNIEXPORT jlong JNICALL Java_dev_qingwan_bluedove_advertisement_BluetoothLEAdvertisementWatcher_n_1listenReceived
  (JNIEnv *env, jclass, jlong ptr, jobject listener)
{
    auto* pWatcherWrapper = reinterpret_cast<Wrapper<BluetoothLEAdvertisementWatcher>*>(ptr);
    auto pWrappedListener = std::make_shared<WrappedListener<BluetoothLEAdvertisementWatcher, BluetoothLEAdvertisementReceivedEventArgs>>(env
        , listener, "dev/qingwan/bluedove/advertisement/BluetoothLEAdvertisementWatcher$BluetoothLEAdvertisementReceivedListener");
    auto token = pWatcherWrapper->value.Received([pWrappedListener](auto&&... args) { (*pWrappedListener)(args...); });
    auto* pToken = new Wrapper(token);
    return reinterpret_cast<jlong>(pToken);
}

JNIEXPORT void JNICALL Java_dev_qingwan_bluedove_advertisement_BluetoothLEAdvertisementWatcher_n_1revokeReceivedListener
  (JNIEnv *, jclass, jlong ptr_watcher, jlong ptr_token)
{
    auto* pWatcherWrapper = reinterpret_cast<Wrapper<BluetoothLEAdvertisementWatcher>*>(ptr_watcher);
    auto* pTokenWrapper = reinterpret_cast<Wrapper<event_token>*>(ptr_token);
    pWatcherWrapper->value.Received(pTokenWrapper->value);
    delete pTokenWrapper;
}

JNIEXPORT void JNICALL Java_dev_qingwan_bluedove_advertisement_BluetoothLEAdvertisementWatcher_n_1start
  (JNIEnv *, jclass, jlong ptr)
{
    auto* pWatcherWrapper = reinterpret_cast<Wrapper<BluetoothLEAdvertisementWatcher>*>(ptr);
    pWatcherWrapper->value.Start();
}

JNIEXPORT void JNICALL Java_dev_qingwan_bluedove_advertisement_BluetoothLEAdvertisementWatcher_n_1stop
  (JNIEnv *, jclass, jlong ptr)
{
    auto* pWatcherWrapper = reinterpret_cast<Wrapper<BluetoothLEAdvertisementWatcher>*>(ptr);
    pWatcherWrapper->value.Stop();
}

JNIEXPORT void JNICALL Java_dev_qingwan_bluedove_advertisement_BluetoothLEAdvertisementWatcher_n_1setScanningMode
  (JNIEnv *, jclass, jlong ptr, jint mode)
{
    auto* pWatcherWrapper = reinterpret_cast<Wrapper<BluetoothLEAdvertisementWatcher>*>(ptr);
    pWatcherWrapper->value.ScanningMode(static_cast<BluetoothLEScanningMode>(mode));
}

JNIEXPORT jint JNICALL Java_dev_qingwan_bluedove_advertisement_BluetoothLEAdvertisementWatcher_n_1getScanningMode
  (JNIEnv *, jclass, jlong ptr)
{
    auto* pWatcherWrapper = reinterpret_cast<Wrapper<BluetoothLEAdvertisementWatcher>*>(ptr);
    return static_cast<jint>(pWatcherWrapper->value.ScanningMode());
}

JNIEXPORT jlong JNICALL Java_dev_qingwan_bluedove_advertisement_BluetoothLEAdvertisementWatcher_n_1getSignalStrengthFilter
  (JNIEnv *, jclass, jlong ptr)
{
    auto* pWatcherWrapper = reinterpret_cast<Wrapper<BluetoothLEAdvertisementWatcher>*>(ptr);
    auto signalStrengthFilter = pWatcherWrapper->value.SignalStrengthFilter();
    auto* pFilterWrapper = new Wrapper(signalStrengthFilter);
    return reinterpret_cast<jlong>(pFilterWrapper);
}