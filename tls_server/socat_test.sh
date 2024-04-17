#!/bin/bash

./tls_server ./keys_and_certs/localhost.key ./keys_and_certs/localhost.crt &
server_pid=$!
echo "server pid: $server_pid"
trap "kill $server_pid" SIGTERM SIGINT TERM
socat openssl:localhost:4433,cafile=./keys_and_certs/ca.crt STDOUT | tee result.log > /dev/null

echo "killing pid $server_pid"
kill $server_pid


