#ifndef BANDPASSFILTER_GLOBAL_H
#define BANDPASSFILTER_GLOBAL_H
#include <QtCore/qglobal.h>

#if defined(BANDPASSFILTER_LIBRARY)
#  define BANDPASSFILTERSHARED_EXPORT Q_DECL_EXPORT
#else
#  define BANDPASSFILTERSHARED_EXPORT Q_DECL_IMPORT
#endif
#endif // BANDPASSFILTER_GLOBAL_H