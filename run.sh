g++ preparesyndata.cpp -std=c++11
./a.out > inp.csv
g++ createfeature.cpp -std=c++11
./a.out < inp.csv > inp2.csv
python main.py 