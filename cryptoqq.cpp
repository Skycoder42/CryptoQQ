#include <cryptoqq.h>
using namespace CryptoPP;
using namespace CryptoQQ;

ByteArray::ByteArray(const byte *data, size_t size) :
	QByteArray{reinterpret_cast<const char*>(data), static_cast<int>(size)}
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
