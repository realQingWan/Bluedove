package dev.qingwan.bluedove.winrt;

import dev.qingwan.bluedove.AutoManageWrapper;

public class GUID extends AutoManageWrapper {
    public GUID(long pointer) {
        super(pointer);
    }

    private static native boolean n_equals(long n_this, long n_other);

    @Override
    public boolean equals(Object obj) {
        if (obj instanceof GUID) return n_equals(n_Pointer, ((GUID)obj).n_Pointer);
        return super.equals(obj);
    }
}
