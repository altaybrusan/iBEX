TEMPLATE = subdirs
include(./common/build/commonconfig.pri)

CONFIG += ordered
SUBDIRS += \
    launch \
    plugins \
    #tests
    tests



