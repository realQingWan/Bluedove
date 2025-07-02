package dev.qingwan.bluedove.genericAttributeProfile;

import dev.qingwan.bluedove.AutoManageWrapper;

import java.util.Arrays;
import java.util.List;

public class GattCharacteristicsResult extends AutoManageWrapper {
    public GattCharacteristicsResult(long pointer) {
        super(pointer);
    }

    private static native long[] n_getCharacteristics(long pointer);
    private static native byte n_getProtocolError(long pointer);
    private static native int n_getStatus(long pointer);

    public List<GattCharacteristic> getServices() {
        return Arrays.stream(n_getCharacteristics(n_Pointer)).mapToObj(GattCharacteristic::new).toList();
    }
    public byte ProtocolError() {
        return n_getProtocolError(n_Pointer);
    }
    public GattCommunicationStatus getStatus(){
        return GattCommunicationStatus.fromValue(n_getStatus(n_Pointer));
    }
}
