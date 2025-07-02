#include <winrt/windows.devices.bluetooth.h>
#include <winrt/windows.foundation.h>
#include <iostream>
#include "../Util.h"

#include "../jni_generated/dev_qingwan_bluedove_Native.h"
#include "Wrapper.h"

JNIEXPORT void JNICALL Java_dev_qingwan_bluedove_Native_n_1releaseObject
  (JNIEnv *, jclass, jlong ptr)
{
  delete reinterpret_cast<IWrapper*>(ptr);
}