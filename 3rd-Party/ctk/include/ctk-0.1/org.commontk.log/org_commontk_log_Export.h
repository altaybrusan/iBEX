

// .NAME __org_commontk_log_Export - manage Windows system differences
// .SECTION Description
// The __org_commontk_log_Export captures some system differences between Unix
// and Windows operating systems. 

#ifndef __org_commontk_log_Export_h
#define __org_commontk_log_Export_h

#include "ctkCompilerDetections_p.h"

#include <QtGlobal>

#if defined(Q_OS_WIN) || defined(Q_OS_SYMBIAN)
#  if defined(org_commontk_log_EXPORTS)
#    define org_commontk_log_EXPORT Q_DECL_EXPORT
#  else
#    define org_commontk_log_EXPORT Q_DECL_IMPORT
#  endif
#endif

#if !defined(org_commontk_log_EXPORT)
//#  if defined(CTK_SHARED)
#    define org_commontk_log_EXPORT Q_DECL_EXPORT
//#  else
//#    define org_commontk_log_EXPORT
//#  endif
#endif

#endif

