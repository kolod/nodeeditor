nodeeditor_add_example(
	EXENAME Images
	SOURCES
		${CMAKE_CURRENT_LIST_DIR}/ImageShowModel.cpp
		${CMAKE_CURRENT_LIST_DIR}/ImageLoaderModel.cpp
		${CMAKE_CURRENT_LIST_DIR}/main.cpp
	HEADERS
		${CMAKE_CURRENT_LIST_DIR}/PixmapData.h
		${CMAKE_CURRENT_LIST_DIR}/ImageLoaderModel.h
		${CMAKE_CURRENT_LIST_DIR}/ImageShowModel.h
)
