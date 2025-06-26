import dev.qingwan.bluedove.BluetoothAdapter
import java.io.File

fun main(args: Array<String>) {
    System.load(File("./BleNative/cmake-build-debug/BleNative.dll").absolutePath)
    val adapter = BluetoothAdapter.getDefaultAsync()
    println(adapter)
    println(adapter.deviceId)
    println(adapter.isAdvertisementOffloadSupported)
    println(adapter.isClassicSupported)
    println(adapter.isLowEnergySupported)
    println(adapter.isCentralRoleSupported)
    println(adapter.isLowEnergyCodedPhySupported)
    println(adapter.isExtendedAdvertisingSupported)
    println(adapter.isLowEnergyUncoded2MPhySupported)
    println(adapter.isPeripheralRoleSupported)
    println(adapter.maxAdvertisementDataLength)
    println(adapter.bluetoothAddress)
    println(adapter.radioAsync)
    adapter.close()
}