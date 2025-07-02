package dev.qingwan.bluedove.advertisement;

import dev.qingwan.bluedove.AutoManageWrapper;

public class BluetoothLEAdvertisement extends AutoManageWrapper {
    public BluetoothLEAdvertisement(long pointer) {
        super(pointer);
    }

    private static native String n_getLocalName(long pointer);

    public String getLocalName() {
        return n_getLocalName(n_Pointer);
    }
}
