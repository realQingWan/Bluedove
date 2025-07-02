package dev.qingwan.bluedove.genericAttributeProfile;

import dev.qingwan.bluedove.BluetoothAddressType;

import java.util.Arrays;

public enum GattCommunicationStatus {
    Success(0),
    Unreachable(1),
    ProtocolError(2),
    AccessDenied(3)
    ;
    public int value;
    GattCommunicationStatus(int value) {
        this.value = value;
    }
    public static GattCommunicationStatus fromValue(int value) {
        return Arrays.stream(GattCommunicationStatus.values())
                .filter(status -> status.value == value)
                .findFirst().orElse(null);
    }
}
