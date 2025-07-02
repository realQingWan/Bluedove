package dev.qingwan.bluedove;

public class BluetoothSignalStrengthFilter extends AutoManageWrapper {
    public BluetoothSignalStrengthFilter(long pointer) {
        super(pointer);
    }

    private static native short n_getInRangeThresholdInDBm(long pointer);
    private static native void n_setInRangeThresholdInDBm(long pointer, short value);
    private static native short n_getOutOfRangeThresholdInDBm(long pointer);
    private static native void n_setOutOfRangeThresholdInDBm(long pointer, short value);
    private static native void n_setOutOfRangeTimeout(long pointer, long timeoutMillis);
    private static native long n_getOutOfRangeTimeout(long pointer);
    private static native void n_setSamplingInterval(long pointer, long timeoutMillis);
    private static native long n_getSamplingInterval(long pointer);

    public short getInRangeThresholdInDBm() {
        return n_getInRangeThresholdInDBm(n_Pointer);
    }

    public void setInRangeThresholdInDBm(short value) {
        if (value < -128 || value > 127) {
            throw new IllegalArgumentException("value must be between -128 and 127");
        }
        n_setInRangeThresholdInDBm(n_Pointer, value);
    }

    public short getOutOfRangeThresholdInDBm() {
        return n_getOutOfRangeThresholdInDBm(n_Pointer);
    }

    public void setOutOfRangeThresholdInDBm(short value) {
        if (value < -128 || value > 127) {
            throw new IllegalArgumentException("value must be between -128 and 127");
        }
        n_setOutOfRangeThresholdInDBm(n_Pointer, value);
    }

    public void setOutOfRangeTimeout(long timeoutMillis) {
        if (timeoutMillis < 1000) {
            throw new IllegalArgumentException("timeoutMillis must be >= 1000");
        }
        n_setOutOfRangeTimeout(n_Pointer, timeoutMillis);
    }

    public long getOutOfRangeTimeout() {
        return n_getOutOfRangeTimeout(n_Pointer);
    }

    public void setSamplingInterval(long intervalMillis) {
        if (intervalMillis < 0) {
            throw new IllegalArgumentException("intervalMillis must be >= 0");
        }
        n_setSamplingInterval(n_Pointer, intervalMillis);
    }

    public long getSamplingInterval() {
        return n_getSamplingInterval(n_Pointer);
    }

    public String toString() {
        return String.format("BluetoothSignalStrengthFilter(n_Pointer=%d)", n_Pointer);
    }

}
