#ifndef BLENATIVE_UTIL_H
#define BLENATIVE_UTIL_H
#include <jni.h>
#include <winrt/base.h>


winrt::hstring JStringToHString(JNIEnv *, jstring);

#endif //BLENATIVE_UTIL_H
