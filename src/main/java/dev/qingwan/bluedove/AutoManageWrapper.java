package dev.qingwan.bluedove;

public abstract class AutoManageWrapper implements AutoCloseable {
    public final long n_Pointer;

    public AutoManageWrapper(long pointer) {
        this.n_Pointer = pointer;
        if (n_Pointer == 0) {
            throw new RuntimeException(new NullPointerException());
        }
    }

    public void close() throws Exception {
        Native.n_releaseObject(n_Pointer);
    }
}
