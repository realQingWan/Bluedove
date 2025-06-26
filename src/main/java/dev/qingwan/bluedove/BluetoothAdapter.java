package dev.qingwan.bluedove;

public class BluetoothAdapter implements AutoCloseable {
    private final long n_Pointer;
    private BluetoothAdapter(long pointer) {
        this.n_Pointer = pointer;
    }
    private static native long n_getDefaultAsync();
    private static native void n_releaseAdapter(long pointer);
    private static native String n_getDeviceId(long pointer);

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
    public String toString() {
        return String.format("BluetoothAdapter(n_Pointer=%d)", n_Pointer);
    }

    @Override
    public void close() {
        n_releaseAdapter(n_Pointer);
    }
}
