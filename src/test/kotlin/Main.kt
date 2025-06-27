import dev.qingwan.bluedove.BluetoothAdapter
import dev.qingwan.bluedove.advertisement.BluetoothLEAdvertisementWatcher
import java.io.File

fun main(args: Array<String>) {
    System.load(File("./BleNative/cmake-build-debug/BleNative.dll").absolutePath)
    val watcher = BluetoothLEAdvertisementWatcher()
    println(watcher)
    println(watcher.status)
    watcher.close()
}