plugins {
    id("com.android.application")
}

android {
    namespace = "dev.sporeport.cellstage"
    compileSdk = 34
    lint {
        baseline = file("lint-baseline.xml")
    }

    defaultConfig {
        applicationId = "dev.sporeport.cellstage"
        minSdk = 26
        targetSdk = 34
        versionCode = 1
        versionName = "0.1.0"
        ndk {
            abiFilters += listOf("arm64-v8a")
        }
    }

    buildTypes {
        debug {
            applicationIdSuffix = ".dev"
        }
    }

    packaging {
        jniLibs {
            keepDebugSymbols += "**/*.so"
            useLegacyPackaging = true
        }
    }

    compileOptions {
        sourceCompatibility = JavaVersion.VERSION_17
        targetCompatibility = JavaVersion.VERSION_17
    }

    externalNativeBuild {
        cmake {
            path = file("src/main/cpp/CMakeLists.txt")
        }
    }

}
