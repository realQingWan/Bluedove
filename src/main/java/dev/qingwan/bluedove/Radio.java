package dev.qingwan.bluedove;

public class Radio extends AutoManageWrapper {

    Radio(long pointer) {
        super(pointer);
    }

    public String toString() {
        return String.format("Radio(n_Pointer=%d)", n_Pointer);
    }

}
