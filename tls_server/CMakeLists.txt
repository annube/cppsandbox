add_executable(tls_server tls_server.c)

find_package(OpenSSL)

target_link_libraries(tls_server PRIVATE OpenSSL::SSL OpenSSL::Crypto) 


FILE(COPY run_tls_server.sh DESTINATION ${CMAKE_CURRENT_BINARY_DIR})


add_custom_command(TARGET tls_server POST_BUILD
COMMAND ${CMAKE_COMMAND} -E copy_directory
${CMAKE_CURRENT_SOURCE_DIR}/keys_and_certs $<TARGET_FILE_DIR:tls_server>/keys_and_certs )

FILE(COPY run_tls_server.sh DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
FILE(COPY run_tls_server.sh DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
