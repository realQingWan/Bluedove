package dev.qingwan.bluedove.genericAttributeProfile;

import dev.qingwan.bluedove.AutoManageWrapper;

import java.nio.ByteBuffer;
import java.util.Arrays;
import java.util.List;

public class GattReadResult extends AutoManageWrapper {
    public GattReadResult(long pointer) {
        super(pointer);
    }

    private static native byte[] n_getValue(long pointer);
    private static native byte n_getProtocolError(long pointer);
    private static native int n_getStatus(long pointer);

    public ByteBuffer getValue() {
        byte[] array = n_getValue(n_Pointer);
        if (array == null)
            return null;
        return ByteBuffer.wrap(array);
    }
    public byte ProtocolError() {
        return n_getProtocolError(n_Pointer);
    }
    public GattCommunicationStatus getStatus(){
        return GattCommunicationStatus.fromValue(n_getStatus(n_Pointer));
    }
}
