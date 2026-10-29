if [ ! -e "./main.cpp" ]; then
    cp ./helpers/template.cpp ./main.cpp
fi

if [ ! -e "./input.txt" ]; then
    touch input.txt
fi
g++ main.cpp -DINPUT_FILE -Wformat=0 -std=c++20 -fsanitize=address,undefined,leak -o main && ./main
rm main