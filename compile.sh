script_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd $script_dir

gcc -o main core_base.c ./libs/texts.o -I./libs
