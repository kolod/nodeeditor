find_package(Catch2 2.3.0 REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Test REQUIRED)

message( STATUS "Building Tests" )

set(SOURCES
	TestDragging.cpp
	TestDataModelRegistry.cpp
	TestFlowScene.cpp
	TestNodeGraphicsObject.cpp
	test_main.cpp
)

set(HEADERS
	ApplicationSetup.h
	Stringify.h
	StubNodeDataModel.h
)


if(NODE_EDITOR_BUILD_SHARED_LIBS)
	add_executable(test_nodes_shared WIN32 ${SOURCES} ${HEADERS})
	target_include_directories(test_nodes_shared PRIVATE ../lib/node_common)
	target_link_libraries(test_nodes_shared PRIVATE NodeEditorSharedLib Catch2::Catch2 Qt::Test)
	add_test(
		NAME test_nodes_shared
		COMMAND $<TARGET_FILE:test_nodes_shared> $<$<BOOL:${NODE_EDITOR_BUILD_FORCE_TEST_COLOR}>:--use-colour=yes>
	)

	# Installation of Qt DLLs on Windows
	node_editor_deployqt(test_nodes_shared)

	# Installation
	install(TARGETS test_nodes_shared RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

endif(NODE_EDITOR_BUILD_SHARED_LIBS)



if(NODE_EDITOR_BUILD_STATIC_LIBS)
	add_executable(test_nodes_static WIN32 ${SOURCES} ${HEADERS})
	target_include_directories(test_nodes_static PRIVATE ../lib/node_common)
	target_link_libraries(test_nodes_static PRIVATE NodeEditorLib Catch2::Catch2 Qt::Test)
	add_test(
		NAME test_nodes_static
		COMMAND $<TARGET_FILE:test_nodes_static> $<$<BOOL:${NODE_EDITOR_BUILD_FORCE_TEST_COLOR}>:--use-colour=yes>
	)

	# Installation of Qt DLLs on Windows
	node_editor_deployqt(test_nodes_static)

endif(NODE_EDITOR_BUILD_STATIC_LIBS)
