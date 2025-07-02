package dev.qingwan.bluedove.advertisement;

import dev.qingwan.bluedove.AutoManageWrapper;
import dev.qingwan.bluedove.BaseListener;
import dev.qingwan.bluedove.BluetoothSignalStrengthFilter;
import dev.qingwan.bluedove.Native;

import java.util.HashMap;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.function.Consumer;

public class BluetoothLEAdvertisementWatcher extends AutoManageWrapper {

    private BluetoothLEAdvertisementWatcher(long pointer) {
        super(pointer);
    }

    public BluetoothLEAdvertisementWatcher() {
        this(n_newWatcher());
    }

    private static native long n_newWatcher();
    private static native int n_getStatus(long pointer);
    private static native long n_listenReceived(long pointer, BluetoothLEAdvertisementReceivedListener listener);
    private static native void n_start(long pointer);
    private static native void n_stop(long pointer);
    private static native void n_revokeReceivedListener(long pointer, long token);
    private static native void n_setScanningMode(long pointer, int mode);
    private static native int n_getScanningMode(long pointer);
    private static native long n_getSignalStrengthFilter(long pointer);

    public BluetoothLEAdvertisementWatcherStatus getStatus() {
        int value = n_getStatus(n_Pointer);
        return BluetoothLEAdvertisementWatcherStatus.fromValue(value);
    }

    public void start() {
        n_start(n_Pointer);
    }

    public void stop() {
        n_stop(n_Pointer);
    }

    public void setScanningMode(BluetoothLEScanningMode mode) {
        n_setScanningMode(n_Pointer, mode.value);
    }
    public BluetoothLEScanningMode getScanningMode() {
        return BluetoothLEScanningMode.fromValue(n_getScanningMode(n_Pointer));
    }

    public long listenReceived(BluetoothLEAdvertisementReceivedListener listener) {
        return n_listenReceived(n_Pointer, listener);
    }

    public long listenReceived(Consumer<BluetoothLEAdvertisementReceivedEventArgs> listener) {
        return listenReceived(new BluetoothLEAdvertisementReceivedListener() {
            @Override
            protected void onReceived(BluetoothLEAdvertisementReceivedEventArgs args) {
                listener.accept(args);
            }
        });
    }

    public void revokeReceivedListener(long token) {
        n_revokeReceivedListener(n_Pointer, token);
    }

    public BluetoothSignalStrengthFilter getSignalStrengthFilter() {
        return new BluetoothSignalStrengthFilter(n_getSignalStrengthFilter(n_Pointer));
    }

    public String toString() {
        return String.format("BluetoothLEAdvertisementWatcher(n_Pointer=%d)", n_Pointer);
    }

    public abstract static class BluetoothLEAdvertisementReceivedListener extends BaseListener {
        public void callback(long objPointer, long argsPointer) {
            System.out.printf("objPointer=%d, argsPointer=%d%n", objPointer, argsPointer);
            onReceived(new BluetoothLEAdvertisementReceivedEventArgs(argsPointer));
        }
        protected abstract void onReceived(BluetoothLEAdvertisementReceivedEventArgs args);
    }
    public static final class BluetoothLEAdvertisementReceivedEventArgs extends AutoManageWrapper{

        BluetoothLEAdvertisementReceivedEventArgs(long pointer) {
            super(pointer);
        }
        private static native long n_getBluetoothAddress(long pointer);
        private static native long n_getAdvertisement(long pointer);

        public long getBluetoothAddress() {
            return n_getBluetoothAddress(n_Pointer);
        }

        public BluetoothLEAdvertisement getAdvertisement() {
            return new BluetoothLEAdvertisement(n_getAdvertisement(n_Pointer));
        }
    }
}
