#!/bin/bash
# o arquivo correcao.sh deve estar no diretorio da atividade 01
# source_dir deve ser o radical do diretorio atividade

# Define source and destination directories and filenames
dest_dir="pont_" #<coloca o  radical da atividade 
source_dir="${dest_dir}1" #< da onde o correcao.sh vai ser copiado
source_file="correcao.sh"
include_dir="Includes"
output_dir="Respostas/JoaoHenrique" #<coloca seu nome aqui
main_file="main.c"

# Define the range of destination directories (quais exercicios vao receber o Respostas/nome)
start_dest=01
end_dest=13 #<coloca a quantidade de atividades

# Loop through destination directories
for ((indice = start_dest; indice <= end_dest; indice++)); do
  # Define the full paths for source and destination
  source_path="$source_dir/$source_file"
  dest_path="dest_dir${indice}"

  # Check if the destination directory exists
  if [ -d "$dest_path" ]; then
    # Create the Respostas/JoaoHenrique directory within the destination directory (Respostas/nome)
    mkdir -p "$dest_path/$output_dir"

    # Copy the contents of the Include directory to Respostas/JoaoHenrique (.h do include)
    find "$dest_path/$include_dir" -type f -exec cp {} "$dest_path/$output_dir" \;

    # Rename the copied files in the Respostas/JoaoHenrique directory from .h to .c
    for file in "$dest_path"/*.h; do
      file_deconversao="$file.tmp"
      cp "$file" "$file_deconversao"
      mv "$file_deconversao" "${file%.h}.c"
    done

    # Create a main.c file in the Respostas/JoaoHenrique directory
    echo "// Cole a main do pdf aqui" > "$dest_path/$main_file"

    # Copy the source file to the destination directory (correcao.sh)
    cp "$source_path" "dest_dir${indice}/"

    echo "Foram copiados '$source_file' e os arquivos do '$include_dir' para 'dest_dir${indice}/'"
  else
    echo "O diretorio 'dest_dir${indice}/$output_dir' nao existe. Pulando sua copia..."
  fi
done
