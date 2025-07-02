#include <winrt/windows.foundation.h>
#include <iostream>

#include "../../jni_generated/dev_qingwan_bluedove_winrt_AsyncOperation.h"
#include "../../Util.h"
#include "../Wrapper.h"

using namespace winrt;
using namespace Windows::Foundation;

JNIEXPORT jlong JNICALL Java_dev_qingwan_bluedove_winrt_AsyncOperation_n_1get
  (JNIEnv *env, jclass, jlong ptr)
{
  auto* pOperationWrapper = reinterpret_cast<IOperationWrapper*>(ptr);
  return pOperationWrapper->getResultAsJlong(env);
}

