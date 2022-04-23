cmake_minimum_required(VERSION 3.1 FATAL_ERROR)

project(Application)

set(CMAKE_MODULE_PATH "${CMAKE_BINARY_DIR}" "${CMAKE_MODULE_PATH}")
set(CMAKE_PREFIX_PATH "${CMAKE_BINARY_DIR}" "${CMAKE_PREFIX_PATH}")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")

option(BUILD_TESTS "Build tests" OFF)
option(GENERATE_DOCS "Generate documentations" OFF)
option(GENERATE_GRAPH "Generate dependency graph" OFF)

enable_testing()

add_subdirectory(src)

if (BUILD_TESTS)
    add_subdirectory(test)
endif ()

# C++ Standard can be enforced
#set(CMAKE_CXX_STANDARD 17)

if (GENERATE_DOCS)
	find_package(Doxygen)
	if (DOXYGEN_FOUND)
		message ("Doxygen found!")
		set (DOXYGEN_IN ${PROJECT_SOURCE_DIR}/build/CMakeDoxyfile.in)
		set (DOXYGEN_OUT ${PROJECT_SOURCE_DIR}/build/CMakeDoxyfile.out)
		set (DOXYGEN_INPUT ${PROJECT_SOURCE_DIR}/src/MessageStore/include)
		set (DOXYGEN_PROJECT_NAME "MessageStore Application")
		set (DOXYGEN_MARKDOWN_SUPPORT YES)
		set (DOXYGEN_SHOW_USED_FILES NO)
		configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
		add_custom_target(docs ALL
			COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
			WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
			COMMENT "*****Generating Documentation*****")
	else (DOXYGEN_FOUND)
		message ("Doxygen not found!")
	endif (DOXYGEN_FOUND)
endif ()


if(GENERATE_GRAPH)
	message ("Generating graph option selected!")
	configure_file(${CMAKE_SOURCE_DIR}/cmake/modules/CMakeGraphVizOptions.cmake
				   ${CMAKE_CURRENT_BINARY_DIR}/CMakeGraphVizOptions.cmake COPYONLY)

	add_custom_target(graphviz ALL
				COMMAND ${CMAKE_COMMAND} "--graphviz=dependencyGraph.dot" .
				COMMAND dot -Tpng dependencyGraph.dot -o dependencyGraph.png
				WORKING_DIRECTORY "${CMAKE_BINARY_DIR}"
			)	
endif()
