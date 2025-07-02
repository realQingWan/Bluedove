package dev.qingwan.bluedove.advertisement;

import java.util.Arrays;

public enum BluetoothLEAdvertisementWatcherStatus {
    Created(0),
    Started(1),
    Stopping(2),
    Stopped(3),
    Aborted(4)
    ;
    public int value;
    BluetoothLEAdvertisementWatcherStatus(int value) {
        this.value = value;
    }
    public static BluetoothLEAdvertisementWatcherStatus fromValue(int value) {
        return Arrays.stream(BluetoothLEAdvertisementWatcherStatus.values())
                .filter(status -> status.value == value)
                .findFirst().orElse(null);
    }

}
