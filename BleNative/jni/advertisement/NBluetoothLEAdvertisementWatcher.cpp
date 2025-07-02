#include <winrt/windows.devices.bluetooth.advertisement.h>
#include <winrt/windows.foundation.h>
#include <iostream>

#include "../../jni_generated/dev_qingwan_bluedove_advertisement_BluetoothLEAdvertisementWatcher.h"
#include "../../Util.h"
#include "../Wrapper.h"

using namespace winrt;
using namespace Windows::Devices::Bluetooth::Advertisement;

class WrappedReceivedListener : JNIEnvWrapper
{
private:
    jobject listener;
public:
    mutable event_token token;

public:
    WrappedReceivedListener(JNIEnv* env, jobject listener): JNIEnvWrapper(env)
    {
        std::cout << "create WrappedReceivedListener" << std::endl;
        this->listener = env->NewGlobalRef(listener);
    }

    ~WrappedReceivedListener()
    {
        std::cout << "delete WrappedReceivedListener" << std::endl;
        context([this](JNIEnv* env)
        {
            env->DeleteGlobalRef(listener);
        });
    }

    void operator()(BluetoothLEAdvertisementWatcher const& watcher, BluetoothLEAdvertisementReceivedEventArgs const& args)
    {
        context([this,args](JNIEnv* env)
        {
            jclass clazz = env->FindClass("dev/qingwan/bluedove/advertisement/BluetoothLEAdvertisementWatcher$BluetoothLEAdvertisementReceivedListener");
            jmethodID callback = env->GetMethodID(clazz, "callback", "(J)V");
            auto pArgs = new Wrapper(args);
            env->CallVoidMethod(listener, callback, reinterpret_cast<jlong>(pArgs));
        });
    }
};

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
    auto pWrappedListener = std::make_shared<WrappedReceivedListener>(env, listener);
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