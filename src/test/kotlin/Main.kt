import dev.qingwan.bluedove.BluetoothAdapter
import dev.qingwan.bluedove.BluetoothLEDevice
import dev.qingwan.bluedove.BluetoothUuidHelper
import dev.qingwan.bluedove.Native
import dev.qingwan.bluedove.advertisement.BluetoothLEAdvertisementWatcher
import dev.qingwan.bluedove.advertisement.BluetoothLEAdvertisementWatcher.BluetoothLEAdvertisementReceivedListener
import dev.qingwan.bluedove.advertisement.BluetoothLEScanningMode
import dev.qingwan.bluedove.genericAttributeProfile.GattCommunicationStatus
import dev.qingwan.bluedove.helper.BufferHelper
import java.io.File
import java.util.UUID

fun main(args: Array<String>) {
    System.load(File("./BleNative/cmake-build-debug/BleNative.dll").absolutePath)
    /**
     * m_watcher = BluetoothLEAdvertisementWatcher();
     *
     *         // 设置信号强度筛选（可选）
     *         m_watcher.SignalStrengthFilter().InRangeThresholdInDBm(-70);
     *         m_watcher.SignalStrengthFilter().OutOfRangeThresholdInDBm(-75);
     *         m_watcher.SignalStrengthFilter().OutOfRangeTimeout(TimeSpan{ std::chrono::seconds(5) });
     *
     *         // 注册事件处理程序
     *         m_watcher.Received({ this, &BluetoothDeviceDiscoverer::OnAdvertisementReceived });
     *         m_watcher.Stopped({ this, &BluetoothDeviceDiscoverer::OnWatcherStopped });
     *         m_watcher.Start();
     */
    val found = mutableListOf<Long>()
    val watcher = BluetoothLEAdvertisementWatcher()
    println("Default scanMode: ${watcher.scanningMode}")
    watcher.scanningMode = BluetoothLEScanningMode.Active
    println("New scanMode: ${watcher.scanningMode}")
    val signalFilter = watcher.signalStrengthFilter
    println(signalFilter)
    val token = watcher.listenReceived { args ->
        if (args.bluetoothAddress in found) {
            return@listenReceived
        }
        found.add(args.bluetoothAddress)
        val device = BluetoothLEDevice.fromBluetoothAddressAsync(args.bluetoothAddress).get()
        if (device != null) {
            println("found")
            println("localName: ${args.advertisement.localName}")
            println("ptr: ${device.n_Pointer}")
            println("name: ${device.name}")
            println("deviceId: ${device.deviceId}")
            println("getting gattServices")
            val gattServices = device.gattServicesAsync.get()!!
            println("status ${gattServices.status}")
            if (gattServices.status != GattCommunicationStatus.Success) {
                return@listenReceived
            }
            println("gattServicesSize: ${gattServices.services.size}")
            device.listenNameChanged { device ->
                println("nameChanged: ${device.name}")
            }
            gattServices.services.forEach {
                if (it.uuid == BluetoothUuidHelper.fromShortId(0x1800)) {
                    println("0x1800")
                    println("getting Characteristics")
                    val characteristics = it.characteristicsAsync.get()!!
                    println("status ${characteristics.status}")
                    if (characteristics.status != GattCommunicationStatus.Success) {
                        return@listenReceived
                    }
                    characteristics.services.forEach {
                        if (it.uuid == BluetoothUuidHelper.fromShortId(0x2A00)) {
                            println("0x2A00")
                            val value = it.readValueAsync().get()!!
                            val buffer = value.value
                            println(BufferHelper.readString(buffer))
                        }
                    }
                }
            }

        }
    }
    /**
     * winrt::fire_and_forget GetCompleteDeviceName(BluetoothLEDevice device) {
     *         try {
     *             // 读取Generic Access服务中的设备名称特征(0x2A00)
     *             auto services = co_await device.GetGattServicesAsync();
     *             for (auto&& service : services) {
     *                 if (service.Uuid() == BluetoothUuidHelper::FromShortId(0x1800)) { // Generic Access
     *                     auto characteristics = co_await service.GetCharacteristicsAsync();
     *                     for (auto&& charac : characteristics) {
     *                         if (charac.Uuid() == BluetoothUuidHelper::FromShortId(0x2A00)) { // Device Name
     *                             auto value = co_await charac.ReadValueAsync();
     *                             auto reader = DataReader::FromBuffer(value.Value());
     *                             std::wstring name(reader.UnconsumedBufferLength() / sizeof(wchar_t), L'\0');
     *                             reader.ReadBytes(name);
     *                             std::wcout << L"Complete GATT Name: " << name << std::endl;
     *                         }
     *                     }
     *                 }
     *             }
     *         } catch (const winrt::hresult_error& ex) {
     *             std::wcerr << L"Failed to read GATT name: " << ex.message().c_str() << std::endl;
     *         }
     *     }
     */
    watcher.start()
    while (true) {

    }
}