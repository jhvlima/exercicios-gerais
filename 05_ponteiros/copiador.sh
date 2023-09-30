#!/bin/bash

# Source directory and file
source_dir="pont_01"
source_file="correcao.sh"
include_dir="Includes"

# Loop through destination directories
for dest_dir in pont_{03..13}; do
  # Check if the destination directory exists
  if [ -d "$dest_dir" ]; then
    # Create the Respostas/JoaoHenrique directory within the destination directory
    mkdir -p "$dest_dir/Respostas/JoaoHenrique"

    # Copy the contents of the Include directory to Respostas/JoaoHenrique
    find "$dest_dir/$include_dir" -type f -exec cp {} "$dest_dir/Respostas/JoaoHenrique/" \;

    # Rename the copied files in the Respostas/JoaoHenrique directory from .h to .c
    for file in "$dest_dir/Respostas/JoaoHenrique"/*.h; do
      file_deconversao="$file.tmp"
      cp "$file" "$file_deconversao"
      mv "$file_deconversao" "${file%.h}.c"
    done

    # Create a main.c file in the Respostas/JoaoHenrique directory
    echo "// Your C code goes here" > "$dest_dir/Respostas/JoaoHenrique/main.c"

    # Copy the source file to the destination directory
    cp "$source_dir/$source_file" "$dest_dir/"

    echo "Copied '$source_file' and '$include_dir' contents to '$dest_dir/'"
  else
    echo "Destination directory '$dest_dir/' does not exist. Skipping."
  fi
done
