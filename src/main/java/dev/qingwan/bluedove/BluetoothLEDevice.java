package dev.qingwan.bluedove;

/**
 * Implement of <a href="https://learn.microsoft.com/en-us/uwp/api/windows.devices.bluetooth.bluetoothledevice">BluetoothLEDevice</a>
 */
public class BluetoothLEDevice implements AutoCloseable {

    private final long n_Pointer;
    private BluetoothLEDevice(long pointer) {
        this.n_Pointer = pointer;
    }

    private static native long n_fromIdAsync(String deviceId);
    private static native void n_releaseDevice(long pointer);



    public static BluetoothLEDevice fromIdAsync(String deviceId) {
        long ptr = n_fromIdAsync(deviceId);
        if (ptr == 0) {
            return null;
        }
        return new BluetoothLEDevice(ptr);
    }

    @Override
    public void close(){
        n_releaseDevice(n_Pointer);
    }
}
