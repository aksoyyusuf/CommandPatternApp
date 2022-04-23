add_executable(Application
	main.cpp	
)

target_link_libraries(Application 
	PRIVATE
	MessageStore
)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/CLI)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/UserDB)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/MessageStore)
