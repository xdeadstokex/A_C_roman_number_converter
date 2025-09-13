script_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd $script_dir

gcc -c roman_number_converter.c -o roman_number_converter.o -I./libs -I./
gcc -o main core_base.c roman_number_converter.o ./libs/texts.o -I./libs -I./
