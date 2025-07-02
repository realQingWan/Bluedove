package dev.qingwan.bluedove;

import dev.qingwan.bluedove.advertisement.BluetoothLEAdvertisementWatcherStatus;

import java.util.Arrays;

/**
 * Implement of <a href="https://learn.microsoft.com/en-us/uwp/api/windows.devices.bluetooth.bluetoothaddresstype">BluetoothAddressType</a>
 */
public enum BluetoothAddressType {
    Public(0),
    Random(1),
    Unspecified(2)
    ;
    public int value;
    BluetoothAddressType(int value) {
        this.value = value;
    }
    public static BluetoothAddressType fromValue(int value) {
        return Arrays.stream(BluetoothAddressType.values())
                .filter(status -> status.value == value)
                .findFirst().orElse(null);
    }
}
