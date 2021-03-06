#ifndef QIODEVICESINK_H
#define QIODEVICESINK_H

#include <QIODevice>
#include <QByteArray>
#include <QBuffer>

#include <cryptopp/filters.h>

namespace CryptoQQ {

class CRYPTO_QQ_EXPORT QIODeviceSink : public CryptoPP::Sink, public CryptoPP::NotCopyable
{
public:
#if CRYPTOPP_VERSION >= 600
	using byte = CryptoPP::byte;
#endif

	class Err : public CryptoPP::Exception
	{
	public:
		Err(const QString &s);
	};

	QIODeviceSink();
	QIODeviceSink(QIODevice *device);

	QIODevice *device() const;

	void IsolatedInitialize(const CryptoPP::NameValuePairs &parameters) override;
	size_t Put2(const byte *inString, size_t length, int messageEnd, bool blocking) override;
	bool IsolatedFlush(bool hardFlush, bool blocking) override;

protected:
	static const char * const DeviceParameter;

private:
	QIODevice *_device;
};

class CRYPTO_QQ_EXPORT QByteArraySink : public QIODeviceSink
{
public:
	QByteArraySink();
	QByteArraySink(QByteArray &sink);

	const QByteArray &buffer() const;

private:
	QBuffer _buffer;
};

}

#endif // QIODEVICESINK_H
