#include <winrt/windows.foundation.h>
#include <iostream>

#include "../../jni_generated/dev_qingwan_bluedove_winrt_GUID.h"
#include "../../Util.h"
#include "../Wrapper.h"

using namespace winrt;

JNIEXPORT jboolean JNICALL Java_dev_qingwan_bluedove_winrt_GUID_n_1equals
  (JNIEnv *, jclass, jlong ptr1, jlong ptr2)
{
    auto guid1 = reinterpret_cast<Wrapper<guid>*>(ptr1);
    auto guid2 = reinterpret_cast<Wrapper<guid>*>(ptr2);
    return guid1->value == guid2->value;
}