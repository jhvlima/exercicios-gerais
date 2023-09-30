#!/bin/bash

# Source directory and file
source_dir="pont_01"
source_file="correcao.sh"
include_dir="Includes"

# Loop through destination directories
for dest_dir in pont_{03..13}; do
  # Check if the destination directory exists
  if [ -d "$dest_dir" ]; then

    # Delete the Include directory in JoaoHenrique
    rm -rf "$dest_dir/Respostas"

    echo Apaguei "$dest_dir/Respostas"
    fi
    done