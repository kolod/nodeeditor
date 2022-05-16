set(libBasename NodeEditor)
set(libIncludeSubdir nede_common)

if(NODE_EDITOR_BUILD_SHARED_LIBS)
	set(libsh_name ${libBasename}SharedLib)
	set(libsh_name_decorated ${libsh_name}${NODE_EDITOR_LIBNAME_ADDITION})
	set(${libBasename}_SHARED_LIBRARY ${libsh_name_decorated}  CACHE STRING "name of static library for ${libBasename}" FORCE)
	message( STATUS "-- Building ${libsh_name}" )
endif(NODE_EDITOR_BUILD_SHARED_LIBS)

if(NODE_EDITOR_BUILD_STATIC_LIBS)
	set(lib_name ${libBasename}Lib)
	set(lib_name_decorated ${lib_name}${NODE_EDITOR_LIBNAME_ADDITION})
	set(${libBasename}_STATIC_LIBRARY ${lib_name_decorated}  CACHE STRING "name of static library for ${libBasename}" FORCE)
	message( STATUS "-- Building ${lib_name}" )
endif(NODE_EDITOR_BUILD_STATIC_LIBS)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

# Set up source files
set(SOURCES
	${CMAKE_CURRENT_LIST_DIR}/Node.cpp
	${CMAKE_CURRENT_LIST_DIR}/NodeConnectionInteraction.cpp
	${CMAKE_CURRENT_LIST_DIR}/NodeDataModel.cpp
	${CMAKE_CURRENT_LIST_DIR}/NodeGeometry.cpp
	${CMAKE_CURRENT_LIST_DIR}/NodeGraphicsObject.cpp
	${CMAKE_CURRENT_LIST_DIR}/NodePainter.cpp
	${CMAKE_CURRENT_LIST_DIR}/NodeState.cpp
	${CMAKE_CURRENT_LIST_DIR}/NodeStyle.cpp
	${CMAKE_CURRENT_LIST_DIR}/Properties.cpp
	${CMAKE_CURRENT_LIST_DIR}/StyleCollection.cpp
	${CMAKE_CURRENT_LIST_DIR}/Connection.cpp
	${CMAKE_CURRENT_LIST_DIR}/ConnectionBlurEffect.cpp
	${CMAKE_CURRENT_LIST_DIR}/ConnectionGeometry.cpp
	${CMAKE_CURRENT_LIST_DIR}/ConnectionGraphicsObject.cpp
	${CMAKE_CURRENT_LIST_DIR}/ConnectionPainter.cpp
	${CMAKE_CURRENT_LIST_DIR}/ConnectionState.cpp
	${CMAKE_CURRENT_LIST_DIR}/ConnectionStyle.cpp
	${CMAKE_CURRENT_LIST_DIR}/DataModelRegistry.cpp
	${CMAKE_CURRENT_LIST_DIR}/FlowScene.cpp
	${CMAKE_CURRENT_LIST_DIR}/FlowView.cpp
	${CMAKE_CURRENT_LIST_DIR}/FlowViewStyle.cpp
)

set(HEADERS
	$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/FlowViewStyle.h>
	$<INSTALL_INTERFACE:FlowViewStyle.h>
	$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/memory.h>
	$<INSTALL_INTERFACE:memory.h>
	$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/Node.h>
	$<INSTALL_INTERFACE:Node.h>
	$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/NodeConnectionInteraction.h>
	$<INSTALL_INTERFACE:NodeConnectionInteraction.h>
	$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/NodeData.h>
	$<INSTALL_INTERFACE:NodeData.h>
	$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/NodeDataModel.h>
	$<INSTALL_INTERFACE:NodeDataModel.h>
	$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/nodeeditor_imexport.h>
	$<INSTALL_INTERFACE:nodeeditor_imexport.h>
	$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/NodeGeometry.h>
	$<INSTALL_INTERFACE:NodeGeometry.h>
	$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/NodeGraphicsObject.h>
	$<INSTALL_INTERFACE:NodeGraphicsObject.h>
	$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/NodePainter.h>
	$<INSTALL_INTERFACE:NodePainter.h>
	$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/NodePainterDelegate.h>
	$<INSTALL_INTERFACE:NodePainterDelegate.h>
	$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/NodeState.h>
	$<INSTALL_INTERFACE:NodeState.h>
	$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/NodeStyle.h>
	$<INSTALL_INTERFACE:NodeStyle.h>
	$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/OperatingSystem.h>
	$<INSTALL_INTERFACE:OperatingSystem.h>
	$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/PortType.h>
	$<INSTALL_INTERFACE:PortType.h>
	$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/Properties.h>
	$<INSTALL_INTERFACE:Properties.h>
	$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/QStringStdHash.h>
	$<INSTALL_INTERFACE:QStringStdHash.h>
	$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/QUuidStdHash.h>
	$<INSTALL_INTERFACE:QUuidStdHash.h>
	$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/Serializable.h>
	$<INSTALL_INTERFACE:Serializable.h>
	$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/Style.h>
	$<INSTALL_INTERFACE:Style.h>
	$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/StyleCollection.h>
	$<INSTALL_INTERFACE:StyleCollection.h>
	$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/TypeConverter.h>
	$<INSTALL_INTERFACE:TypeConverter.h>
	$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/Connection.h>
	$<INSTALL_INTERFACE:Connection.h>
	$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/ConnectionBlurEffect.h>
	$<INSTALL_INTERFACE:ConnectionBlurEffect.h>
	$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/ConnectionGeometry.h>
	$<INSTALL_INTERFACE:ConnectionGeometry.h>
	$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/ConnectionGraphicsObject.h>
	$<INSTALL_INTERFACE:ConnectionGraphicsObject.h>
	$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/ConnectionPainter.h>
	$<INSTALL_INTERFACE:ConnectionPainter.h>
	$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/ConnectionState.h>
	$<INSTALL_INTERFACE:ConnectionState.h>
	$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/ConnectionStyle.h>
	$<INSTALL_INTERFACE:ConnectionStyle.h>
	$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/DataModelRegistry.h>
	$<INSTALL_INTERFACE:DataModelRegistry.h>
	$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/FlowScene.h>
	$<INSTALL_INTERFACE:FlowScene.h>
	$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/FlowView.h>
	$<INSTALL_INTERFACE:FlowView.h>
	$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/Export.h>
	$<INSTALL_INTERFACE:Export.h>

	$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/FlowScene>
	$<INSTALL_INTERFACE:FlowScene>
	$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/FlowView>
	$<INSTALL_INTERFACE:FlowView>
	$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/FlowViewStyle>
	$<INSTALL_INTERFACE:FlowViewStyle>
	$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/Node>
	$<INSTALL_INTERFACE:Node>
	$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/NodeData>
	$<INSTALL_INTERFACE:NodeData>
	$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/NodeDataModel>
	$<INSTALL_INTERFACE:NodeDataModel>
	$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/NodeGeometry>
	$<INSTALL_INTERFACE:NodeGeometry>
	$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/NodePainterDelegate>
	$<INSTALL_INTERFACE:NodePainterDelegate>
	$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/NodeState>
	$<INSTALL_INTERFACE:NodeState>
	$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/NodeStyle>
	$<INSTALL_INTERFACE:NodeStyle>
	$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/StyleCollection>
	$<INSTALL_INTERFACE:StyleCollection>
	$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/TypeConverter>
	$<INSTALL_INTERFACE:TypeConverter>
	$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/Connection>
	$<INSTALL_INTERFACE:Connection>
	$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/ConnectionStyle>
	$<INSTALL_INTERFACE:ConnectionStyle>
	$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/DataModelRegistry>
	$<INSTALL_INTERFACE:DataModelRegistry>
)

qt_add_resources(SOURCES ${CMAKE_CURRENT_LIST_DIR}/resources/resources.qrc)

include(CMakePackageConfigHelpers)


if(NODE_EDITOR_BUILD_SHARED_LIBS)
	add_library(${libsh_name} SHARED ${SOURCES} ${HEADERS})

	set_target_properties(${libsh_name}
		PROPERTIES
			VERSION "${PROJECT_VERSION}"
			OUTPUT_NAME "${libsh_name_decorated}"
			WINDOWS_EXPORT_ALL_SYMBOLS "ON"
	)

	target_compile_definitions(${libsh_name}
		PUBLIC
			NODE_EDITOR_SHARED
		PRIVATE
			NODE_EDITOR_EXPORTS
			QT_NO_KEYWORDS
	)

	target_include_directories(${libsh_name} PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/../>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
	)

	target_link_libraries(${libsh_name} PUBLIC
		Qt${QT_VERSION_MAJOR}::Core
		Qt${QT_VERSION_MAJOR}::Widgets
		Qt${QT_VERSION_MAJOR}::Gui
		Qt${QT_VERSION_MAJOR}::OpenGL
	)

	write_basic_package_version_file(
		${CMAKE_CURRENT_BINARY_DIR}/${libsh_name}Version.cmake
		VERSION ${PROJECT_VERSION}
		COMPATIBILITY AnyNewerVersion
	)

	if(MINGW)
		# COMPILER-SETTINGS FOR MINGW
		target_compile_options(${libsh_name} PUBLIC -fexceptions)
	elseif(MSVC)
		# COMPILER-SETTINGS FOR MS VISUAL C++
		target_compile_options(${libsh_name} PUBLIC /EHsc)
		target_compile_definitions(${libsh_name} PUBLIC NOMINMAX)
	endif()
endif()


if(NODE_EDITOR_BUILD_STATIC_LIBS)
	add_library(${lib_name} STATIC ${SOURCES} ${HEADERS})

	set_target_properties(${libsh_name}
		PROPERTIES
			VERSION "${PROJECT_VERSION}"
			OUTPUT_NAME "${libsh_name_decorated}"
			WINDOWS_EXPORT_ALL_SYMBOLS "ON"
	)

	target_compile_definitions(${libsh_name}
		PRIVATE
			QT_NO_KEYWORDS
	)

	target_include_directories(${lib_name} PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/../>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
	)

	target_link_libraries(${libsh_name} PUBLIC
		Qt${QT_VERSION_MAJOR}::Core
		Qt${QT_VERSION_MAJOR}::Widgets
		Qt${QT_VERSION_MAJOR}::Gui
		Qt${QT_VERSION_MAJOR}::OpenGL
	)

	write_basic_package_version_file(
		${CMAKE_CURRENT_BINARY_DIR}/${libsh_name}Version.cmake
		VERSION ${PROJECT_VERSION}
		COMPATIBILITY AnyNewerVersion
	)

	if(MINGW)
	  	# COMPILER-SETTINGS FOR MINGW
	  	target_compile_options(${lib_name} PUBLIC -fexceptions)
	elseif(MSVC)
	  	# COMPILER-SETTINGS FOR MS VISUAL C++
	  	target_compile_options(${lib_name} PUBLIC /EHsc)
	  	target_compile_definitions(${lib_name} PUBLIC NOMINMAX)
	endif()
endif()



# Installation
if(NODE_EDITOR_BUILD_SHARED_LIBS)
	install(TARGETS ${libsh_name} EXPORT ${libsh_name}_TARGETS
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${libIncludeSubdir}
    )

	set(NODE_EDITOR_CURRENT_TARGET_FILENAME "${libsh_name}Targets.cmake")
	configure_file(LibTarget.cmake.in "${CMAKE_CURRENT_BINARY_DIR}/${libsh_name}Config.cmake" @ONLY)
    install(EXPORT ${libsh_name}_TARGETS
        FILE "${NODE_EDITOR_CURRENT_TARGET_FILENAME}"
        DESTINATION lib/cmake
    )

	install(FILES "${CMAKE_CURRENT_BINARY_DIR}/${libsh_name}Version.cmake" DESTINATION lib/cmake)
    install(FILES "${CMAKE_CURRENT_BINARY_DIR}/${libsh_name}Config.cmake"  DESTINATION lib/cmake)
endif(NODE_EDITOR_BUILD_SHARED_LIBS)


if(NODE_EDITOR_BUILD_STATIC_LIBS)
	install(TARGETS ${lib_name} EXPORT ${lib_name}_TARGETS
		RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
		ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
		LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
		INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${libIncludeSubdir}
	)

	set(NODE_EDITOR_CURRENT_TARGET_FILENAME "${lib_name}Targets.cmake")
	configure_file(LibTarget.cmake.in "${CMAKE_CURRENT_BINARY_DIR}/${lib_name}Config.cmake" @ONLY)
    install(EXPORT ${lib_name}_TARGETS
        FILE "${NODE_EDITOR_CURRENT_TARGET_FILENAME}"
        DESTINATION lib/cmake
    )

	install(FILES "${CMAKE_CURRENT_BINARY_DIR}/${lib_name}Version.cmake" DESTINATION lib/cmake)
    install(FILES "${CMAKE_CURRENT_BINARY_DIR}/${lib_name}Config.cmake"  DESTINATION lib/cmake)
endif(NODE_EDITOR_BUILD_STATIC_LIBS)


install(
	FILES ${HEADERS}
	DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${libIncludeSubdir}
	COMPONENT Headers
)

configure_file(${PROJECT_SOURCE_DIR}/readme.txt.in ${CMAKE_CURRENT_BINARY_DIR}/${lib_name}_Readme.txt @ONLY)
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/${lib_name}_Readme.txt" DESTINATION doc/NodeEditor )
install(FILES "${PROJECT_SOURCE_DIR}/LICENSE" DESTINATION doc/NodeEditor RENAME "${lib_name}_LICENSE.txt")
