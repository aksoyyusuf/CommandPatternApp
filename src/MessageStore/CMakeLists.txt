add_library(MessageStore
    "${CMAKE_CURRENT_SOURCE_DIR}/src/MessageStore.cpp"
)

target_link_libraries(MessageStore 
	PRIVATE
	CLI
	UserDB
)

target_include_directories(MessageStore
    PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
	PRIVATE
	"${CMAKE_CURRENT_SOURCE_DIR}/src"
	"${CMAKE_SOURCE_DIR}/src/CLI/include"
)
