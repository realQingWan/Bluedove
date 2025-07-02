package dev.qingwan.bluedove.winrt;

import dev.qingwan.bluedove.AutoManageWrapper;
import org.jetbrains.annotations.Nullable;

import java.util.function.Function;

public class AsyncOperation<T> extends AutoManageWrapper {
    private final Function<Long, T> initializer;
    public AsyncOperation(long pointer, Function<Long, T> initializer) {
        super(pointer);
        this.initializer = initializer;
    }

    private static native long n_get(long pointer);


    @Nullable
    public T get() {
        long result = n_get(n_Pointer);
        if (result == 0) {
            return null;
        }
        return initializer.apply(result);
    }

}
