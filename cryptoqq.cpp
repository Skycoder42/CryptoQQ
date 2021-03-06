#include <cryptoqq.h>
using namespace CryptoPP;
using namespace CryptoQQ;

ByteArray::ByteArray(const QByteArray &other) :
	QByteArray{other}
{}

ByteArray::ByteArray(QByteArray &&other) noexcept :
	QByteArray{std::move(other)}
{}

ByteArray &ByteArray::operator=(const QByteArray &other)
{
	QByteArray::operator=(other);
	return *this;
}

ByteArray &ByteArray::operator=(QByteArray &&other) noexcept
{
	QByteArray::operator=(std::move(other));
	return *this;
}

ByteArray::ByteArray(const char *data, int size) :
	QByteArray{data, size}
{}

ByteArray::ByteArray(int size, char c) :
	QByteArray{size, c}
{}

ByteArray::ByteArray(int size, Qt::Initialization i) :
	QByteArray{size, i}
{}

ByteArray::ByteArray(const byte *data, size_t size) :
	QByteArray{reinterpret_cast<const char*>(data), static_cast<int>(size)}
{}

ByteArray::ByteArray(size_t size, CryptoPP::byte b) :
	QByteArray{static_cast<int>(size), static_cast<char>(b)}
{}

ByteArray::ByteArray(size_t size, Qt::Initialization i) :
	QByteArray{static_cast<int>(size), i}
{}

ByteArray ByteArray::fromRawByteData(const byte *data, size_t size)
{
	return QByteArray::fromRawData(reinterpret_cast<const char*>(data), static_cast<int>(size));
}

byte *ByteArray::byteData()
{
	return reinterpret_cast<byte*>(QByteArray::data());
}

const byte *ByteArray::byteData() const
{
	return reinterpret_cast<const byte*>(QByteArray::data());
}

const byte *ByteArray::constByteData() const
{
	return reinterpret_cast<const byte*>(QByteArray::constData());
}

size_t ByteArray::byteSize() const
{
	return static_cast<size_t>(QByteArray::size());
}

ByteArray::operator byte *()
{
	return reinterpret_cast<byte*>(QByteArray::data());
}

ByteArray::operator const byte *() const
{
	return reinterpret_cast<const byte*>(QByteArray::data());
}
