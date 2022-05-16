#pragma once

/*! \def JKQTCOMMON_LIB_EXPORT
    \ingroup tools

    This define allows to export functions and classes from the jkqtcommon-library when building a dynamic/shared library.
    Usage is as follows:
    \code
        #include "jkqtcommon/jkqtcommon_imexport.h"

        class JKQTCOMMON_LIB_EXPORT exportedClassName {
           ...
        };

        JKQTCOMMON_LIB_EXPORT void exportedFunctionName();
    \endcode

    These macros append the appropriate \c Q_DECL_EXPORT and \c Q_DECL_IMPORT
    to the function/class body and thus tell windows compilers to export these sysmbols from
    the shared library, or import them from a shared library.

    Note that these attributes are only necessary on windows systems!

    These macros are controlled by two other macros:
      - \c JKQTCOMMON_LIB_IN_DLL declares that the application should link against a shared version of
                                 JKQTCommon, i.e. \c JKQTCommonSharedLib_XYZ .
                                 This needs to be defined while compiling the library and while compiling
                                 any application linking against  \c JKQTCommonSharedLib_XYZ.
      - \c JKQTCOMMON_LIB_EXPORT_LIBRARY is only defined while compiling JKQTCommon into \c JKQTCommonSharedLib_XYZ
                                 and ensures thet the symbols are exported. If it is not defined (e.g. while
                                 compiling an application), the symbols are imported
    .

 */

/*! \def JKQTCOMMON_LIB_IN_DLL
    \ingroup tools
    \brief declares that the application should link against a shared version of
           JKQTCommon, i.e. \c JKQTCommonSharedLib_XYZ .
           This needs to be defined while compiling the library and while compiling
           any application linking against  \c JKQTCommonSharedLib_XYZ.
*/

/*! \def JKQTCOMMON_LIB_EXPORT_LIBRARY
    \ingroup tools
    \brief is only defined while compiling JKQTCommon into \c JKQTCommonSharedLib_XYZ
           and ensures thet the symbols are exported. If it is not defined (e.g. while
           compiling an application), the symbols are imported
*/

#include <QtCore/QtGlobal>
#  ifdef NODE_EDITOR_SHARED
#    ifndef NODE_EDITOR_PUBLIC
#      ifdef NODE_EDITOR_EXPORTS
          /* We are building this library */
#        define NODE_EDITOR_PUBLIC Q_DECL_EXPORT
#      else
          /* We are using this library */
#        define NODE_EDITOR_PUBLIC Q_DECL_IMPORT
#      endif
#    endif
#  else
#    ifndef NODE_EDITOR_PUBLIC
#      define NODE_EDITOR_PUBLIC
#    endif
#  endif
