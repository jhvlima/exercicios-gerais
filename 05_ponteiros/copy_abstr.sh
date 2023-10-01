#!/bin/bash
# o arquivo correcao.sh deve estar no diretorio da atividade 01
# source_dir deve ser o radical do diretorio atividade

# Define source and destination directories and filenames
source_dir="pont_01"
source_file="correcao.sh"
include_dir="Includes"
output_dir="Respostas/JoaoHenrique"
main_file="main.c"
dest_dir="pont_"

# Define the range of destination directories
start_dest=3
end_dest=13

# Loop through destination directories
for ((indice = start_dest; indice <= end_dest; indice++)); do
  # Define the full paths for source and destination
  source_path="$source_dir/$source_file"
  dest_path="dest_dir${indice}/$output_dir"

  # Check if the destination directory exists
  if [ -d "$dest_path" ]; then
    # Create the Respostas/JoaoHenrique directory within the destination directory
    mkdir -p "$dest_path"

    # Copy the contents of the Include directory to Respostas/JoaoHenrique
    find "$indice/$include_dir" -type f -exec cp {} "$dest_path/" \;

    # Rename the copied files in the Respostas/JoaoHenrique directory from .h to .c
    for file in "$dest_path"/*.h; do
      file_deconversao="$file.tmp"
      cp "$file" "$file_deconversao"
      mv "$file_deconversao" "${file%.h}.c"
    done

    # Create a main.c file in the Respostas/JoaoHenrique directory
    echo "// Your C code goes here" > "$dest_path/$main_file"

    # Copy the source file to the destination directory
    cp "$source_path" "dest_dir${indice}/"

    echo "Copied '$source_file' and '$include_dir' contents to 'dest_dir${indice}/'"
  else
    echo "Destination directory 'dest_dir${indice}/$output_dir' does not exist. Skipping."
  fi
done
