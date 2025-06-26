import java.nio.file.Files

plugins {
    java
    kotlin("jvm") version "2.0.0"
}

group = "dev.qingwan"
version = "1.0-SNAPSHOT"

repositories {
    mavenCentral()
}

dependencies {
    testImplementation(kotlin("test"))
}


tasks.withType<JavaCompile>().configureEach {
    options.compilerArgs.addAll(listOf("-h", file("$projectDir/BleNative/jni_generated").absolutePath))
}

task("generateJniHeaders") {
    val javaHome = System.getProperty("java.home")
    val javacPath = "$javaHome/bin/javac"
    val nativeIncludeDir = file("$projectDir/BleNative/jni_generated")
    val nativeClasses = listOf(
        "dev.qingwan.bluedove.BluetoothAdapter",
    )

    doLast {
        nativeClasses.forEach {
            println("Generating $it")
            val nativeSource = "$projectDir/src/main/java/${it.replace(".", "/")}.java"
            val nativeClass = "$projectDir/src/main/java/${it.replace(".", "/")}.class"

            exec {
                commandLine(javacPath, "-h", nativeIncludeDir, nativeSource)
            }
            File(nativeClass).delete()
        }
    }

}

tasks.test {
    useJUnitPlatform()
}
kotlin {
    jvmToolchain(17)
}