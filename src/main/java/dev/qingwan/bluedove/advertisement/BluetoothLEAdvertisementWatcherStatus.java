package dev.qingwan.bluedove.advertisement;

public enum BluetoothLEAdvertisementWatcherStatus {
    Created,
    Started,
    Stopping,
    Stopped,
    Aborted
    ;
    public static BluetoothLEAdvertisementWatcherStatus fromValue(int value) {
        return BluetoothLEAdvertisementWatcherStatus.values()[value];
    }
}
