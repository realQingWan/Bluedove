package dev.qingwan.bluedove.genericAttributeProfile;

import dev.qingwan.bluedove.AutoManageWrapper;

import java.util.Arrays;
import java.util.List;

public class GattDeviceServicesResult extends AutoManageWrapper {
    public GattDeviceServicesResult(long pointer) {
        super(pointer);
    }

    private static native long[] n_getServices(long pointer);
    private static native byte n_getProtocolError(long pointer);
    private static native int n_getStatus(long pointer);

    public List<GattDeviceService> getServices() {
        return Arrays.stream(n_getServices(n_Pointer)).mapToObj(GattDeviceService::new).toList();
    }
    public byte ProtocolError() {
        return n_getProtocolError(n_Pointer);
    }
    public GattCommunicationStatus getStatus(){
        return GattCommunicationStatus.fromValue(n_getStatus(n_Pointer));
    }
}
