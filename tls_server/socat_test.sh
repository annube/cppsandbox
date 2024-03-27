#!/bin/bash

./run_tls_server.sh &
server_pid=$!
trap "kill $server_pid" SIGTERM SIGINT TERM
socat openssl:localhost:4433,cafile=./keys_and_certs/ca.crt CREATE:result.log

kill $server_pid


