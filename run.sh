g++ main.cpp -DINPUT_FILE -Wformat=0 -std=c++20 -fsanitize=address,undefined,leak -o main && ./main
rm main