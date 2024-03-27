add_executable(tls_server tls_server.c)

find_package(OpenSSL)

target_link_libraries(tls_server PRIVATE OpenSSL::SSL OpenSSL::Crypto) 


FILE(COPY run_tls_server.sh DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

set(KEYS_AND_CERTS
  ${CMAKE_CURRENT_BINARY_DIR}/keys_and_certs/localhost.key
  ${CMAKE_CURRENT_BINARY_DIR}/keys_and_certs/localhost.crt
  ${CMAKE_CURRENT_BINARY_DIR}/keys_and_certs/ca.crt
  )

add_custom_target(SSL_FILES
DEPENDS
${KEYS_AND_CERTS}
)

add_custom_command(OUTPUT
  ${KEYS_AND_CERTS}
COMMAND ${CMAKE_COMMAND} -E copy_directory
${CMAKE_CURRENT_SOURCE_DIR}/keys_and_certs ${CMAKE_CURRENT_BINARY_DIR}/keys_and_certs
  DEPENDS keys_and_certs/localhost.key
  keys_and_certs/localhost.crt
  keys_and_certs/ca.crt
  )


FILE(COPY run_tls_server.sh DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
FILE(COPY socat_test.sh DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_test(NAME SslSocat
  COMMAND ./socat_test.sh
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
  )

