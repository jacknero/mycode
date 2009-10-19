#! /usr/bin/env bash
if [[ $1 == "--hwut-info" ]]; then
    echo "Filter Prefixes"
    exit
fi
echo "../filter --nice"
../filter --nice

