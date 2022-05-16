nodeeditor_add_example(
	EXENAME Example
	SOURCES
		${CMAKE_CURRENT_LIST_DIR}/TextDisplayDataModel.cpp
		${CMAKE_CURRENT_LIST_DIR}/TextSourceDataModel.cpp
		${CMAKE_CURRENT_LIST_DIR}/main.cpp
	HEADERS
		${CMAKE_CURRENT_LIST_DIR}/TextData.h
		${CMAKE_CURRENT_LIST_DIR}/TextDisplayDataModel.h
		${CMAKE_CURRENT_LIST_DIR}/TextSourceDataModel.h
)
