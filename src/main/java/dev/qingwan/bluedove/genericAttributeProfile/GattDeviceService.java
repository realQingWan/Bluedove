package dev.qingwan.bluedove.genericAttributeProfile;

import dev.qingwan.bluedove.AutoManageWrapper;
import dev.qingwan.bluedove.winrt.AsyncOperation;
import dev.qingwan.bluedove.winrt.GUID;

public class GattDeviceService extends AutoManageWrapper {
    public GattDeviceService(long pointer) {
        super(pointer);
    }

    private static native long n_getUuid(long pointer);
    private static native long n_getCharacteristicsAsync(long pointer);

    public GUID getUuid() {
        return new GUID(n_getUuid(n_Pointer));
    }

    public AsyncOperation<GattCharacteristicsResult> getCharacteristicsAsync() {
        return new AsyncOperation<>(n_getCharacteristicsAsync(n_Pointer), GattCharacteristicsResult::new);
    }

    public String toString() {
        return String.format("GattDeviceService(n_Pointer=%d)", n_Pointer);
    }
}
