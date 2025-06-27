#include <winrt/windows.devices.bluetooth.advertisement.h>
#include <winrt/windows.foundation.h>
#include <iostream>

#include "../../jni_generated/dev_qingwan_bluedove_advertisement_BluetoothLEAdvertisementWatcher.h"
#include "../../Util.h"
#include "../Wrapper.h"

using namespace winrt;
using namespace Windows::Devices::Bluetooth::Advertisement;

class WrappedReceivedListener
{
private:
    JavaVM* jvm;
    jobject javaListener;
    JNIEnv* getEnv() {
        JNIEnv* env;
        jvm->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION_1_6);
        return env;
    }
public:
    WrappedReceivedListener(JavaVM* vm, jobject listener)
    {
        JNIEnv* env = getEnv();
        javaListener = env->NewGlobalRef(listener);
    }
    ~WrappedReceivedListener() {
        if (javaListener) {
            JNIEnv* env = getEnv();
            env->DeleteGlobalRef(javaListener);
        }
    }
    void operator()(BluetoothLEAdvertisementWatcher const& watcher, BluetoothLEAdvertisementReceivedEventArgs const& args)
    {
        JNIEnv* env = getEnv();
    }
};

JNIEXPORT jlong JNICALL Java_dev_qingwan_bluedove_advertisement_BluetoothLEAdvertisementWatcher_n_1newWatcher
  (JNIEnv *, jclass)
{
    auto watcher = BluetoothLEAdvertisementWatcher();
    auto pWatcher = new Wrapper(watcher);
    return reinterpret_cast<jlong>(pWatcher);
}

JNIEXPORT void JNICALL Java_dev_qingwan_bluedove_advertisement_BluetoothLEAdvertisementWatcher_n_1releaseWatcher
  (JNIEnv *, jclass, jlong ptr)
{
    delete reinterpret_cast<Wrapper<BluetoothLEAdvertisementWatcher>*>(ptr);
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
    JavaVM* jvm;
    env->GetJavaVM(&jvm);
    auto wrappedListener = WrappedReceivedListener(jvm, env->NewGlobalRef(listener));

    auto token = pWatcherWrapper->value.Received(wrappedListener);
    return static_cast<jlong>(token.value);
}