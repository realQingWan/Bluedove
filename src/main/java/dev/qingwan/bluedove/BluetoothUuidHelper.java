package dev.qingwan.bluedove;

import dev.qingwan.bluedove.winrt.GUID;

public class BluetoothUuidHelper {

    private static native long n_fromShortId(int shortId);

    public static GUID fromShortId(int shortId) {
        return new GUID(n_fromShortId(shortId));
    }
}
