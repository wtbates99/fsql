read -p "Enter your filename: " filename
mkdir -p build
gcc main.c -o build/main.o && ./build/main.o $"filename"
