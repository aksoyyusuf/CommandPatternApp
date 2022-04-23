add_library(UserDB
    "${CMAKE_CURRENT_SOURCE_DIR}/src/UserDB.cpp"
)

target_include_directories(UserDB
    PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
	"${CMAKE_SOURCE_DIR}/src/MessageStore/include"
	PRIVATE
	"${CMAKE_CURRENT_SOURCE_DIR}/src"    
)
