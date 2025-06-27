package dev.qingwan.bluedove.advertisement;

import java.util.HashMap;
import java.util.concurrent.atomic.AtomicInteger;

public class BluetoothLEAdvertisementWatcher implements AutoCloseable {
    private final long n_Pointer;

    private BluetoothLEAdvertisementWatcher(long pointer) {
        this.n_Pointer = pointer;
        if (n_Pointer == 0) {
            throw new RuntimeException(new NullPointerException());
        }
    }
    public BluetoothLEAdvertisementWatcher() {
        this(n_newWatcher());
    }

    private static native long n_newWatcher();
    private static native void n_releaseWatcher(long pointer);
    private static native int n_getStatus(long pointer);
    private static native long n_listenReceived(long pointer, BluetoothLEAdvertisementReceivedListener listener);

    public BluetoothLEAdvertisementWatcherStatus getStatus() {
        int value = n_getStatus(n_Pointer);
        return BluetoothLEAdvertisementWatcherStatus.fromValue(value);
    }

    public long listenReceived(BluetoothLEAdvertisementReceivedListener listener) {
        return n_listenReceived(n_Pointer, listener);
    }

    public String toString() {
        return String.format("BluetoothLEAdvertisementWatcher(n_Pointer=%d)", n_Pointer);
    }

    @Override
    public void close() throws Exception {
        n_releaseWatcher(n_Pointer);
    }

    public abstract static class BluetoothLEAdvertisementReceivedListener {

        public static final class BluetoothLEAdvertisementReceivedEventArgs {

        }
    }
}
