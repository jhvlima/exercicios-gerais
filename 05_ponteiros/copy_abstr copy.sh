#!/bin/bash
# Como usar
# Coloque este copiador.sh junto com o correcao.sh no diretório principal da atividade 
# exemplo: 05_ponteiros/
#              correcao.sh
#              copiador.sh
#              pont_01/
#                 Casos/
#                 Includes/
#                 Gabarito-obj/
#              pont_02/
#                               
# Agora só usar o comando ./copiador.sh no diretório 05_ponteiros
# ATENÇÃO: se voce adicionar -o no final do comando ele vai sobrescrever sua main.c e seus .c das bibliotecas,
# só use isso nos exercícios que você ainda não fez.
# Para alterar o alcance do seu uso  dependendo da quantidade de exercicos modifique a variável start_dest e end_dest

# Default behavior is to not overwrite existing files
overwrite=false

# Process command-line options
while getopts ":o" opt; do
  case $opt in
    o)
      overwrite=true
      ;;
    \?)
      echo "Opção inválida: -$OPTARG" >&2
      exit 1
      ;;
  esac
done

# Define source and destination directories and filenames
dest_dir="pont_" # <coloca o radical da atividade 
source_dir="${dest_dir}01" # < da onde o correcao.sh vai ser copiado
source_file="correcao.sh"
include_dir="Includes"
output_dir="Respostas/JoaoHenrique" # <coloca seu nome aqui
main_file="main.c"

# Define the range of destination directories (quais exercícios vão receber o Respostas/nome)
start_dest=05
end_dest=13 # <coloca a quantidade de atividades

# Loop through destination directories
for ((indice = start_dest; indice <= end_dest; indice++)); do
  # Define the full paths for source and destination
  source_path="$source_dir/$source_file"
  dest_path="${dest_dir}$(printf "%02d" $indice)"  # Concatenate dest_dir and indice Padded with leading zeros

  # Check if the destination directory exists
  if [ -d "$dest_path" ]; then
    # Create the Respostas/JoaoHenrique directory within the destination directory (Respostas/nome)
    mkdir -p "$dest_path/$output_dir"

    # Copy the contents of the Include directory to Respostas/JoaoHenrique (.h do include)
    if [ "$overwrite" = true ]; then
      find "$dest_path/$include_dir" -type f -exec cp {} "$dest_path/$output_dir" \;
    else
      find "$dest_path/$include_dir" -type f -exec cp -n {} "$dest_path/$output_dir" \;
    fi

    # Rename the copied files in the Respostas/JoaoHenrique directory from .h to .c
    for file in "$dest_path/$output_dir"/*.h; do
      file_deconversao="$file.tmp"
      cp "$file" "$file_deconversao"
      mv "$file_deconversao" "${file%.h}.c"
    done

    # Create a main.c file in the Respostas/JoaoHenrique directory
    echo "// Cole a main do pdf aqui" > "$dest_path/$output_dir/$main_file"

    # Copy the source file to the destination directory (correcao.sh)
    cp "$source_path" "$dest_path/"

    echo "Foram copiados '$source_file' e os arquivos do '$include_dir' para '$dest_path/$output_dir'"
  else
    echo "O diretório '$dest_path/$output_dir' não existe. Pulando sua cópia..."
  fi
done
