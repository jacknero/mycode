#! /usr/bin/env bash
if [[ $1 == "--hwut-info" ]]; then
    echo "Flags"
    exit
fi
echo "../flags osterix"
../flags osterix

echo "../flags osterix -hamburg"
../flags osterix -hamburg

