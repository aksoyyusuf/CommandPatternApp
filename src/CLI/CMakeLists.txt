add_library(CLI
    "${CMAKE_CURRENT_SOURCE_DIR}/src/CLI.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/SendMsgCmd.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/CreateUserCmd.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/ReceiveMsgCmd.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/QuitCmd.cpp"
)

target_include_directories(CLI
    PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
	"${CMAKE_SOURCE_DIR}/src/MessageStore/include"
	PRIVATE
	"${CMAKE_CURRENT_SOURCE_DIR}/src"    
)
