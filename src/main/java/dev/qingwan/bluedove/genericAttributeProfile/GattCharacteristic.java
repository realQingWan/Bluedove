package dev.qingwan.bluedove.genericAttributeProfile;

import dev.qingwan.bluedove.AutoManageWrapper;
import dev.qingwan.bluedove.winrt.AsyncOperation;
import dev.qingwan.bluedove.winrt.GUID;

public class GattCharacteristic extends AutoManageWrapper {
    public GattCharacteristic(long pointer) {
        super(pointer);
    }

    private static native long n_getUuid(long pointer);
    private static native long n_readValueAsync(long pointer);


    public GUID getUuid() {
        return new GUID(n_getUuid(n_Pointer));
    }

    public AsyncOperation<GattReadResult> readValueAsync() {
        return new AsyncOperation<>(n_readValueAsync(n_Pointer), GattReadResult::new);
    }

}
