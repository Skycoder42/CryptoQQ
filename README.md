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
The package is provided via qdep, as `Skycoder42/CryptoQQ`. To use it simply:

1. Install and enable qdep (See [qdep - Installing](https://github.com/Skycoder42/qdep#installation))
2. Add the following to your pro file:
```qmake
QDEP_DEPENDS += Skycoder42/CryptoQQ
!load(qdep):error("Failed to load qdep feature! Run 'qdep.py prfgen --qmake $$QMAKE_QMAKE' to create it.")
```

You will have to install [CryptoPP](https://www.cryptopp.com/) and add the library to your project. In case your working on unix/linux and want to use the CryptoPP provided by your distro, you can use `pkgconfig`:

```pro
CONFIG += link_pkgconfig
PKGCONFIG += libcrypto++ #or however it is called for your distro
```