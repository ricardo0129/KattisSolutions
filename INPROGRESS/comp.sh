var=$(ls -Art | find . -type f -name "*.cpp" | tail -n 1)
echo "compiling $var"
g++ -std=c++17 "$var"
