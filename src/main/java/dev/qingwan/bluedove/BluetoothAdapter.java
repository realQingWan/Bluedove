package dev.qingwan.bluedove;

/**
 * Implement of <a href="https://learn.microsoft.com/en-us/uwp/api/windows.devices.bluetooth.bluetoothadapter">BluetoothAdapter</a>
 */
public class BluetoothAdapter implements AutoCloseable {
    private final long n_Pointer;
    private BluetoothAdapter(long pointer) {
        this.n_Pointer = pointer;
    }
    private static native long n_getDefaultAsync();
    private static native void n_releaseAdapter(long pointer);
    private static native String n_getDeviceId(long pointer);
    private static native boolean n_isAdvertisementOffloadSupported(long pointer);
    private static native boolean n_isCentralRoleSupported(long pointer);
    private static native boolean n_isClassicSupported(long pointer);
    private static native boolean n_isExtendedAdvertisingSupported(long pointer);
    private static native boolean n_isLowEnergyCodedPhySupported(long pointer);
    private static native boolean n_isLowEnergySupported(long pointer);
    private static native boolean n_isLowEnergyUncoded2MPhySupported(long pointer);
    private static native boolean n_isPeripheralRoleSupported(long pointer);
    private static native int n_getMaxAdvertisementDataLength(long pointer);
    private static native long n_getBluetoothAddress(long pointer);
    private static native long n_getRadioAsync(long pointer);

    public String getDeviceId() {
        return n_getDeviceId(n_Pointer);
    }

    public static BluetoothAdapter getDefaultAsync() {
        long ptr = n_getDefaultAsync();
        if (ptr == 0) {
            throw new IllegalStateException("No BluetoothAdapter found");
        }
        return new BluetoothAdapter(n_getDefaultAsync());
    }

    public boolean isAdvertisementOffloadSupported() {
        return n_isAdvertisementOffloadSupported(n_Pointer);
    }

    public boolean isCentralRoleSupported() {
        return n_isCentralRoleSupported(n_Pointer);
    }

    public boolean isClassicSupported() {
        return n_isClassicSupported(n_Pointer);
    }

    public boolean isExtendedAdvertisingSupported() {
        return n_isExtendedAdvertisingSupported(n_Pointer);
    }

    public boolean isLowEnergyCodedPhySupported() {
        return n_isLowEnergyCodedPhySupported(n_Pointer);
    }

    public boolean isLowEnergySupported() {
        return n_isLowEnergySupported(n_Pointer);
    }

    public boolean isLowEnergyUncoded2MPhySupported() {
        return n_isLowEnergyUncoded2MPhySupported(n_Pointer);
    }

    public boolean isPeripheralRoleSupported() {
        return n_isPeripheralRoleSupported(n_Pointer);
    }

    public int getMaxAdvertisementDataLength() {
        return n_getMaxAdvertisementDataLength(n_Pointer);
    }

    public long getBluetoothAddress() {
        return n_getBluetoothAddress(n_Pointer);
    }

    public Radio getRadioAsync() {
        return new Radio(n_getRadioAsync(n_Pointer));
    }

    public String toString() {
        return String.format("BluetoothAdapter(n_Pointer=%d)", n_Pointer);
    }

    @Override
    public void close() {
        n_releaseAdapter(n_Pointer);
    }
}
