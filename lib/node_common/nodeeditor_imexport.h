#pragma once

#include <QtCore/QtGlobal>
#  ifdef NODEEDITOR_LIB_IN_DLL
#    ifndef NODEEDITOR_LIB_EXPORT
#      ifdef NODEEDITOR_LIB_EXPORT_LIBRARY
		  /* We are building this library */
#        define JKQTCOMMON_LIB_EXPORT Q_DECL_EXPORT
#      else
		  /* We are using this library */
#        define JKQTCOMMON_LIB_EXPORT Q_DECL_IMPORT
#      endif
#    endif
#  else
#    ifndef JKQTCOMMON_LIB_EXPORT
#      define JKQTCOMMON_LIB_EXPORT
#    endif
#  endif
