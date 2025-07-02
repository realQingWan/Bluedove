package dev.qingwan.bluedove;

import dev.qingwan.bluedove.genericAttributeProfile.GattDeviceServicesResult;
import dev.qingwan.bluedove.winrt.AsyncOperation;

import java.util.function.Consumer;

/**
 * Implement of <a href="https://learn.microsoft.com/en-us/uwp/api/windows.devices.bluetooth.bluetoothledevice">BluetoothLEDevice</a>
 */
public class BluetoothLEDevice extends AutoManageWrapper {

    public BluetoothLEDevice(long pointer) {
        super(pointer);
    }

    private static native long n_fromIdAsync(String deviceId);
    private static native long n_fromBluetoothAddressAsync(long address);
    private static native String n_getName(long pointer);
    private static native String n_getDeviceId(long pointer);
    private static native long n_getGattServicesAsync(long pointer);
    private static native long n_listenNameChanged(long pointer, NameChangedListener listener);

    public static AsyncOperation<BluetoothLEDevice> fromIdAsync(String deviceId) {
        long ptr = n_fromIdAsync(deviceId);
        if (ptr == 0) {
            return null;
        }
        return new AsyncOperation<>(ptr, BluetoothLEDevice::new);
    }

    public static AsyncOperation<BluetoothLEDevice> fromBluetoothAddressAsync(long address) {
        long ptr = n_fromBluetoothAddressAsync(address);
        if (ptr == 0) {
            return null;
        }
        return new AsyncOperation<>(ptr, BluetoothLEDevice::new);
    }

    public long listenNameChanged(NameChangedListener listener) {
        return n_listenNameChanged(n_Pointer, listener);
    }

    public long listenNameChanged(Consumer<BluetoothLEDevice> listener) {
        return listenNameChanged(new NameChangedListener() {
            @Override
            protected void onNameChanged(BluetoothLEDevice device) {
                listener.accept(device);
            }
        });
    }

    public abstract static class NameChangedListener extends BaseListener{
        public void callback(long objPointer, long argsPointer) {
            onNameChanged(new BluetoothLEDevice(objPointer));
        }
        protected abstract void onNameChanged(BluetoothLEDevice device);
    }

    public String getName() {
        return n_getName(n_Pointer);
    }

    public String getDeviceId() {
        return n_getDeviceId(n_Pointer);
    }

    public AsyncOperation<GattDeviceServicesResult> getGattServicesAsync() {
        return new AsyncOperation<>(n_getGattServicesAsync(n_Pointer), GattDeviceServicesResult::new);
    }

}
