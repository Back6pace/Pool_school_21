#!/bin/sh
parent=$(git rev-parse --show-toplevel)
cd $(git rev-parse --show-toplevel)
echo "Введите путь до файла формата folder/file"
read way
fullway="$parent/$way"

if ! [ -f "$fullway" ]; then
    echo "Ошибка"
    exit 1
fi 

read -p "Введите строку которую нужно поменять: " search
cheack=$(sed -n /$search/p $way)
if [ -z $cheack ]
then
    echo "Строка отсутствует"
    while [ -z $search ];
    do
        echo "Вы не ввели строку"
        read -p "Введите строку которую нужно поменять: " search
    done
fi

read -p "Введите строку на которую нужно поменять: " replace
if  [ $replace = "" ]; then
echo "Введен пустой символ"
exit 1
fi


sed -i "" "s/$search/$replace/" $way

cd $(git rev-parse --show-toplevel)
size=$(stat -f %z $way) 
log_date=$(date +"%Y-%d-%m %H:%M")
sha=$(shasum -a 256 $way | awk '{print $1}')
echo ""$way" - "$size" - "$log_date" - "$sha" - "sha256"">>src/files.log