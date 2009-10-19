#! /usr/bin/env bash
if [[ $1 == "--hwut-info" ]]; then
    echo "Input File Parsing: Macro Expansion (Dollar Brackets)"
    exit
fi
echo "../expand --directory ../"
../expand --directory ../

