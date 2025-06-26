package dev.qingwan.bluedove;

public class Radio {
    private final long n_Pointer;
    public Radio(long pointer) {
        this.n_Pointer = pointer;
    }

    public String toString() {
        return String.format("Radio(n_Pointer=%d)", n_Pointer);
    }

}
