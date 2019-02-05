HEADERS += \
	$$PWD/qiodevicesource.h \
	$$PWD/qiodevicesink.h

SOURCES += \
	$$PWD/qiodevicesource.cpp \
	$$PWD/qiodevicesink.cpp

INCLUDEPATH += $$PWD

QDEP_PACKAGE_EXPORTS += CRYPTO_QQ_EXPORT
!qdep_build: DEFINES += "CRYPTO_QQ_EXPORT="
