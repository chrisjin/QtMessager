QT       += coregui
QT       += xml
QT       += network
HEADERS += \
    v_phone.h \
    v_smsmanager.h \
    SmsStruct.h \
    v_xmlpaser.h \
    v_connectsocket.h \
    v_phonegui.h \
    v_listwidget.h \
    v_messagelistwidget.h \
    v_personmanager.h \
    v_textedit.h \
    v_mailboxlistwidget.h \
    v_personlistwidget.h \
    v_configwidget.h \
    v_tipwidget.h \
    v_splashdialog.h

SOURCES += \
    v_phone.cpp \
    main.cpp \
    v_smsmanager.cpp \
    v_xmlpaser.cpp \
    v_connectsocket.cpp \
    v_phonegui.cpp \
    v_listwidget.cpp \
    v_messagelistwidget.cpp \
    v_personmanager.cpp \
    v_textedit.cpp \
    v_mailboxlistwidget.cpp \
    v_personlistwidget.cpp \
    v_configwidget.cpp \
    v_tipwidget.cpp \
    v_splashdialog.cpp

OTHER_FILES += \
    tip.html \
    sms.xml \
    person.xml \
    key.txt \
    config \
    backgroundimage
