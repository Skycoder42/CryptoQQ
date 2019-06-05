#ifndef CRYPTOQQ_H
#define CRYPTOQQ_H

#include <cryptopp/secblock.h>

#include <QByteArray>
#include <QDebug>
#include <QDataStream>

namespace CryptoQQ {

class CRYPTO_QQ_EXPORT ByteArray : public QByteArray
{
public:
	ByteArray() = default;
	ByteArray(const ByteArray &other) = default;
	ByteArray(ByteArray &&other) noexcept = default;
	ByteArray &operator=(const ByteArray &other) = default;
	ByteArray &operator=(ByteArray &&other) noexcept = default;
	ByteArray(const CryptoPP::byte *data, size_t size);

	static ByteArray fromRawByteData(const CryptoPP::byte *data, size_t size);

	template <typename... TArgs>
	ByteArray(TArgs&&... args) :
		QByteArray{std::forward<TArgs>(args)...}
	{}

	CryptoPP::byte *byteData();
	const CryptoPP::byte *byteData() const;
	const CryptoPP::byte *constByteData() const;
	size_t byteSize() const;

	operator CryptoPP::byte*();
	operator const CryptoPP::byte*() const;
};

template <class T, class A = CryptoPP::AllocatorWithCleanup<T>>
QDataStream &operator<<(QDataStream &stream, const CryptoPP::SecBlock<T, A> &data) {
	stream.writeBytes(reinterpret_cast<const char*>(data.BytePtr()),
					  static_cast<quint32>(data.SizeInBytes()));
	return stream;
}

template <class T, class A = CryptoPP::AllocatorWithCleanup<T>>
QDataStream &operator>>(QDataStream &stream, CryptoPP::SecBlock<T, A> &data) {
	stream.startTransaction();
	char *buffer = nullptr;
	quint32 len = 0;
	stream.readBytes(buffer, len);
	if (len % sizeof (T) != 0)
		stream.abortTransaction();
	else {
		data.Assign(reinterpret_cast<T*>(buffer), len / sizeof(T));
		stream.commitTransaction();
	}
	delete[] buffer;
	return stream;
}

template <class T, class A = CryptoPP::AllocatorWithCleanup<T>>
QDebug operator<<(QDebug stream, const CryptoPP::SecBlock<T, A> &data) {
	QDebugStateSaver state{stream};
	stream.noquote() << ByteArray::fromRawByteData(data.BytePtr(), data.SizeInBytes()).toHex();
	return stream;
}

}

#endif // CRYPTOQQ_H
