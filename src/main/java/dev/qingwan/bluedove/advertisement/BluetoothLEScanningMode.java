package dev.qingwan.bluedove.advertisement;

import java.util.Arrays;

public enum BluetoothLEScanningMode {
    Passive(0),
    Active(1),
    None(2)
    ;
    public int value;
    BluetoothLEScanningMode(int value) {
        this.value = value;
    }
    public static BluetoothLEScanningMode fromValue(int value) {
        return Arrays.stream(BluetoothLEScanningMode.values())
                .filter(status -> status.value == value)
                .findFirst().orElse(null);
    }
}
