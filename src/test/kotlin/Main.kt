import dev.qingwan.bluedove.BluetoothAdapter
import java.io.File

fun main(args: Array<String>) {
    System.load(File("./BleNative/cmake-build-debug/BleNative.dll").absolutePath)
    val adapter = BluetoothAdapter.getDefaultAsync()
    println(adapter)
    println(adapter.deviceId)
    adapter.close()
}