# CryptoQQ
Qt-Extensions to the [CryptoPP](https://www.cryptopp.com/) library

## Features
Currently provides the following special classes:

- **QIODeviceSource:** A `CryptoPP::Source` to work with `QIODevice`
- **QByteArraySource:** A `CryptoPP::Source` to work with `QByteArray`
- **QIODeviceSink:** A `CryptoPP::Sink` to work with `QIODevice`
- **QByteArraySink:** A `CryptoPP::Sink` to work with `QByteArray`

**Note:** CryptoPP itself is NOT included in the package. You will have to install it seperately and add it to the
project that uses CryptoQQ. Because of that reason, this package is only available as qpmx source package and not as compiled one.

## Installation
The package is providet as qpm package, [`de.skycoder42.cryptoqq`](https://www.qpm.io/packages/de.skycoder42.cryptoqq/index.html). To install it, use one of the methods below.

You will have to install [CryptoPP](https://www.cryptopp.com/) and add the library to your project. In case your working on unix/linux and want to use the CryptoPP provided by your distro, you can use `pkgconfig`:

```pro
CONFIG += link_pkgconfig
PKGCONFIG += libcrypto++ #or however it is called for your distro
```

### Via qpmx
[qpmx](https://github.com/Skycoder42/qpmx) is a frontend for qpm (and other tools) with additional features, and is the preferred way to install packages. To use it:

1. Install qpmx (See [GitHub - Installation](https://github.com/Skycoder42/qpmx#installation))
2. Install qpm (See [GitHub - Installing](https://github.com/Cutehacks/qpm/blob/master/README.md#installing), for **windows** see below)
3. In your projects root directory, run `qpmx install de.skycoder42.cryptoqq`

### Via qpm

1. Install qpm (See [GitHub - Installing](https://github.com/Cutehacks/qpm/blob/master/README.md#installing), for **windows** see below)
2. In your projects root directory, run `qpm install de.skycoder42.cryptoqq`
3. Include qpm to your project by adding `include(vendor/vendor.pri)` to your `.pro` file

Check their [GitHub - Usage for App Developers](https://github.com/Cutehacks/qpm/blob/master/README.md#usage-for-app-developers) to learn more about qpm.

### Important for Windows users:
QPM Version *0.10.0* (the one you can download on the website) is currently broken on windows! It's already fixed in master, but not released yet. Until a newer versions gets released, you can download the latest dev build from here:

- https://storage.googleapis.com/www.qpm.io/download/latest/windows_amd64/qpm.exe
- https://storage.googleapis.com/www.qpm.io/download/latest/windows_386/qpm.exe