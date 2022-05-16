function(nodeeditor_add_example)

	set(options)
	set(oneValueArgs EXENAME)
	set(multiValueArgs LIBRARIES SOURCES HEADERS)

	cmake_parse_arguments(VARS "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

	if(VARS_UNPARSED_ARGUMENTS)
		message(FATAL_ERROR "Unknown keywords given to nodeeditor_add_example(): \"${CPP_UNPARSED_ARGUMENTS}\"")
		return()
	endif()

	if(NOT VARS_EXENAME)
		message(FATAL_ERROR "Keyword 'EXENAME' is required for nodeeditor_add_example()")
		return()
	endif()

	if(NOT VARS_SOURCES)
		message(FATAL_ERROR "Keyword 'SOURCES' is required for nodeeditor_add_example()")
		return()
	endif()

	if(NOT VARS_HEADERS)
		message(FATAL_ERROR "Keyword 'HEADERS' is required for nodeeditor_add_example()")
		return()
	endif()


	if(NODE_EDITOR_BUILD_SHARED_LIBS)
		set(taskName ${VARS_EXENAME}Shared)
		message(STATUS "Building ${taskName}")
		add_executable(${taskName} WIN32 ${VARS_SOURCES} ${VARS_HEADERS})
		target_include_directories(${taskName} PRIVATE ${CMAKE_SOURCE_DIR}/lib/node_common)
		target_link_libraries(${taskName} PRIVATE NodeEditorSharedLib)

		# Installation of Qt DLLs on Windows
		node_editor_deployqt(${taskName})

		# Installation
		install(TARGETS ${taskName} RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

	endif(NODE_EDITOR_BUILD_SHARED_LIBS)

	if(NODE_EDITOR_BUILD_STATIC_LIBS)
		set(taskName ${exempleBaseName}Static)
		message(STATUS "Building ${taskName}")

		add_executable(${taskName} WIN32 ${VARS_SOURCES} ${VARS_HEADERS})
		target_include_directories(${taskName} PRIVATE ${CMAKE_SOURCE_DIR}/lib/node_common)
		target_link_libraries(${taskName} PRIVATE NodeEditorLib)

		# Installation of Qt DLLs on Windows
		node_editor_deployqt(${taskName})

		# Installation
		install(TARGETS ${taskName} RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

	endif(NODE_EDITOR_BUILD_STATIC_LIBS)
endfunction(nodeeditor_add_example)
